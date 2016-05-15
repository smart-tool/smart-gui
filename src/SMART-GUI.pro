#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T23:48:51
#
#-------------------------------------------------

QT       += core gui webkit widgets printsupport

# greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMART-GUI
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp \
           selectalgwindow.cpp \
           addalgo.cpp \
           setupwindow.cpp \
    aboutwindow.cpp

HEADERS += mainwindow.h \
           selectalgwindow.h \
           addalgo.h \
           setupwindow.h \
    aboutwindow.h

FORMS   += mainwindow.ui \
           selectalgwindow.ui \
           addalgo.ui \
           setupwindow.ui \
    aboutwindow.ui

RESOURCES += \
           chartfile.qrc \
           icon.qrc
