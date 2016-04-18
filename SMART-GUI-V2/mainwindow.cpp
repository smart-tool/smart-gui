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

#include <QtWebKit>

#include "selectalgwindow.h"
#include "mythread.h"

QString Default500 = "500";
QString Default1Mb = "1";
QString DefaultTb300 = "300";

QString smartSource = "./smart ";
QString parameters = "";

QProcess *myProc;

//Constructor.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    //ui->centralWidget->setFixedSize(500,500);

    ui->setupUi(this);

    ui->lineEdit->setText(Default500);
    ui->lineEdit_4->setText(Default1Mb);
    ui->lineEdit_5->setText(DefaultTb300);

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


int nOldRow = 0;
#define NumAlgo 500 //Define the number of algorithm

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

void MainWindow::updateGraph(){

    //qDebug() << myProc->readAllStandardOutput().replace('\b',' ');

    QFile timeAlgFile("guiExtract/timeAlg.txt");      //Load timeAlg.txt File.
    QString javascriptCode = "";

    QStringList testAlgo;
    QStringList testAlgoSplitted;

    QString timeAlgo;
    QString lenghtAlgo;

    QString tmpLine = "";

    int nNewRow = 0;

    //Read timeAlg.
    if (timeAlgFile.open(QIODevice::ReadOnly)) {
       QTextStream in(&timeAlgFile);
       while (!in.atEnd()) {
          tmpLine = in.readLine();
          if ( tmpLine.contains("OK") ){
              testAlgo << tmpLine;
              nNewRow++;
          }
       }
       timeAlgFile.close();
    }

    if(nOldRow != nNewRow){                                                                         //If the load file have new row by old.
        for (int i=nOldRow; i<testAlgo.length(); i++){
            testAlgoSplitted = testAlgo[i].split("|");                                              //Split by |.
            lenghtAlgo = testAlgoSplitted[0];                                                       //Get the lenght (patternes).
            timeAlgo = testAlgoSplitted[1];                                                         //Get the list of execute alg.
            timeAlgo = timeAlgo.left(timeAlgo.length() - 3);                                        //Remove the ,OK flag .
            javascriptCode = "myLineChart.addData([" + timeAlgo + "], '" + lenghtAlgo + "');";      //Create the javascript code.
            ui->webView->page()->mainFrame()->evaluateJavaScript(javascriptCode);                   //Send js code.
        }
        nOldRow = nNewRow;                                                                          //Update the number of row.
    }
}

void loadGraph(){
    int EXECUTE[NumAlgo];                                      //Declare EXECTUE array with the state of alrgorithm (0/1).
    char *ALGO_NAME[NumAlgo];                                  //Declare array ALGO_NAME with the name of all string matching algorithms

    QFile graphCode1File("guiExtract/graph/part1.txt");        //Load part1 of html graph.
    QFile graphCode2File("guiExtract/graph/part2.txt");        //Load part2 of html graph.
    QFile graphFile("guiExtract/graph/grafico.html");          //Load file of graph.

    QString graphCodeComplete = "";
    QString graphCode1 = "";
    QString graphCode2 = "";

    QString datasets = "";

    int r, g, b;

    //Read part1.
    if (graphCode1File.open(QIODevice::ReadOnly)) {
        QTextStream in(&graphCode1File);
        graphCode1 = in.readAll();
        graphCode1File.close();
    }

    //Read part2.
    if (graphCode2File.open(QIODevice::ReadOnly)) {
        QTextStream in(&graphCode2File);
        graphCode2 = in.readAll();
        graphCode2File.close();
    }

    //Load array.
    getAlgoMain(ALGO_NAME,EXECUTE);

    //Create the datasets
    for(int i=0;i<NumAlgo;i++){\
        if(ALGO_NAME[i] && EXECUTE[i]){
            r = qrand() % ((255 + 1) - 1) + 1;
            g = qrand() % ((255 + 1) - 1) + 1;
            b = qrand() % ((255 + 1) - 1) + 1;

            datasets = datasets + "{\n\tlabel: '" + ALGO_NAME[i] + "',\n" +
                                  "\tfillColor: 'rgba(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ",0.2)'" + ",\n" +
                                  "\tstrokeColor: 'rgba(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ",1)'" + ",\n" +
                                  "\tpointColor: 'rgba(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ",1)'" + ",\n" +
                                  "\tpointStrokeColor: '#fff'" + ",\n" +
                                  "\tpointHighlightFill: '#fff'" + ",\n" +
                                  "\tpointHighlightStroke: 'rgba(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ",1)'" + ",\n},\n" ;
        }
    }

    graphCodeComplete = graphCodeComplete + graphCode1 + datasets + graphCode2;

    //Write fileGraph.
    if (graphFile.open(QFile::WriteOnly|QFile::Truncate)) {
        QTextStream stream(&graphFile);
        stream << graphCodeComplete;
    }

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

    }else if( ( (ui->lineEdit_6->text()!="") || (ui->lineEdit_7->text()!="") ) ){  //PSET

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
                    " -tsize " +
                    ui->lineEdit_4->text() +
                    " -tb " +
                    ui->lineEdit_5->text() +
                    text2;

        canI = true;

    }

    if (canI) {
        loadGraph();                                        //Load graph.
        QUrl url("guiExtract/graph/grafico.html");          //Url of graph.
        ui->webView->load(url);                             //Insert graph in webView.

        QTimer *timer = new QTimer(this);                                   //Declare newTimer.
        connect(timer, SIGNAL(timeout()), this, SLOT(updateGraph()) );      //Connect timer to slot updateGraph().

        QString execute = smartSource + parameters;
        //myProc = new QProcess(this);
        //connect(myProc, SIGNAL(readyReadStandardOutput()), this, SLOT(updateGraph()) );

        //myProc->start(execute);

        //myProc->kill();

        /*

            //QString execute = smartSource + parameters;
            qDebug() << execute;

            QByteArray ba = execute.toLatin1();
            const char *z = ba.data();

            MyThread *thread1 = new MyThread(z);
            thread1->start();
         */


        timer->start(1000);                         //Start timer(ms).*/

    }

}
