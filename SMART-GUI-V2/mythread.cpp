#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <QThread>

MyThread::MyThread(){

}

MyThread::MyThread(const char* y){
    this->Para=y;
}

void MyThread::SetPara(QString x){

}

QString MyThread::GetPara(){
    return this->Para;
}


void MyThread::run(){
    system(this->Para);
}
