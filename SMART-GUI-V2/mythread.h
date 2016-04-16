#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>


class MyThread : public QThread {

public:
    MyThread();
    MyThread(const char* y);
    const char* Para;
    void run();
    void SetPara(QString x);
    QString GetPara();
};

#endif // MYTHREAD_H
