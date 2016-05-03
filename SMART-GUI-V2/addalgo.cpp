#include "addalgo.h"
#include "ui_addalgo.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QProcess>


AddAlgo::AddAlgo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlgo)
{
    ui->setupUi(this);
    ui->textEdit->setText("#include \"include/main.h\"\n\n //ADD YOUR CODE HERE \n\n //FOR MORE INFO FOR ADD ALGORTHIMS VISIT http://www.dmi.unict.it/~faro/smart/howto.php?id=18 \n\n");
    this->Selected=false;
    this->NameAlgo="";
}

AddAlgo::~AddAlgo()
{
    delete ui;
}

void AddAlgo::updateBar(){
   // qDebug()<< ProcAdd->readAllStandardOutput();


    QString tmpOutput2 = ProcAdd->readAllStandardOutput().replace("\b","");
    tmpOutput2=tmpOutput2.replace("%]","");
    tmpOutput2=tmpOutput2.replace("[0","");
    tmpOutput2=tmpOutput2.replace("[00","");
    ui->progressBar->setValue(tmpOutput2.toInt());

    if(tmpOutput2.contains("ok")) finPro();

}

void AddAlgo::finPro(){

    if(this->Selected){

        QString SelectSequence="./select "+NameAlgo;
        QByteArray ba=SelectSequence.toLatin1();
        const char * SelectSequence2= ba.data();
      //  system(SelectSequence2);
        delete ProcAdd;
        ProcAdd= new QProcess(this);
        ProcAdd->setWorkingDirectory("smartSource");
        ProcAdd->start(SelectSequence2);
        QString error="Algortmhs add and select \n\n";
        QMessageBox::information(this,"ADD and Select",error);

    }else {

        QString error="Algortmhs add \n\n";
        QMessageBox::information(this,"ADD",error);

    }

}

void AddAlgo::on_pushButton_clicked()
{

    bool CompiledCheck=false;
    this->NameAlgo="";
    this->Selected=false;
    if(ui->checkBox->isChecked()) this->Selected=true;
    if(ui->lineEdit->text()!="") this->NameAlgo=ui->lineEdit->text();
    else{
        QString error="You add Name Algortmis to add \n";
         QMessageBox::information(this,"Error..!!",error);

    }

    if(this->NameAlgo!=""){

        QString filename="smartSource/source/algos/"+NameAlgo+".c";
        QFile file(filename);
        if ( file.open(QIODevice::ReadWrite) ){
            QTextStream stream( &file );
            stream << ui->textEdit->toPlainText() << endl;
            CompiledCheck=true;
        }else{
            QString error="Error to save the algortmis \n";
             QMessageBox::information(this,"Error..!!",error);
        }

        if(CompiledCheck){
            system("rm logCompiled.txt");
            QString compiledSequenze="gcc "+filename+" -o "+"smartSource/source/bin/"+NameAlgo+" 2>logCompiled.txt";
            QByteArray ba=compiledSequenze.toLatin1();
            const char * compiledSequenze2= ba.data();
            system(compiledSequenze2);

            QFile BinaryCheck("smartSource/source/bin/"+NameAlgo);
            if(!(BinaryCheck.exists())){
                    QFile logFile("logCompiled.txt");


                    logFile.open(QIODevice::ReadOnly);
                    QByteArray arr= logFile.readAll();

                    QString errorText(arr);
                    QString error="Error Compiled \n\n"+errorText;
                    QMessageBox::information(this,"Error..!!",error);
                    logFile.close();
            }else{
                 //   system("cd smartSource/");

                    QString AddSequence="./select -add "+NameAlgo;
                    QByteArray ba=AddSequence.toLatin1();
                    const char * AddSequence2= ba.data();
                    ProcAdd= new QProcess(this);

                    connect(ProcAdd, SIGNAL(readyReadStandardOutput()), this, SLOT(updateBar()) );
               //     connect(ProcAdd, SIGNAL(finished(int)), this, SLOT(finPro()) );

                    ProcAdd->setWorkingDirectory("smartSource");
                    ProcAdd->start(AddSequence2);

                   //AGGIUNGERE LA FUNZIONE SLOT(GUARDARE UPDATEGUI)
                    //AGGIUNGERE IL CONNECT GUARDA MAINWINDOW


                    //system(AddSequence2);
                    //system("ls");

/*
                    if(this->Selected){

                        QString SelectSequence="./select "+NameAlgo;
                        QByteArray ba=SelectSequence.toLatin1();
                        const char * SelectSequence2= ba.data();
                        system(SelectSequence2);
                        QString error="Algortmhs add and select \n\n";
                        QMessageBox::information(this,"ADD and Select",error);

                    }else {

                        QString error="Algortmhs add \n\n";
                        QMessageBox::information(this,"ADD",error);

                    }

*/



            }
        }

    }


}
