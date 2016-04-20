#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QWebView>
#include <QTimer>
#include <QProcess>
#include <QRegExp>
#include <QColor>
#include <QPalette>

#include <QtWebKit>

#include <cmath>

#include "selectalgwindow.h"

#define NumAlgo 500             //Define the number of algorithm

QRegExp rx("[^0-9.]");          //Regex keeps floating number.

QProcess *myProc;               //Declare myProc.

QStringList myAlgoName;         //Name of active algo.

int nEnabledAlg;                //Number of active algo.
int nExecutePatt;               //Number of patterns to execute.
int currentAlgo;                //Current algorithm.

double minPlen = 2;             //Min plen.
double maxPlen = 4096;          //Max plen.
double currentPlen;             //Current plen.

QVBoxLayout *layoutLegend;      //Declare new Layout.

QString parameters = "";        //Parameters to send in smart.
QString timeAlgo = "";          //String with result algo time.

QString Default500 = "500";
QString Default1Mb = "1";
QString DefaultTb300 = "300";

//Constructor.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    //ui->centralWidget->setFixedSize(500,500);

    ui->setupUi(this);

    ui->lineEdit->setText(Default500);
    ui->lineEdit_4->setText(Default1Mb);
    ui->lineEdit_5->setText(DefaultTb300);

    layoutLegend = new QVBoxLayout();

}

//Distructor.
MainWindow::~MainWindow() {
    delete ui;
}

//Menù option. Open selecAlgorithm Window.
void MainWindow::on_actionSelect_algorithms_triggered() {
    SelectAlgWindow openSelectAlgWin;
    openSelectAlgWin.setModal(true);
    openSelectAlgWin.exec();
}

//Menù option. Open about alert.
void MainWindow::on_actionAbout_SMART_GUI_triggered() {
    const QString help = " This is an help guide for using the tool\n\n "
                         "-pset N computes running times as the mean of N runs (default 500)\n "
                         "-tsize S set the upper bound dimension (in Mb) of the text used for experimental results (default 1Mb)\n "
                         "-plen L U  test only patterns with a length between L and U (included).\n "
                         "-text F  performs experimental results using text buffer F (mandatory unless you use the -simple parameter)\n "
                         "-short computes experimental results using short length patterns\n -occ prints the number of occurrences\n "
                         "-tb L set to L the upper bound for any wort case running time (in ms). The default value is 300 ms\n "
                         "-dif prints the number the best and the worst running time\n -std prints the standard deviations of the running times\n "
                         "-txt output results in txt tabular format\n -tex output results in latex tabular format\n "
                         "-simple P T executes a single run searching T (max 1000 chars) for occurrences of P (max 100 chars)\n \n "
                         "\n SMART by Faro Simone \n GUI by Alessandro Maggio\nSimone Di Mauro\nStefano Borzi.";

    QMessageBox::information(this,"About!",help);
}

//Load into array parameters the status of algo.
void getAlgoMain(char *ALGO_NAME[], int EXECUTE[]) {
    FILE *fp = fopen("source/algorithms.h", "r");
    char c; int i=0;
    while( (c=getc(fp)) != EOF )
        if(c=='#') {
            EXECUTE[i] = (getc(fp)-'0');
            getc(fp);getc(fp);
            ALGO_NAME[i] = (char*) malloc (sizeof(char)*20);
            int j = 0;
            while((c=getc(fp))!=' ') ALGO_NAME[i][j++]=c;
            ALGO_NAME[i][j]='\0';
            i++;
        }
    while(i<NumAlgo) ALGO_NAME[i++]=NULL;
    fclose(fp);
}

//Logarithm in base two.
double Log2( double n )  {
    return log( n ) / log( 2 );
}

//Execute this SLOT on ended process.
void MainWindow::processEnded(){
    qDebug() << " Ho Finito";
}

//Execute this SLOT everytime the SMART have an output.
//Update the chart e progress-bar.
void MainWindow::updateGUI(){

    QString javascriptCode = "";

    QString tmpOutput = myProc->readAllStandardOutput().replace('\b',"");
    ui->fakeTerminal->setText(tmpOutput  /* + ui->fakeTerminal->toPlainText() */ );

    if( tmpOutput.contains("[OK]") || tmpOutput.contains("[ERROR]") || tmpOutput.contains("[--]") || tmpOutput.contains("[OUT]") ){

        QStringList splittedOutput;
        splittedOutput << tmpOutput.split('\t');

        for(int j=0; j<splittedOutput.length(); j++){
            tmpOutput = splittedOutput[j].replace(" ","").replace('\t',"").replace('\n',"");

            if (currentAlgo == nEnabledAlg){

                //Create the javascript code.
                javascriptCode = "myLineChart.addData([" + timeAlgo.left(timeAlgo.length() - 1) + "], '" + QString::number(currentPlen) + "');";

                //Send js code.
                ui->webView->page()->mainFrame()->evaluateJavaScript(javascriptCode);

                //Support debug @Helias.
                qDebug() << "Aggiorna il grafico." ;
                qDebug() << "Valori: " << timeAlgo.left(timeAlgo.length() - 1);
                qDebug() << "Lenght: " << currentPlen;
                qDebug() << "Javascript code: " << javascriptCode;

                timeAlgo = "";
                currentPlen*=2;
                currentAlgo = 0;
            }

            if( tmpOutput.contains("ms") && tmpOutput.contains('.') ){

                //Support debug @Helias.
                qDebug() << "[" << currentAlgo+1 << "/" << nEnabledAlg << "] " << myAlgoName[currentAlgo] << " : " << tmpOutput.replace(rx,"");

                timeAlgo += tmpOutput.replace(rx,"") + ',';
                currentAlgo++;
            }else if ( tmpOutput.contains("[--]") || tmpOutput.contains("[ERROR]") || tmpOutput.contains("[OUT]") ){

                //Support debug @Helias.
                qDebug() << "[" << currentAlgo+1 << "/" << nEnabledAlg << "] " << myAlgoName[currentAlgo] << " : null";

                timeAlgo += "null,";
                currentAlgo++;
            }
        }
    }

}

//loadResource to create chart and load it into webView.
void MainWindow::loadChart(){

    //Inizialize and clear all supportVariables.
    nEnabledAlg = 0;
    myAlgoName.clear();

    while(!layoutLegend->isEmpty())
        delete layoutLegend->takeAt(0);


    int EXECUTE[NumAlgo];                                             //Declare EXECTUE array with the state of alrgorithm (0/1).
    char *ALGO_NAME[NumAlgo];                                         //Declare array ALGO_NAME with the name of all string matching algorithms

    QFile chartCode1File(":/chartFile/chart/chartPart1.html");        //Load part1 of htmlChart by res.
    QFile chartCode2File(":/chartFile/chart/chartPart2.html");        //Load part2 of htmlChart by res..
    QFile chartFile("chart.html");                                    //Load file of graph.

    QString chartCode1, chartCode2;
    QString r, g, b;

    QString datasets = "";

    //Read part1.
    if (chartCode1File.open(QIODevice::ReadOnly)) {
        QTextStream in(&chartCode1File);
        chartCode1 = in.readAll();
        chartCode1File.close();
    }

    //Read part2.
    if (chartCode2File.open(QIODevice::ReadOnly)) {
        QTextStream in(&chartCode2File);
        chartCode2 = in.readAll();
        chartCode2File.close();
    }

    //Load array.
    getAlgoMain(ALGO_NAME,EXECUTE);

    for(int i=0;i<NumAlgo;i++){
        if(ALGO_NAME[i] && EXECUTE[i]){

            myAlgoName << ALGO_NAME[i];
            nEnabledAlg++;

            //Create randomColor.
            r = QString::number( qrand() % ((255 + 1) - 1) + 1 );
            g = QString::number( qrand() % ((255 + 1) - 1) + 1 );
            b = QString::number( qrand() % ((255 + 1) - 1) + 1 );

            //Crete label with name of algo and color (legend).
            QLabel *label = new QLabel(QString::fromUtf8("• ") + myAlgoName[nEnabledAlg-1],0);
            label->setStyleSheet( "color: rgb(" + r + "," + g + "," + b+ ") ; font-weight: bold; font-size: 20px;" );
            layoutLegend->addWidget(label);

            //Create datasets.
            datasets +=  "{\n\tlabel: '" + myAlgoName[nEnabledAlg-1] + "',\n" +
                            "\tfillColor: 'rgba(" + r + "," + g + "," + b + ",0.2)'" + ",\n" +
                            "\tstrokeColor: 'rgba(" + r + "," + g + "," + b + ",1)'" + ",\n" +
                            "\tpointColor: 'rgba(" + r + "," + g + "," + b + ",1)'" + ",\n" +
                            "\tpointStrokeColor: '#fff'" + ",\n" +
                            "\tpointHighlightFill: '#fff'" + ",\n" +
                            "\tpointHighlightStroke: 'rgba(" + r + "," + g + "," + b + ",1)'" + ",\n},\n" ;
        }
    }


    //Apply layout of label with algoName in ui.
    ui->scrollAreaWidgetContents->setLayout(layoutLegend);

    QString chartCodeComplete = chartCode1 + datasets + chartCode2;

    //Write fileChart.
    if (chartFile.open(QFile::WriteOnly|QFile::Truncate)) {
        QTextStream stream(&chartFile);
        stream << chartCodeComplete;
    }


    //Copy Chart.js from resource in local.
    QFile::copy(":/chartFile/chart/Chart.js" , "Chart.js");

    QUrl url("chart.html");          //Url of chart.
    ui->webView->load(url);          //Insert chart in webView.

}

void MainWindow::on_checkBox_released() {

    if(ui->checkBox->isChecked()){
     ui->lineEdit_6->setEnabled(false);
     ui->lineEdit_7->setEnabled(false);
     ui->lineEdit_8->setEnabled(false);
     ui->lineEdit_9->setEnabled(false);
    }else{
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);
        ui->lineEdit_9->setEnabled(true);
    }

}

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1) {

    if(arg1 != ""){
       ui->lineEdit->setEnabled(false);
       ui->lineEdit_4->setEnabled(false);
       ui->lineEdit_5->setEnabled(false);
       ui->lineEdit_6->setEnabled(false);
       ui->lineEdit_7->setEnabled(false);
       ui->comboBox->setEnabled(false);
       ui->checkBox->setEnabled(false);
    }else if(arg1 == "" && ui->lineEdit_9->text() == ""){
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->checkBox->setEnabled(true);
    }

}

void MainWindow::on_lineEdit_9_textChanged(const QString &arg1) {

    if(arg1 != ""){
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_6->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->checkBox->setEnabled(false);
    }else if(arg1 == "" && ui->lineEdit_8->text() == ""){
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->checkBox->setEnabled(true);
    }

}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1) {

    if(arg1 != ""){
       ui->checkBox->setEnabled(false);
       ui->lineEdit_8->setEnabled(false);
       ui->lineEdit_9->setEnabled(false);
    }else if(arg1 == "" && ui->lineEdit_7->text() == ""){
        ui->checkBox->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);
        ui->lineEdit_9->setEnabled(true);
    }

}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1) {

    if(arg1 != ""){
       ui->checkBox->setEnabled(false);
       ui->lineEdit_8->setEnabled(false);
       ui->lineEdit_9->setEnabled(false);
    }else if(arg1 == "" && ui->lineEdit_6->text() == ""){
        ui->checkBox->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);
        ui->lineEdit_9->setEnabled(true);
    }

}

void MainWindow::on_pushButton_pressed() {

    if(ui->lineEdit->text() == "")
        ui->lineEdit->setText(Default500);

    if(ui->lineEdit_4->text() == "")
        ui->lineEdit_4->setText(Default1Mb);

    if(ui->lineEdit_5->text() == "")
        ui->lineEdit_5->setText(DefaultTb300);

}

void MainWindow::on_pushButton_released() {

    QString text2 = "";
    bool canI = false;

    if( ( (ui->lineEdit_8->text() != "") || (ui->lineEdit_9->text() != "") ) ){   //SIMPLE

        if(ui->checkBox_2->isChecked())
           text2 += " -occ ";

        if(ui->checkBox_3->isChecked())
           text2 += " -dif ";

        if(ui->checkBox_4->isChecked())
           text2 += " -std ";

        if(ui->checkBox_5->isChecked())
           text2 += " -txt ";

        if(ui->checkBox_6->isChecked())
           text2 += " -tex ";


        parameters = "-simple " +
                    ui->lineEdit_8->text() +
                    " " +
                    ui->lineEdit_9->text() +
                    text2;

        canI = true;

    }else if( ( (ui->lineEdit_6->text()!="") || (ui->lineEdit_7->text()!="") ) ){  //PLEN

        minPlen = ui->lineEdit_6->text().toDouble();
        maxPlen = ui->lineEdit_7->text().toDouble();

        if(ui->checkBox_2->isChecked())
           text2 += " -occ ";

        if(ui->checkBox_3->isChecked())
           text2 += " -dif ";

        if(ui->checkBox_4->isChecked())
           text2 += " -std ";

        if(ui->checkBox_5->isChecked())
           text2 += " -txt ";

        if(ui->checkBox_6->isChecked())
           text2 += " -tex ";


        parameters = "-text " +
                    ui->comboBox->currentText() +
                    " -pset "+
                    ui->lineEdit->text()+
                    " -tsize "+ui->lineEdit_4->text() +
                    " -tb " +
                    ui->lineEdit_5->text() +
                    " -plen " +
                    ui->lineEdit_6->text() +
                    " " +
                    ui->lineEdit_7->text() +
                    text2;

        canI = true;

    }else if(ui->checkBox->isChecked()){  //SHORT

        if(ui->checkBox_2->isChecked())
           text2 += " -occ ";

        if(ui->checkBox_3->isChecked())
           text2 += " -dif ";

        if(ui->checkBox_4->isChecked())
           text2 += " -std ";

        if(ui->checkBox_5->isChecked())
           text2 += " -txt ";

        if(ui->checkBox_6->isChecked())
           text2 += " -tex ";


        parameters = "-text " +
                    ui->comboBox->currentText() +
                    " -pset "+
                    ui->lineEdit->text()+
                    " -tsize " +
                    ui->lineEdit_4->text() +
                    " -tb " +
                    ui->lineEdit_5->text() +
                    " -short " +
                    text2;

        canI = true;

    }else{

        if(ui->checkBox_2->isChecked())
           text2 += " -occ ";

        if(ui->checkBox_3->isChecked())
           text2 += " -dif ";

        if(ui->checkBox_4->isChecked())
           text2 += " -std ";

        if(ui->checkBox_5->isChecked())
           text2 += " -txt ";

        if(ui->checkBox_6->isChecked())
           text2 += " -tex ";

        parameters = "-text " +
                    ui->comboBox->currentText() +
                    " -pset "+
                    ui->lineEdit->text()+
                    " -tsize " +
                    ui->lineEdit_4->text() +
                    " -tb " +
                    ui->lineEdit_5->text() +
                    text2;

        canI = true;

    }

    if (canI) {

        loadChart();

        QString execute = "./smart " + parameters;
        qDebug() << execute;

        //Support debug @Helias.
        qDebug() << "Numero di algoritmi attivi: " << nEnabledAlg;
        qDebug() << myAlgoName;

        nExecutePatt = (floor ( Log2(maxPlen))) - (ceil ( Log2(minPlen))) + 1;
        qDebug() << "Numero di esecuzioni totali: " << nExecutePatt;

        minPlen = pow(2, ceil ( Log2(minPlen) ) );
        maxPlen = pow(2, floor ( Log2(maxPlen) ) );

        qDebug() << "MinPlen: " << minPlen << "MaxPlen: " << maxPlen;

        currentPlen = minPlen;


        myProc = new QProcess(this);                                                    //Create process.
        connect(myProc, SIGNAL(readyReadStandardOutput()), this, SLOT(updateGUI()) );   //Connect SLOT updateGUI to SIGNAL output.
        connect(myProc, SIGNAL(finished(int)), this, SLOT(processEnded()) );            //Connect SLOT processEnded to SIGNAL finished.
        myProc->start(execute);                                                         //Start process.

    }

}
