#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "selectalgwindow.h"
#include <QMessageBox>
#include <QDebug>
//#include <source/smart.h> //Include function libray by SMART.

QString x="Default";
QString Default500= "500";
QString Default1Mb= "1";
QString DefaultTb300= "300";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
 //   ui->centralWidget->setFixedSize(500,500);


    ui->setupUi(this);
//    ui->lineEdit->setReadOnly(true);
//    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setText(Default500);
    ui->lineEdit_4->setText(Default1Mb);
    ui->lineEdit_5->setText(DefaultTb300);
  //  ui->lineEdit->ba
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSelect_algorithms_triggered()
{
    SelectAlgWindow openSelectAlgWin;
    openSelectAlgWin.setModal(true);
    openSelectAlgWin.exec();
}

void MainWindow::on_actionAbout_SMART_GUI_triggered()
{
    const QString help= " This is an help guide for using the tool\n\n -pset N computes running times as the mean of N runs (default 500)\n -tsize S set the upper bound dimension (in Mb) of the text used for experimental results (default 1Mb)\n -plen L U  test only patterns with a length between L and U (included).\n -text F  performs experimental results using text buffer F (mandatory unless you use the -simple parameter)\n -short computes experimental results using short length patterns\n -occ prints the number of occurrences\n -tb L set to L the upper bound for any wort case running time (in ms). The default value is 300 ms\n -dif prints the number the best and the worst running time\n -std prints the standard deviations of the running times\n -txt output results in txt tabular format\n -tex output results in latex tabular format\n -simple P T executes a single run searching T (max 1000 chars) for occurrences of P (max 100 chars)\n \n \n SMART by Faro Simone \n GUI by Alessandro Maggio\nSimone Di Mauro\nStefano Borzi.";
 QMessageBox::information(this,"About!",help);
}

void MainWindow::on_checkBox_released()
{
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

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)
{
    if(arg1!=""){
       ui->lineEdit->setEnabled(false);
       ui->lineEdit_4->setEnabled(false);
       ui->lineEdit_5->setEnabled(false);
       ui->lineEdit_6->setEnabled(false);
       ui->lineEdit_7->setEnabled(false);
       ui->comboBox->setEnabled(false);
       ui->checkBox->setEnabled(false);
    }else if(arg1=="" && ui->lineEdit_9->text()==""){
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->checkBox->setEnabled(true);
    }
}


void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    if(arg1!=""){
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_6->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->checkBox->setEnabled(false);
    }else if(arg1=="" && ui->lineEdit_8->text()==""){
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->checkBox->setEnabled(true);
    }
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    if(arg1!=""){
       ui->checkBox->setEnabled(false);
       ui->lineEdit_8->setEnabled(false);
       ui->lineEdit_9->setEnabled(false);
    }else if(arg1=="" && ui->lineEdit_7->text()==""){
        ui->checkBox->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);
        ui->lineEdit_9->setEnabled(true);
    }
}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    if(arg1!=""){
       ui->checkBox->setEnabled(false);
       ui->lineEdit_8->setEnabled(false);
       ui->lineEdit_9->setEnabled(false);
    }else if(arg1=="" && ui->lineEdit_6->text()==""){
        ui->checkBox->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);
        ui->lineEdit_9->setEnabled(true);
    }
}

void MainWindow::on_pushButton_pressed()
{
    if(ui->lineEdit->text()=="") ui->lineEdit->setText(Default500);
    if(ui->lineEdit_4->text()=="") ui->lineEdit_4->setText(Default1Mb);
    if(ui->lineEdit_5->text()=="") ui->lineEdit_5->setText(DefaultTb300);
}