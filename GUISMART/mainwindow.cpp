#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    system("./a.out");
}
