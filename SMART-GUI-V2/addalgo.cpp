#include "addalgo.h"
#include "ui_addalgo.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QProcess>

#include <QDir>

QString ___pathSmartGUI = QDir::homePath() + "/smartGUI";
QString ___pathSmart = ___pathSmartGUI + "/smartSource";

AddAlgo::AddAlgo(QWidget *parent) : QDialog(parent), ui(new Ui::AddAlgo) {
    ui->setupUi(this);
    ui->textEdit->setText("#include \"include/main.h\"\n\n //ADD YOUR CODE HERE \n\n //FOR MORE INFO FOR ADD ALGORTHIMS VISIT http://www.dmi.unict.it/~faro/smart/howto.php?id=18 \n\n");
    this->Selected=false;
    this->NameAlgo="";
}

AddAlgo::~AddAlgo(){
    delete ui;
}

void AddAlgo::updateBar(){


    QString tmpOutput2 = ProcAdd->readAllStandardOutput().replace("\b","");

    tmpOutput2 = tmpOutput2.replace("%]","");
    tmpOutput2 = tmpOutput2.replace("[0","");
    tmpOutput2 = tmpOutput2.replace("[00","");

    ui->progressBar->setValue(tmpOutput2.toInt());

    if(tmpOutput2.contains("ok"))
        finPro();

}

void AddAlgo::finPro(){

    if(this->Selected){

        QString SelectSequence = "./select " + NameAlgo;
        QByteArray ba = SelectSequence.toLatin1();
        const char * SelectSequence2 = ba.data();
        delete ProcAdd;

        ProcAdd = new QProcess(this);
        ProcAdd->setWorkingDirectory(___pathSmart);
        ProcAdd->start(SelectSequence2);

        QString Add = "Algortmhs add and select \n\n";
        QMessageBox::information(this,"ADD and Select",Add);
        this->close();
    }else {

        QString Add = "Algortmhs add \n\n";
        QMessageBox::information(this,"ADD",Add);
        this->close();
    }

}

void AddAlgo::on_pushButton_clicked()
{

    bool CompiledCheck = false;
    this->NameAlgo = "";
    this->Selected = false;

    if(ui->checkBox->isChecked())
        this->Selected = true;

    if(ui->lineEdit->text() != ""){
        if(ui->lineEdit->text().contains(" ")){
            QString error = "You Name algortmis contais space \n";
            QMessageBox::information(this,"Error",error);

        }else  this->NameAlgo=ui->lineEdit->text();
    }
    else{
        QString error = "You add Name Algortmis to add \n";
        QMessageBox::information(this,"Error",error);
    }

    if(this->NameAlgo != ""){

        QString filename=___pathSmart + "/source/algos/" + NameAlgo + ".c";
        QFile file(filename);

        if ( file.open(QIODevice::ReadWrite) ){
            QTextStream stream( &file );
            stream << ui->textEdit->toPlainText() << endl;
            CompiledCheck=true;
        }else{
            QString error = "Error to save the algortmis \n";
            QMessageBox::information(this,"Error save algortmis",error);
        }

        if(CompiledCheck){

            system("rm logCompiled.txt");
            QString compiledSequenze = "gcc " + filename + " -o " + ___pathSmart + "/source/bin/" + NameAlgo + " 2>logCompiled.txt";
            QByteArray ba = compiledSequenze.toLatin1();
            const char * compiledSequenze2 = ba.data();
            system(compiledSequenze2);

            QFile BinaryCheck(___pathSmart + "/source/bin/" + NameAlgo);

            if(!(BinaryCheck.exists())){

                QFile logFile("logCompiled.txt");

                logFile.open(QIODevice::ReadOnly);
                QByteArray arr = logFile.readAll();

                QString errorText(arr);
                QString error = "Error Compiled \n\n"+errorText;
                QMessageBox::information(this,"Error..!!",error);
                logFile.close();

            }else{


                QString AddSequence = ___pathSmart + "/./select -add " + NameAlgo;
                qDebug()<<AddSequence;
                QByteArray ba = AddSequence.toLatin1();
                const char * AddSequence2 = ba.data();
                ProcAdd = new QProcess(this);

                connect(ProcAdd, SIGNAL(readyReadStandardOutput()), this, SLOT(updateBar()) );

                ProcAdd->setWorkingDirectory(___pathSmart);
                ProcAdd->start(AddSequence2);

            }
        }

    }

}
