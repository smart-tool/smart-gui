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

QRegExp rxFloat("[^0-9.]");     //Regex keeps floating number.

QProcess *myProc;               //Declare myProc.

QStringList myAlgoName;         //Name of active algo.
QString *algoOutput;            //List of all output for fake terminal.

int nEnabledAlg;                //Number of active algo.
int nExecutePatt;               //Number of patterns to execute.
int currentAlgo;                //Current algorithm.
int countPercent = 0;           //Percent of currente execute algorithm.

double minPlen = 2;             //Min plen.
double maxPlen = 4096;          //Max plen.
double currentPlen;             //Current plen.

QVBoxLayout *layoutLegend;      //Declare new Layout.

QString completeOutput = "";    //Output string goint to fake terminal.
QString parameters = "";        //Parameters to send in smart.
QString timeAlgo = "";          //String with result algo time.
QString expCode = "";           //String with code ex.

bool forcedStop = false;        //Bool true if click stop button.

QString Default500 = "500";
QString Default1Mb = "1";
QString DefaultTb300 = "300";

//Constructor.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    //ui->centralWidget->setFixedSize(500,500);

    ui->setupUi(this);

    ui->Pset_lineEdit->setText(Default500);
    ui->Tsize_lineEdit->setText(Default1Mb);
    ui->Tb_lineEdit->setText(DefaultTb300);

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

//Generate code experiment
void generateEXPCode(){
    int t = (int)time(NULL);
    expCode = "EXP" + QString::number(t);
}

QString MainWindow::createHeadEXP(){

    return  QString::fromLatin1("\n\n  -----------------------------------------------------------------------------") +
            QString::fromLatin1("\n  Experimental results on ") + ui->Text_comboBox->currentText() + QString::fromLatin1(": ") + expCode +
            QString::fromLatin1("\n  Searching for a set of ") + ui->Pset_lineEdit->text() + QString::fromLatin1(" patterns with length ") + QString::number(currentPlen) +
            QString::fromLatin1("\n  Testing ") + QString::number(nEnabledAlg) + QString::fromLatin1(" algorithms \n");

}

//Execute this SLOT on ended process.
void MainWindow::processEnded(){

    qDebug() << " Ho Finito";

    if(forcedStop)
        ui->fakeTerminal_textEdit->setText( ui->fakeTerminal_textEdit->toPlainText() +
                                            "\n\n  -----------------------------------------------------------------------------" +
                                            "\n  STOPPED BY USER " + expCode
                                            );
    else{
        ui->fakeTerminal_textEdit->setText( ui->fakeTerminal_textEdit->toPlainText() +
                                            "\n\n  -----------------------------------------------------------------------------" +
                                            "\n  OUTPUT RUNNING TIMES " + expCode
                                            );
    }

    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
}

//Execute this SLOT everytime the SMART have an output.
//Update the chart e progress-bar.
void MainWindow::updateGUI(){

    QString javascriptCode = "";
    QString tmpOutput = myProc->readAllStandardOutput().replace('\b',"");

    if (tmpOutput.contains("%")){

        if (countPercent == 0 && currentAlgo == 0)
            completeOutput += createHeadEXP();

        int tmpPercent = (100*countPercent)/ui->Pset_lineEdit->text().toDouble();

        algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                    "\t" + myAlgoName[currentAlgo] + " \t[" + QString::number(tmpPercent) + "%]\t" ;

        countPercent += tmpOutput.count('%');

        ui->fakeTerminal_textEdit->setText(completeOutput + algoOutput[currentAlgo]);

    }

    if( tmpOutput.contains("[OK]") || tmpOutput.contains("[ERROR]") || tmpOutput.contains("[--]") || tmpOutput.contains("[OUT]") ){

        QStringList splittedOutput;
        splittedOutput << tmpOutput.split('\t');

        for(int j=0; j<splittedOutput.length(); j++){
            tmpOutput = splittedOutput[j].replace(" ","").replace('\t',"").replace('\n',"");

            if (currentAlgo == nEnabledAlg){

                //Create the javascript code.
                javascriptCode = "myLineChart.addData([" + timeAlgo.left(timeAlgo.length() - 1) + "], '" + QString::number(currentPlen) + "');";

                //Send js code.
                ui->chart_webView->page()->mainFrame()->evaluateJavaScript(javascriptCode);

                timeAlgo = "";
                currentAlgo = 0;

                if (currentPlen == maxPlen)
                    currentPlen = minPlen;
                else
                    currentPlen*=2;

            }

            if( tmpOutput.contains("ms") && tmpOutput.contains('.') ){

                if(ui->Pre_checkBox->isChecked()){
                    QString timePre = "";
                    QStringList tmpPreTime = tmpOutput.split('+');
                    for(int k=0; k<tmpPreTime.length(); k++){
                        if(tmpPreTime[k].contains("ms")){
                            timeAlgo += tmpPreTime[k].replace(rxFloat,"") + ',';
                            timePre += " + " + tmpPreTime[k].replace(rxFloat,"");
                        }else
                            timePre += tmpPreTime[k].replace(rxFloat,"");

                    }

                    algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                                "\t" + myAlgoName[currentAlgo] + " \t[OK]\t" + timePre + " ms" ; 

                }else{

                    algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                                "\t" + myAlgoName[currentAlgo] + " \t[OK]\t" + tmpOutput.replace(rxFloat,"") + " ms" ;


                    timeAlgo += tmpOutput.replace(rxFloat,"") + ',';

                }

                completeOutput += algoOutput[currentAlgo];
                ui->fakeTerminal_textEdit->setText(completeOutput);


                currentAlgo++;
                countPercent=0;

            }else if ( tmpOutput.contains("[--]") || tmpOutput.contains("[ERROR]") || tmpOutput.contains("[OUT]") ){

                QString tmpError = "--";

                if ( tmpOutput.contains("[ERROR]"))     tmpError = "ERROR";
                else if (tmpOutput.contains("[OUT]"))   tmpError = "OUT";


                algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                            "\t" + myAlgoName[currentAlgo] + " \t[" + tmpError + "]\t" ;

                completeOutput += algoOutput[currentAlgo];
                ui->fakeTerminal_textEdit->setText(completeOutput);

                timeAlgo += "null,";
                currentAlgo++;
                countPercent=0;
            }

        }

    }

    //Go to the end of fakeTerminal.
    QTextCursor c = ui->fakeTerminal_textEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->fakeTerminal_textEdit->setTextCursor(c);

}

//loadResource to create chart and load it into webView.
void MainWindow::loadChart(){

    //Inizialize and clear all supportVariables.
    forcedStop = false;

    nEnabledAlg = 0;
    countPercent = 0;
    currentAlgo = 0;

    myAlgoName.clear();

    ui->fakeTerminal_textEdit->setText("");

    expCode = "";
    completeOutput = "";

    generateEXPCode();

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
    ui->activeAlgo_scrollArea->setLayout(layoutLegend);

    QString chartCodeComplete = chartCode1 + datasets + chartCode2;

    //Write fileChart.
    if (chartFile.open(QFile::WriteOnly|QFile::Truncate)) {
        QTextStream stream(&chartFile);
        stream << chartCodeComplete;
    }


    //Copy Chart.js from resource in local.
    QFile::copy(":/chartFile/chart/Chart.js" , "Chart.js");

    QUrl url("chart.html");             //Url of chart.
    ui->chart_webView->load(url);       //Insert chart in webView.

    algoOutput = new QString[nEnabledAlg];
    for (int i=0; i<nEnabledAlg; i++)
        algoOutput[i] = "";

}

void MainWindow::on_Short_checkBox_released() {

    if(ui->Short_checkBox->isChecked()){
     ui->PlenU_lineEdit->setEnabled(false);
     ui->PlenL_lineEdit->setEnabled(false);
     ui->SimpleP_lineEdit->setEnabled(false);
     ui->SimpleT_lineEdit->setEnabled(false);
    }else{
        ui->PlenU_lineEdit->setEnabled(true);
        ui->PlenL_lineEdit->setEnabled(true);
        ui->SimpleP_lineEdit->setEnabled(true);
        ui->SimpleT_lineEdit->setEnabled(true);
    }

}

void MainWindow::on_SimpleP_lineEdit_textChanged(const QString &arg1) {

    if(arg1 != ""){
       ui->Pset_lineEdit->setEnabled(false);
       ui->Tsize_lineEdit->setEnabled(false);
       ui->Tb_lineEdit->setEnabled(false);
       ui->PlenU_lineEdit->setEnabled(false);
       ui->PlenL_lineEdit->setEnabled(false);
       ui->Text_comboBox->setEnabled(false);
       ui->Short_checkBox->setEnabled(false);
    }else if(arg1 == "" && ui->SimpleT_lineEdit->text() == ""){
        ui->Pset_lineEdit->setEnabled(true);
        ui->Tsize_lineEdit->setEnabled(true);
        ui->Tb_lineEdit->setEnabled(true);
        ui->PlenU_lineEdit->setEnabled(true);
        ui->PlenL_lineEdit->setEnabled(true);
        ui->Text_comboBox->setEnabled(true);
        ui->Short_checkBox->setEnabled(true);
    }

}

void MainWindow::on_SimpleT_lineEdit_textChanged(const QString &arg1) {

    if(arg1 != ""){
        ui->Pset_lineEdit->setEnabled(false);
        ui->Tsize_lineEdit->setEnabled(false);
        ui->Tb_lineEdit->setEnabled(false);
        ui->PlenU_lineEdit->setEnabled(false);
        ui->PlenL_lineEdit->setEnabled(false);
        ui->Text_comboBox->setEnabled(false);
        ui->Short_checkBox->setEnabled(false);
    }else if(arg1 == "" && ui->SimpleP_lineEdit->text() == ""){
        ui->Pset_lineEdit->setEnabled(true);
        ui->Tsize_lineEdit->setEnabled(true);
        ui->Tb_lineEdit->setEnabled(true);
        ui->PlenU_lineEdit->setEnabled(true);
        ui->PlenL_lineEdit->setEnabled(true);
        ui->Text_comboBox->setEnabled(true);
        ui->Short_checkBox->setEnabled(true);
    }

}

void MainWindow::on_PlenU_lineEdit_textChanged(const QString &arg1) {

    if(arg1 != ""){
       ui->Short_checkBox->setEnabled(false);
       ui->SimpleP_lineEdit->setEnabled(false);
       ui->SimpleT_lineEdit->setEnabled(false);
    }else if(arg1 == "" && ui->PlenL_lineEdit->text() == ""){
        ui->Short_checkBox->setEnabled(true);
        ui->SimpleP_lineEdit->setEnabled(true);
        ui->SimpleT_lineEdit->setEnabled(true);
    }

}

void MainWindow::on_PlenL_lineEdit_textChanged(const QString &arg1) {

    if(arg1 != ""){
       ui->Short_checkBox->setEnabled(false);
       ui->SimpleP_lineEdit->setEnabled(false);
       ui->SimpleT_lineEdit->setEnabled(false);
    }else if(arg1 == "" && ui->PlenU_lineEdit->text() == ""){
        ui->Short_checkBox->setEnabled(true);
        ui->SimpleP_lineEdit->setEnabled(true);
        ui->SimpleT_lineEdit->setEnabled(true);
    }

}

void MainWindow::on_start_pushButton_pressed() {

    if(ui->Pset_lineEdit->text() == "")
        ui->Pset_lineEdit->setText(Default500);

    if(ui->Tsize_lineEdit->text() == "")
        ui->Tsize_lineEdit->setText(Default1Mb);

    if(ui->Tb_lineEdit->text() == "")
        ui->Tb_lineEdit->setText(DefaultTb300);

}

void MainWindow::on_start_pushButton_released() {

    QString text2 = "";
    bool canI = false;

    if( ( (ui->SimpleP_lineEdit->text() != "") || (ui->SimpleT_lineEdit->text() != "") ) ){   //SIMPLE

        if(ui->Occ_checkBox->isChecked())
           text2 += " -occ ";

        if(ui->Dif_checkBox->isChecked())
           text2 += " -dif ";

        if(ui->Std_checkBox->isChecked())
           text2 += " -std ";

        if(ui->Txt_checkBox->isChecked())
           text2 += " -txt ";

        if(ui->Tex_checkBox->isChecked())
           text2 += " -tex ";

        if(ui->Pre_checkBox->isChecked())
            text2 += " -pre ";


        parameters = "-simple " +
                    ui->SimpleP_lineEdit->text() +
                    " " +
                    ui->SimpleT_lineEdit->text() +
                    text2;

        canI = true;

    }else if( ( (ui->PlenU_lineEdit->text()!="") || (ui->PlenL_lineEdit->text()!="") ) ){  //PLEN

        minPlen = ui->PlenU_lineEdit->text().toDouble();
        maxPlen = ui->PlenL_lineEdit->text().toDouble();

        if(ui->Occ_checkBox->isChecked())
           text2 += " -occ ";

        if(ui->Dif_checkBox->isChecked())
           text2 += " -dif ";

        if(ui->Std_checkBox->isChecked())
           text2 += " -std ";

        if(ui->Txt_checkBox->isChecked())
           text2 += " -txt ";

        if(ui->Tex_checkBox->isChecked())
           text2 += " -tex ";

        if(ui->Pre_checkBox->isChecked())
            text2 += " -pre ";


        parameters = "-text " +
                    ui->Text_comboBox->currentText() +
                    " -pset "+
                    ui->Pset_lineEdit->text()+
                    " -tsize "+ui->Tsize_lineEdit->text() +
                    " -tb " +
                    ui->Tb_lineEdit->text() +
                    " -plen " +
                    ui->PlenU_lineEdit->text() +
                    " " +
                    ui->PlenL_lineEdit->text() +
                    text2;

        canI = true;

    }else if(ui->Short_checkBox->isChecked()){  //SHORT

        if(ui->Occ_checkBox->isChecked())
           text2 += " -occ ";

        if(ui->Dif_checkBox->isChecked())
           text2 += " -dif ";

        if(ui->Std_checkBox->isChecked())
           text2 += " -std ";

        if(ui->Txt_checkBox->isChecked())
           text2 += " -txt ";

        if(ui->Tex_checkBox->isChecked())
           text2 += " -tex ";

        if(ui->Pre_checkBox->isChecked())
            text2 += " -pre ";


        parameters = "-text " +
                    ui->Text_comboBox->currentText() +
                    " -pset "+
                    ui->Pset_lineEdit->text()+
                    " -tsize " +
                    ui->Tsize_lineEdit->text() +
                    " -tb " +
                    ui->Tb_lineEdit->text() +
                    " -short " +
                    text2;

        canI = true;

    }else{

        if(ui->Occ_checkBox->isChecked())
           text2 += " -occ ";

        if(ui->Dif_checkBox->isChecked())
           text2 += " -dif ";

        if(ui->Std_checkBox->isChecked())
           text2 += " -std ";

        if(ui->Txt_checkBox->isChecked())
           text2 += " -txt ";

        if(ui->Tex_checkBox->isChecked())
           text2 += " -tex ";

        if(ui->Pre_checkBox->isChecked())
            text2 += " -pre ";

        parameters = "-text " +
                    ui->Text_comboBox->currentText() +
                    " -pset "+
                    ui->Pset_lineEdit->text()+
                    " -tsize " +
                    ui->Tsize_lineEdit->text() +
                    " -tb " +
                    ui->Tb_lineEdit->text() +
                    text2;

        canI = true;

    }

    if (canI) {

        ui->stop_pushButton->setEnabled(true);
        ui->start_pushButton->setEnabled(false);
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

void MainWindow::on_stop_pushButton_released(){
    forcedStop = true;
    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
    myProc->kill();
}
