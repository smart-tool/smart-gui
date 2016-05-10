#include "setupwindow.h"
#include "ui_setupwindow.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

QString _pathSmartGUI = QDir::homePath() + "/smartGUI";
QString _pathSmart = _pathSmartGUI + "/smartSource";

QString sourceDirectory;

bool copyPath(QString sourceDir, QString destinationDir, bool overWriteDirectory) {
    QDir originDirectory(sourceDir);

    if (! originDirectory.exists())
        return false;

    QDir destinationDirectory(destinationDir);

    if(destinationDirectory.exists() && !overWriteDirectory)
        return false;
    else if(destinationDirectory.exists() && overWriteDirectory)
        destinationDirectory.removeRecursively();

    originDirectory.mkpath(destinationDir);

    foreach (QString directoryName, originDirectory.entryList(QDir::Dirs | \
                                                              QDir::NoDotAndDotDot)) {

        QString destinationPath = destinationDir + "/" + directoryName;
        originDirectory.mkpath(destinationPath);
        copyPath(sourceDir + "/" + directoryName, destinationPath, overWriteDirectory);
    }

    foreach (QString fileName, originDirectory.entryList(QDir::Files)) {
        QFile::copy(sourceDir + "/" + fileName, destinationDir + "/" + fileName);
    }

    /*! Possible race-condition mitigation? */
    QDir finalDestination(destinationDir);
    finalDestination.refresh();

    if(finalDestination.exists())
        return true;

    return false;
}

setupWindow::setupWindow(QWidget *parent) :QDialog(parent),ui(new Ui::setupWindow){
    ui->setupUi(this);

    ui->folder_label->setText(_pathSmart);

    if(QDir(_pathSmart).exists()){
        ui->info_label->setText("The folder exists.");
        ui->info_label->setStyleSheet( "color: green ;");
    }else{
        ui->info_label->setText("The folder does not exist.\nCopy it manually or use this window.");
        ui->info_label->setStyleSheet( "color: red ;");
    }
}

setupWindow::~setupWindow(){
    delete ui;
}

void setupWindow::on_chooseFolder_pushButton_clicked(){

    QFileDialog dialog(this, tr("Choose folder"), QDir::homePath());
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setLabelText(QFileDialog::Accept, "Choose folder");

    if(dialog.exec())
        sourceDirectory = dialog.selectedFiles().at(0);

}

void setupWindow::on_save_pushButton_clicked(){

    if (sourceDirectory != ""){
        bool status = copyPath(sourceDirectory, _pathSmart, true);

        if (status)
            QMessageBox::information(this,"Done!","Folder copied successfully!");
        else
            QMessageBox::critical(this,"Error!","Error to copy folder!");


        if(QDir(_pathSmart).exists()){
            ui->info_label->setText("The folder exists.");
            ui->info_label->setStyleSheet( "color: green ;");
        }else{
            ui->info_label->setText("The folder does not exist.\nCopy it manually or use this window.");
            ui->info_label->setStyleSheet( "color: red ;");
        }
    }else
        QMessageBox::critical(this,"Error!","First choose a folder!");

}
