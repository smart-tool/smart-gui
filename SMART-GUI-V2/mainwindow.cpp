#include "mainwindow.h"
#include "ui_mainwindow.h"

//Include the other window header.
#include "selectalgwindow.h"
#include "addalgo.h"
#include "setupwindow.h"

//Library for manage file and directory.
#include <QFile>
#include <QDir>

//Library for manage String.
#include <QString>
#include <QStringList>
#include <QRegExp>

//Library for the ui.
#include <QTabWidget>
#include <QTextEdit>
#include <QScrollArea>
#include <QSplitter>

//Library for styleLabel.
#include <QColor>
#include <QPalette>

//Library for webEngineView.
#include <QtWebEngineWidgets>
#include <QWebEnginePage>
#include <QWebEngineView>

#include <QDebug>

#include <QMessageBox>

#include <QProcess>

#include <cmath>

#define NumAlgo 500             //Define the number of algorithm.

QString completeOutput = "";    //Output string goint to fake terminal.
QString parameters = "";        //Parameters to send in smart.
QString timeAlgo = "";          //String with result algo time.
QString expCode = "";           //String with code ex.

QProcess *myProc;               //Declare myProc.

QStringList nameText;           //List of all text name for 'all test'.
QStringList myAlgoName;         //List of name of active algo.
QString *algoOutput;            //List of all output for fake terminal.

int nEnabledAlg;                //Number of active algo.
int nExecutePatt;               //Number of patterns to execute.
int currentAlgo;                //Current algorithm.
int countPercent = 0;           //Percent of currente execute algorithm.
int helpCounterAlg = 0;         //Help variable to calculate percentage.

double minPlen = 2;             //Min plen.
double maxPlen = 4096;          //Max plen.
double currentPlen;             //Current plen.

bool forcedStop;                //Bool true if click stop button.
bool errorParameters;           //Bool true if we wrong parameters in Smart.
bool errorSegmentationFault;    //Bool true if Smart have a Segmentation Fault.

QString Default500 = "500";     //Default value for Pset.
QString Default1Mb = "1";       //Default value for Tsize.
QString DefaultTb300 = "300";   //Default value for Tb.

QTextEdit *fakeTerminal;        //Pointer of textEdit used to made a dynamic fakeTerminal.
QVBoxLayout *layoutLegend;      //Pointer of boxLayout used to made a legend of active algo.
QScrollArea *scrollActiveAlgo;  //Pointer of scrollArea to make the layoutLenged scrollable.
QSplitter *layoutForTab;        //Pointer of splitter to make resizable the GUI.

QWebEngineView *showResult;     //Pointer of webEngineView used to show the result test.

QWebEngineView *chartWebView;           //Pointer of webEngineView (Show single chart).
QTabWidget *tabData;                    //Pointer of tabWidget (different tab for different exp).

QWebEngineView *chartWebViewAll[100];   //Array of pointer of webEngineView (Show the multi char for test "all text").
QTabWidget *tabChartWebView;            //Pointer of tabWidget (different tab for different text).

QString pathSmartGUI = QDir::homePath() + "/smartGUI";  //Default directory contains smartGUI file (chart.html, chart.js and path of smartSource (nextUpdate) ).
QString pathSmart = pathSmartGUI + "/smartSource";      //Default contains smartSource file.

//Constructor.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    //Set the the default value in lineEdit.
    ui->Pset_lineEdit->setText(Default500);
    ui->Tsize_lineEdit->setText(Default1Mb);
    ui->Tb_lineEdit->setText(DefaultTb300);

    //Create new tab and add it to layout.
    tabData = new QTabWidget;
    ui->horizontalLayout_2->addWidget(tabData);

    //Load all name of text.
    nameText << "rand2" << "rand4" << "rand8" << "rand16" << "rand32" << "rand64" << "rand128" << "rand250" <<
                "italianTexts" << "englishTexts" << "frenchTexts" << "chineseTexts" << "midimusic" << "genome" << "protein";

    //Allow only number in lineEdit.
    ui->PlenL_lineEdit->setValidator( new QIntValidator(0, 1000, this) );
    ui->PlenU_lineEdit->setValidator( new QIntValidator(0, 1000, this) );
    ui->Tb_lineEdit->setValidator( new QIntValidator(0, 1000, this) );
    ui->Tsize_lineEdit->setValidator( new QIntValidator(0, 1000, this) );
    ui->Pset_lineEdit->setValidator( new QIntValidator(0, 1000, this) );

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

    QByteArray tmpByteArray = pathSmart.toLatin1() + "/source/algorithms.h";
    const char * pathSmartConst = tmpByteArray.data();

    FILE *fp = fopen(pathSmartConst, "r");
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

    QString tmpText;
    if (ui->SimpleT_lineEdit->text() != "")
        tmpText = ui->SimpleT_lineEdit->text();
    else if( ui->Text_comboBox->currentText() != "all" )
        tmpText = ui->Text_comboBox->currentText();
    else
        tmpText = nameText[tabChartWebView->count()-1];

    return  QString::fromLatin1("\n\n  ---------------------------------------------------------------------") +
            QString::fromLatin1("\n  Experimental results on ") + tmpText + QString::fromLatin1(": ") + expCode +
            QString::fromLatin1("\n  Searching for a set of ") + ui->Pset_lineEdit->text() + QString::fromLatin1(" patterns with length ") + QString::number(currentPlen) +
            QString::fromLatin1("\n  Testing ") + QString::number(nEnabledAlg) + QString::fromLatin1(" algorithms \n");

}

int calculatePercentage(){
    return (helpCounterAlg*100)/(nEnabledAlg * nExecutePatt);
}

void MainWindow::showResultFunction(){
    showResult->show();
}

//Execute this SLOT on ended process.
void MainWindow::processEnded(){

    if(forcedStop)
        fakeTerminal->setText( fakeTerminal->toPlainText() +
                                            "\n\n  ---------------------------------------------------------------------" +
                                            "\n  STOPPED BY USER " + expCode
                                            );
    else if(errorParameters){
        fakeTerminal->setText( fakeTerminal->toPlainText() +
                                            "\n\n  ---------------------------------------------------------------------" +
                                            "\n  ERROR IN INPUT PARAMETERS " + expCode
                                            );

         QMessageBox::warning(this,"Error!","Error in input parameters.");
    }else if(errorSegmentationFault){
        fakeTerminal->setText( fakeTerminal->toPlainText() +
                                            "\n\n  ---------------------------------------------------------------------" +
                                            "\n  SEGMENTATION FAULT " + expCode
                                            );

         QMessageBox::warning(this,"Error!","Segmentation fault.");

    }else{
        ui->progressBar->setValue(calculatePercentage());
        fakeTerminal->setText( fakeTerminal->toPlainText() +
                                            "\n\n  ---------------------------------------------------------------------" +
                                            "\n  OUTPUT RUNNING TIMES " + expCode
                                            );

        if (ui->Text_comboBox->currentText() != "all"){
            fakeTerminal->setText( fakeTerminal->toPlainText() + "\n\n  Saving data on " + expCode + "/" + ui->Text_comboBox->currentText() + ".xml" +
                                                                 "\n  Saving data on " + expCode + "/" + ui->Text_comboBox->currentText() + ".html" );

            if (ui->Tex_checkBox->isChecked())
                fakeTerminal->setText( fakeTerminal->toPlainText() + "\n  Saving data on " + expCode + "/" + ui->Text_comboBox->currentText() + ".tex" );

            if (ui->Txt_checkBox->isChecked())
                fakeTerminal->setText( fakeTerminal->toPlainText() + "\n  Saving data on " + expCode + "/" + ui->Text_comboBox->currentText() + ".txt" );


            if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "Done!", "Test complete.\nOpen " + expCode + "/" + ui->Text_comboBox->currentText() + ".html?", QMessageBox::Yes|QMessageBox::No).exec()) {
                showResult = new QWebEngineView();
                showResult->load(QUrl("file:///" + pathSmart + "/results/" + expCode + "/" + ui->Text_comboBox->currentText() + ".html"));
                connect(showResult, SIGNAL(loadFinished(bool)), this, SLOT(showResultFunction()));
            }

        }else{
            for(int j=0; j<tabChartWebView->count()-1; j++){
                fakeTerminal->setText( fakeTerminal->toPlainText() + "\n\n  Saving data on " + expCode + "/" + nameText[j] + ".xml" +
                                                                     "\n  Saving data on " + expCode + "/" + nameText[j] + ".html" );

                if (ui->Tex_checkBox->isChecked())
                    fakeTerminal->setText( fakeTerminal->toPlainText() + "\n  Saving data on " + expCode + "/" + nameText[j] + ".tex" );

                if (ui->Txt_checkBox->isChecked())
                    fakeTerminal->setText( fakeTerminal->toPlainText() + "\n  Saving data on " + expCode + "/" + nameText[j] + ".txt" );

            }

            QMessageBox::information(this,"Done!","Test complete.");
        }

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
    QString tmpError = myProc->readAllStandardError().replace('\b',"");

    if (tmpOutput.contains("Error in input parameters"))
        errorParameters = true;
    else if(tmpError.contains("Segmentation fault"))
        errorSegmentationFault = true;
    else{
        if (tmpOutput.contains("%")){

            int tmpPercent = (100*countPercent)/ui->Pset_lineEdit->text().toDouble();

            algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                        "\t" + myAlgoName[currentAlgo] + " \t[" + QString::number(tmpPercent) + "%]\t" ;

            countPercent += tmpOutput.count('%');

            fakeTerminal->setText(completeOutput + algoOutput[currentAlgo]);

        }

        if( tmpOutput.contains("[OK]") || tmpOutput.contains("[ERROR]") || tmpOutput.contains("[--]") || tmpOutput.contains("[OUT]") ){

            QRegExp rxFloat("[^0-9.]");     //Regex keeps floating number.
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
                                    infoAlgo += tmpTimePre[f].replace(rxFloat,"") + " ms";
                                }else
                                    infoAlgo += '\t' + tmpTimePre[f].replace(rxFloat,"") + "+";

                        }else{
                            timeAlgo += splittedBySpace[i].replace(rxFloat,"") + ',';
                            infoAlgo += '\t' + splittedBySpace[i].replace(rxFloat,"") + " ms";
                        }
                    }

                    if(splittedBySpace[i].contains("std"))
                        infoAlgo += '\t' + splittedBySpace[i];

                    if(splittedBySpace[i].contains('[') &&  splittedBySpace[i].contains(']') && splittedBySpace[i].contains(','))
                        infoAlgo += '\t' + splittedBySpace[i];
                }

                if (currentAlgo == nEnabledAlg){

                    //Create the javascript code.
                    javascriptCode = "myLineChart.addData([" + timeAlgo.left(timeAlgo.length() - 1) + "], '" + QString::number(currentPlen) + "');";

                    //Send js code.
                    if(ui->Text_comboBox->currentText() != "all")
                        chartWebView->page()->runJavaScript(javascriptCode);
                    else
                        chartWebViewAll[tabChartWebView->count() - 1]->page()->runJavaScript(javascriptCode);

                    timeAlgo = "";
                    currentAlgo = 0;

                    if (currentPlen == maxPlen && ui->Text_comboBox->currentText() == "all"){
                        currentPlen = minPlen;

                        tabChartWebView->insertTab(tabChartWebView->count(), chartWebViewAll[tabChartWebView->count()], nameText[tabChartWebView->count()] );
                        tabChartWebView->setCurrentIndex(tabChartWebView->count()-1);

                        ui->progressBar->setValue(0);
                        helpCounterAlg = 0;
                        countPercent = 0;
                    }else
                        currentPlen*=2;

                    completeOutput += createHeadEXP();

                }

                if( tmpOutput.contains("ms") && tmpOutput.contains('.') ){

                    if( ui->Occ_checkBox->isChecked() )
                        infoAlgo += '\t' + splittedOutput[j+1].replace('\n',"");

                    algoOutput[currentAlgo] =   "\n  - [" + QString::number(currentAlgo+1) + "/" + QString::number(nEnabledAlg) + "]"
                                                "\t" + myAlgoName[currentAlgo] + " \t[OK]" + infoAlgo ;

                    completeOutput += algoOutput[currentAlgo];
                    fakeTerminal->setText(completeOutput);

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
                    fakeTerminal->setText(completeOutput);

                    timeAlgo += "null,";
                    currentAlgo++;
                    countPercent=0;

                    helpCounterAlg++;
                }

            }

        }
    }

    //Go to the end of fakeTerminal.
    QTextCursor c = fakeTerminal->textCursor();
    c.movePosition(QTextCursor::End);
    fakeTerminal->setTextCursor(c);

}


//Inizialize and clear all supportVariables
void MainWindow::inizializeAll(){

    timeAlgo = "";

    ui->progressBar->setValue(0);
    helpCounterAlg = 0;

    forcedStop = false;
    errorParameters = false;
    errorSegmentationFault = false;

    nEnabledAlg = 0;
    countPercent = 0;
    currentAlgo = 0;

    myAlgoName.clear();

    expCode = "";
    completeOutput = "";

    generateEXPCode();

    layoutForTab = new QSplitter();


    fakeTerminal = new QTextEdit();
    fakeTerminal->setReadOnly(true);
    fakeTerminal->setLineWrapMode((QTextEdit::NoWrap));
    layoutForTab->addWidget(fakeTerminal);

    if( ui->Text_comboBox->currentText() == "all" ){

        for(int i=0; i<nameText.length(); i++)
            chartWebViewAll[i] = new QWebEngineView();

        tabChartWebView = new QTabWidget;
        layoutForTab->addWidget(tabChartWebView);
        tabChartWebView->insertTab(tabChartWebView->count(), chartWebViewAll[tabChartWebView->count()], nameText[tabChartWebView->count()]);

    }else{
        chartWebView = new QWebEngineView();
        layoutForTab->addWidget(chartWebView);
    }

    scrollActiveAlgo = new QScrollArea();
    layoutLegend = new QVBoxLayout();
    scrollActiveAlgo->setLayout(layoutLegend);
    scrollActiveAlgo->setMaximumWidth(150);
    layoutForTab->addWidget(scrollActiveAlgo);

    tabData->insertTab(tabData->count(), layoutForTab, expCode );
    tabData->setCurrentIndex(tabData->count()-1);

}

//loadResource to create chart and load it into webView.
void MainWindow::createChart(){

    inizializeAll();

    int EXECUTE[NumAlgo];                                             //Declare EXECTUE array with the state of alrgorithm (0/1).
    char *ALGO_NAME[NumAlgo];                                         //Declare array ALGO_NAME with the name of all string matching algorithms

    QFile chartCode1File(":/chartFile/chart/chartPart1.html");        //Load part1 of htmlChart by res.
    QFile chartCode2File(":/chartFile/chart/chartPart2.html");        //Load part2 of htmlChart by res..
    QFile chartFile(pathSmartGUI + "/chart.html");                   //Load file of graph.

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

    QString chartCodeComplete = chartCode1 + datasets + chartCode2;

    //Write fileChart.
    if (chartFile.open(QFile::WriteOnly|QFile::Truncate)) {
        QTextStream stream(&chartFile);
        stream << chartCodeComplete;
    }

    //Copy Chart.js from resource in local.
    QFile::copy(":/chartFile/chart/Chart.js" , pathSmartGUI +  "/Chart.js");

    if( ui->Text_comboBox->currentText() != "all" )
        chartWebView->load(QUrl("file:///" + pathSmartGUI +  "/chart.html"));
    else{
        for(int i=0; i<nameText.length(); i++)
            chartWebViewAll[i]->load(QUrl("file:///" + pathSmartGUI +  "/chart.html"));
    }

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

    QFile SmartCheck(pathSmart + "/smart");
    QFile SelectCheck(pathSmart + "/select");
    QFile TestCheck(pathSmart + "/test");

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

        QString execute = "./smart " + parameters;
        qDebug() << execute;

        nExecutePatt = (floor ( Log2(maxPlen))) - (ceil ( Log2(minPlen))) + 1;

        minPlen = pow(2, ceil ( Log2(minPlen) ) );
        maxPlen = pow(2, floor ( Log2(maxPlen) ) );

        currentPlen = minPlen;

        createChart();

        myProc = new QProcess(this);                                                    //Create process.
        connect(myProc, SIGNAL(readyReadStandardOutput()), this, SLOT(updateGUI()) );   //Connect SLOT updateGUI to SIGNAL output.
        connect(myProc, SIGNAL(finished(int)), this, SLOT(processEnded()) );            //Connect SLOT processEnded to SIGNAL finished.
        myProc->setWorkingDirectory(pathSmart);                                        //Set the folder with SMART.
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

void MainWindow::on_actionSetup_SMART_GUI_triggered(){
    setupWindow openSetupWindow;
    openSetupWindow.setModal(true);
    openSetupWindow.exec();
}
