#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <QThread>

MyThread::MyThread()
{
 //    this->Para="-h";
}

MyThread::MyThread(const char* y){
    this->Para=y;
}

void MyThread::SetPara(QString x){
   // this->Para=x;
}

QString MyThread::GetPara(){
    return this->Para;
}


void MyThread::run(){
    //qDebug()<<"test"
    //QString x="./smart -h";
    //system((const char *)x);

    system(this->Para);


}
