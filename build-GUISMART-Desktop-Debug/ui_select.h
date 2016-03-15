/********************************************************************************
** Form generated from reading UI file 'select.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_H
#define UI_SELECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selezione
{
public:
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Selezione)
    {
        if (Selezione->objectName().isEmpty())
            Selezione->setObjectName(QString::fromUtf8("Selezione"));
        Selezione->resize(693, 384);
        pushButton = new QPushButton(Selezione);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 110, 141, 71));
        scrollArea = new QScrollArea(Selezione);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(9, 18, 241, 261));
        scrollArea->setWidgetResizable(true);
        scrollContents = new QWidget();
        scrollContents->setObjectName(QString::fromUtf8("scrollContents"));
        scrollContents->setGeometry(QRect(0, 0, 237, 257));
        scrollArea->setWidget(scrollContents);
        pushButton_2 = new QPushButton(Selezione);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 300, 91, 27));
        pushButton->raise();
        scrollArea->raise();
        pushButton_2->raise();

        retranslateUi(Selezione);

        QMetaObject::connectSlotsByName(Selezione);
    } // setupUi

    void retranslateUi(QDialog *Selezione)
    {
        Selezione->setWindowTitle(QApplication::translate("Selezione", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Selezione", "Mostra Selezionati", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Selezione", "Aggiorna", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Selezione: public Ui_Selezione {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_H
