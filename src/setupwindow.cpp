#include "setupwindow.h"
#include "ui_setupwindow.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

QString _pathSmartGUI = QDir::currentPath() + "/smartGUI";
QString _pathSmart = "";

QFile pathSmartFile(_pathSmartGUI + "/pathSource.conf");

QString sourceDirectory;

setupWindow::setupWindow(QWidget *parent) :QDialog(parent),ui(new Ui::setupWindow){
    ui->setupUi(this);

    if(pathSmartFile.exists()){
        if (pathSmartFile.open(QIODevice::ReadOnly)) {
            QTextStream in(&pathSmartFile);
            _pathSmart = in.readAll();
            pathSmartFile.close();
        }
    }

    if(_pathSmart == ""){
        ui->folder_label->setStyleSheet( "color: red ;");
        ui->folder_label->setText("The SMART folder is not setted.");
    }else{
        QFile SmartCheck(_pathSmart + "/smart");
        QFile SelectCheck(_pathSmart + "/select");
        QFile TestCheck(_pathSmart + "/test");
        if (! (SmartCheck.exists() && SelectCheck.exists() && TestCheck.exists() ) ){
            ui->folder_label->setStyleSheet( "color: red ;");
            ui->folder_label->setText("Current folder: " + _pathSmart);
        }else{
            ui->folder_label->setStyleSheet( "color: green ;");
            ui->folder_label->setText("Current folder: " + _pathSmart);
        }
    }

}

setupWindow::~setupWindow(){
    delete ui;
}

void setupWindow::on_chooseFolder_pushButton_clicked(){

    QFileDialog dialog(this, tr("Choose folder"), QDir::homePath());
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setLabelText(QFileDialog::Accept, "Choose folder");

    if(dialog.exec()){
        sourceDirectory = dialog.selectedFiles().at(0);
        ui->newFolder_label->setText("New folder: " + sourceDirectory);
    }

}

void setupWindow::on_save_pushButton_clicked(){

    if (sourceDirectory != ""){
        QFile SmartCheck(sourceDirectory + "/smart");
        QFile SelectCheck(sourceDirectory + "/select");
        QFile TestCheck(sourceDirectory + "/test");

        if (SmartCheck.exists() && SelectCheck.exists() && TestCheck.exists()){

            QDir dirGUI(_pathSmartGUI);
            if(!(dirGUI.exists()))
                dirGUI.mkdir(_pathSmartGUI);

            if (pathSmartFile.open(QFile::WriteOnly|QFile::Truncate)) {
                QTextStream stream(&pathSmartFile);
                stream << sourceDirectory;
            }

            ui->folder_label->setStyleSheet( "color: green ;");
            ui->folder_label->setText("Current folder: " + sourceDirectory);

            ui->newFolder_label->setText("");

            QMessageBox::information(this,"Done!","Folder setted successfully!\nRestart SMART-GUI to enable changes.");
        }else
            QMessageBox::critical(this,"Error!","The selected folder not contains SMART!");
    }else
        QMessageBox::critical(this,"Error!","First choose a folder!");

}
