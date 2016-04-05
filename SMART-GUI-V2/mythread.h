#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>


class MyThread : public QThread
{
public:
    MyThread();
    void run();
};

#endif // MYTHREAD_H
