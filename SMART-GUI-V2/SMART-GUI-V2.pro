#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T23:48:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMART-GUI-V2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    selectalgwindow.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    selectalgwindow.h \
    mythread.h

FORMS    += mainwindow.ui \
    selectalgwindow.ui
