#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "selectalgwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
