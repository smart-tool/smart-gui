#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "selectalgwindow.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
 //   ui->centralWidget->setFixedSize(500,500);
    QString x="Default";
    QString Default500= "500";
    QString Default1Mb= "1Mb";
    QString DefaultTb300= "300";

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
    QMessageBox::information(this,"About!","Alessandro Maggio\nSimone Di Mauro\nStefano Borzi'.");
}

void MainWindow::on_checkBox_released()
{
    if(ui->checkBox->isChecked()){
     ui->lineEdit_6->setEnabled(false);
     ui->lineEdit_7->setEnabled(false);
    }else{
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
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
