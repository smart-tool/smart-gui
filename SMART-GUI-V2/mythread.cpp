#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <QThread>

QProcess *myProcess;

MyThread::MyThread(){

}

MyThread::MyThread(const char* y){
    this->Para=y;
    myProcess = new QProcess(this);
}

void MyThread::SetPara(QString x){

}

QString MyThread::GetPara(){
    return this->Para;
}


void MyThread::run(){
    myProcess->start(this->Para);
    //qDebug() << myProcess->pid();
    //system(this->Para);
}

void MyThread::stop(){
    myProcess->kill();
}
