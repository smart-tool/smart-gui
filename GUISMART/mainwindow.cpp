#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "select.h"
#include <QDebug>
#include <cstdlib>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<< ui->comboBox->currentIndex();
//    system("./smart -text all");
}

void MainWindow::on_actionSeleziona_algortmi_triggered()
{
        Selezione select;
        select.setModal(true);
        select.exec();
}
