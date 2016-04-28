#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>

#include <QWebView>
#include <QWebFrame>

#include <QTabWidget>

#include <QTimer>
#include <QProcess>
#include <QRegExp>
#include <QColor>
#include <QPalette>

#include <QtWebKit>

#include <cmath>

#include "selectalgwindow.h"
#include "addalgo.h"

#define NumAlgo 500             //Define the number of algorithm

QRegExp rxFloat("[^0-9.]");     //Regex keeps floating number.

QProcess *myProc;               //Declare myProc.

QStringList myAlgoName;         //Name of active algo.
QString *algoOutput;            //List of all output for fake terminal.

int nEnabledAlg;                //Number of active algo.
int nExecutePatt;               //Number of patterns to execute.
int currentAlgo;                //Current algorithm.
int countPercent = 0;           //Percent of currente execute algorithm.
int helpCounterAlg = 0;         //Help variable to calculate percentage.

double minPlen = 2;             //Min plen.
double maxPlen = 4096;          //Max plen.
double currentPlen;             //Current plen.

QVBoxLayout *layoutLegend;      //Declare new Layout.

QString completeOutput = "";               //Output string goint to fake terminal.
QString parameters = "";                   //Parameters to send in smart.
QString timeAlgo = "";                     //String with result algo time.
QString expCode = "";                      //String with code ex.
QString folderSource = "smartSource";      //Folder contains source of smart.

bool forcedStop = false;        //Bool true if click stop button.

QString Default500 = "500";
QString Default1Mb = "1";
QString DefaultTb300 = "300";

QWebView *chartWebView;
QTabWidget *tabWebView;

//Constructor.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    ui->Pset_lineEdit->setText(Default500);
    ui->Tsize_lineEdit->setText(Default1Mb);
    ui->Tb_lineEdit->setText(DefaultTb300);

    layoutLegend = new QVBoxLayout();

    tabWebView = new QTabWidget;
    ui->layoutWebView->addWidget(tabWebView);

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
    const QString help = "\tThis is an help guide for using the tool.\n"
                         "\n\n-pset N computes running times as the mean of N runs (default 500)."
                         "\n\n-tsize S set the upper bound dimension (in Mb) of the text used for experimental results (default 1Mb)."
                         "\n\n-plen L U  test only patterns with a length between L and U (included)."
                         "\n\n-text F  performs experimental results using text buffer F (mandatory unless you use the -simple parameter)."
                         "\n\n-short computes experimental results using short length patterns."
                         "\n\n-occ prints the number of occurrences."
                         "\n\n-tb L set to L the upper bound for any wort case running time (in ms). The default value is 300 ms."
                         "\n\n-dif prints the number the best and the worst running time."
                         "\n\n-std prints the standard deviations of the running times."
                         "\n\n-txt output results in txt tabular format."
                         "\n\n-tex output results in latex tabular format."
                         "\n\n-simple P T executes a single run searching T (max 1000 chars) for occurrences of P (max 100 chars)."
                         "\n\nSMART by Faro Simone."
                         "\nGUI by \nAlessandro Maggio\nSimone Di Mauro\nStefano Borzi.";

    QMessageBox::information(this,"About!",help);
}

//Load into array parameters the status of algo.
void getAlgoMain(char *ALGO_NAME[], int EXECUTE[]) {
    FILE *fp = fopen("smartSource/source/algorithms.h", "r");
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

    return  QString::fromLatin1("\n\n  ---------------------------------------------------------------------") +
            QString::fromLatin1("\n  Experimental results on ") + ui->Text_comboBox->currentText() + QString::fromLatin1(": ") + expCode +
            QString::fromLatin1("\n  Searching for a set of ") + ui->Pset_lineEdit->text() + QString::fromLatin1(" patterns with length ") + QString::number(currentPlen) +
            QString::fromLatin1("\n  Testing ") + QString::number(nEnabledAlg) + QString::fromLatin1(" algorithms \n");

}

int calculatePercentage(){
    return (helpCounterAlg*100)/(nEnabledAlg * nExecutePatt);
}

//Execute this SLOT on ended process.
void MainWindow::processEnded(){

    if(forcedStop)
        ui->fakeTerminal_textEdit->setText( ui->fakeTerminal_textEdit->toPlainText() +
                                            "\n\n  ---------------------------------------------------------------------" +
                                            "\n  STOPPED BY USER " + expCode
                                            );
    else{
        ui->progressBar->setValue(calculatePercentage());
        QMessageBox::information(this,"Done!","Test complete.");
        ui->fakeTerminal_textEdit->setText( ui->fakeTerminal_textEdit->toPlainText() +
                                            "\n\n  ---------------------------------------------------------------------" +
                                            "\n  OUTPUT RUNNING TIMES " + expCode
                                            );
    }

    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
}

//Execute this SLOT everytime the SMART have an output.
//Update the chart e progress-bar.
void MainWindow::updateGUI(){

    ui->progressBar->setValue(calculatePercentage());

    QString javascriptCode = "";
    QString tmpOutput = myProc->readAllStandardOutput().replace('\b',"");

    if (tmpOutput.contains("%")){

        int tmpPercent = (100*countPercent)/ui->Pset_lineEdit->text().toDouble();

        algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                    "\t" + myAlgoName[currentAlgo] + " \t[" + QString::number(tmpPercent) + "%]\t" ;

        countPercent += tmpOutput.count('%');

        ui->fakeTerminal_textEdit->setText(completeOutput + algoOutput[currentAlgo]);

    }

    if( tmpOutput.contains("[OK]") || tmpOutput.contains("[ERROR]") || tmpOutput.contains("[--]") || tmpOutput.contains("[OUT]") ){

        QString infoAlgo = "";
        QStringList splittedOutput;
        splittedOutput << tmpOutput.split('\t');

        for(int j=0; j<splittedOutput.length(); j++){

            tmpOutput = splittedOutput[j].replace('\n',"");
            QStringList splittedBySpace = tmpOutput.split("  "); //Split by doubleSpace

            for(int i=0; i<splittedBySpace.length(); i++){
                if(splittedBySpace[i].contains("ms") && tmpOutput.contains('.')){

                    if(splittedBySpace[i].contains('+')){
                        QStringList tmpTimePre = splittedBySpace[i].split('+');
                        for(int f=0; f<tmpTimePre.length(); f++)
                            if(tmpTimePre[f].contains("ms")){
                                timeAlgo += tmpTimePre[f].replace(rxFloat,"") + ',';
                                infoAlgo += '\t' + tmpTimePre[f].replace(rxFloat,"") + " ms";
                            }


                    }else{
                        timeAlgo += splittedBySpace[i].replace(rxFloat,"") + ',';
                        infoAlgo += '\t' + splittedBySpace[i].replace(rxFloat,"") + " ms";
                    }
                }

                if(splittedBySpace[i].contains("std"))
                    infoAlgo += '\t' + splittedBySpace[i];

                if(splittedBySpace[i].contains('[') &&  splittedBySpace[i].contains(']') && splittedBySpace[i].contains(',')){
                    infoAlgo += '\t' + splittedBySpace[i];
                }
            }

            if (currentAlgo == nEnabledAlg){

                //Create the javascript code.
                javascriptCode = "myLineChart.addData([" + timeAlgo.left(timeAlgo.length() - 1) + "], '" + QString::number(currentPlen) + "');";

                //Send js code.
                chartWebView->page()->mainFrame()->evaluateJavaScript(javascriptCode);

                completeOutput += createHeadEXP();

                timeAlgo = "";
                currentAlgo = 0;

                if (currentPlen == maxPlen)
                    currentPlen = minPlen;
                else
                    currentPlen*=2;

            }

            if( tmpOutput.contains("ms") && tmpOutput.contains('.') ){

                algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                            "\t" + myAlgoName[currentAlgo] + " \t[OK]" + infoAlgo ;

                completeOutput += algoOutput[currentAlgo];
                ui->fakeTerminal_textEdit->setText(completeOutput);

                currentAlgo++;
                countPercent=0;

                helpCounterAlg++;
                infoAlgo = "";

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

                helpCounterAlg++;
            }

        }

    }

    //Go to the end of fakeTerminal.
    QTextCursor c = ui->fakeTerminal_textEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->fakeTerminal_textEdit->setTextCursor(c);

}

//Clear layout.
void clearLayout(){
    QLayoutItem *item;
    while((item = layoutLegend->takeAt(0))) {
        if (item->layout()) {
            clearLayout();
            delete item->layout();
        }
        if (item->widget())
            delete item->widget();

        delete item;
    }
}

//Inizialize and clear all supportVariables
void MainWindow::inizializeAll(){

    timeAlgo = "";

    ui->progressBar->setValue(0);
    helpCounterAlg = 0;

    forcedStop = false;

    nEnabledAlg = 0;
    countPercent = 0;
    currentAlgo = 0;

    myAlgoName.clear();

    ui->fakeTerminal_textEdit->setText("");

    expCode = "";
    completeOutput = "";

    generateEXPCode();

    clearLayout();
}

//loadResource to create chart and load it into webView.
void MainWindow::loadChart(){

    inizializeAll();

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

    chartWebView = new QWebView();
    tabWebView->insertTab(tabWebView->count(), chartWebView, ui->Text_comboBox->currentText());
    tabWebView->setCurrentIndex(tabWebView->count()-1);

    QUrl url("chart.html");        //Url of chart.
    chartWebView->load(url);       //Insert chart in webView.

    algoOutput = new QString[nEnabledAlg];
    algoOutput->clear();

    completeOutput += createHeadEXP();

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

    QString tmpPr = "";

    QFile SmartCheck(folderSource + "/smart");
    QFile SelectCheck(folderSource + "/select");
    QFile TestCheck(folderSource + "/test");

    if (SmartCheck.exists() && SelectCheck.exists() && TestCheck.exists()){

        if(ui->Occ_checkBox->isChecked())
           tmpPr += " -occ ";

        if(ui->Dif_checkBox->isChecked())
           tmpPr += " -dif ";

        if(ui->Std_checkBox->isChecked())
           tmpPr += " -std ";

        if(ui->Txt_checkBox->isChecked())
           tmpPr += " -txt ";

        if(ui->Tex_checkBox->isChecked())
           tmpPr += " -tex ";

        if(ui->Pre_checkBox->isChecked())
           tmpPr += " -pre ";

        if( ( (ui->SimpleP_lineEdit->text() != "") || (ui->SimpleT_lineEdit->text() != "") ) ){   //SIMPLE

            parameters = "-simple " + ui->SimpleP_lineEdit->text() + " " + ui->SimpleT_lineEdit->text() +
                         tmpPr;


        }else if( ( (ui->PlenU_lineEdit->text()!="") || (ui->PlenL_lineEdit->text()!="") ) ){  //PLEN

            parameters = "-text " + ui->Text_comboBox->currentText() +
                        " -pset "+ ui->Pset_lineEdit->text()+
                        " -tsize " + ui->Tsize_lineEdit->text() +
                        " -tb " + ui->Tb_lineEdit->text() +
                        " -plen " + ui->PlenU_lineEdit->text() + " " + ui->PlenL_lineEdit->text() +
                        tmpPr;


        }else if(ui->Short_checkBox->isChecked()){  //SHORT

            parameters = "-text " + ui->Text_comboBox->currentText() +
                        " -pset "+ ui->Pset_lineEdit->text()+
                        " -tsize " + ui->Tsize_lineEdit->text() +
                        " -tb " + ui->Tb_lineEdit->text() + " -short " + tmpPr;

        }else{

            parameters = "-text " + ui->Text_comboBox->currentText() +
                        " -pset "+ ui->Pset_lineEdit->text()+
                        " -tsize " + ui->Tsize_lineEdit->text() +
                        " -tb " + ui->Tb_lineEdit->text() +
                        tmpPr;

        }

        if(ui->PlenU_lineEdit->text()!="" || ui->PlenU_lineEdit->text()!=""){
            minPlen = ui->PlenU_lineEdit->text().toDouble();
            maxPlen = ui->PlenL_lineEdit->text().toDouble();
        }else{
            minPlen = 2;
            maxPlen = 4096;
        }

        ui->stop_pushButton->setEnabled(true);
        ui->start_pushButton->setEnabled(false);

        loadChart();

        QString execute = "./smart " + parameters;
        qDebug() << execute;

        nExecutePatt = (floor ( Log2(maxPlen))) - (ceil ( Log2(minPlen))) + 1;

        minPlen = pow(2, ceil ( Log2(minPlen) ) );
        maxPlen = pow(2, floor ( Log2(maxPlen) ) );

        currentPlen = minPlen;

        myProc = new QProcess(this);                                                    //Create process.
        connect(myProc, SIGNAL(readyReadStandardOutput()), this, SLOT(updateGUI()) );   //Connect SLOT updateGUI to SIGNAL output.
        connect(myProc, SIGNAL(finished(int)), this, SLOT(processEnded()) );            //Connect SLOT processEnded to SIGNAL finished.
        myProc->setWorkingDirectory(folderSource);                                      //Set the folder with SMART.
        myProc->start(execute);                                                         //Start process.

    }else
        QMessageBox::warning(this,"Error!","Need SMART source in folder.");


}

void MainWindow::on_stop_pushButton_released() {
    forcedStop = true;
    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
    myProc->kill();
}

void MainWindow::on_actionAdd_Algorithms_triggered() {
    AddAlgo openAddAlgoWin;
    openAddAlgoWin.setModal(true);
    openAddAlgoWin.exec();

}
