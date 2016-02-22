#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T17:42:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUISMART
TEMPLATE = app
CONFIG += console


SOURCES += main.cpp\
        mainwindow.cpp \
    select.cpp

HEADERS  += mainwindow.h \
    select.h

FORMS    += mainwindow.ui \
    select.ui
