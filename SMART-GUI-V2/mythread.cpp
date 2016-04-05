#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <QThread>

MyThread::MyThread()
{

}

void MyThread::run(){
    //qDebug()<<"test"
    //QString x="./smart -h";
    //system((const char *)x);

    system("./smart -text rand2");


}
