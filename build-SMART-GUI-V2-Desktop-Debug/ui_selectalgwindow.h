/********************************************************************************
** Form generated from reading UI file 'selectalgwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTALGWINDOW_H
#define UI_SELECTALGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectAlgWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *checkAll_Button;
    QPushButton *uncheckAll_Button;
    QPushButton *update_Button;
    QLabel *labelListAlg;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *SelectAlgWindow)
    {
        if (SelectAlgWindow->objectName().isEmpty())
            SelectAlgWindow->setObjectName(QString::fromUtf8("SelectAlgWindow"));
        SelectAlgWindow->resize(378, 493);
        SelectAlgWindow->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(SelectAlgWindow);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkAll_Button = new QPushButton(SelectAlgWindow);
        checkAll_Button->setObjectName(QString::fromUtf8("checkAll_Button"));
        checkAll_Button->setAutoDefault(false);

        verticalLayout_2->addWidget(checkAll_Button);

        uncheckAll_Button = new QPushButton(SelectAlgWindow);
        uncheckAll_Button->setObjectName(QString::fromUtf8("uncheckAll_Button"));
        uncheckAll_Button->setAutoDefault(false);

        verticalLayout_2->addWidget(uncheckAll_Button);

        update_Button = new QPushButton(SelectAlgWindow);
        update_Button->setObjectName(QString::fromUtf8("update_Button"));
        update_Button->setAutoDefault(false);

        verticalLayout_2->addWidget(update_Button);


        verticalLayout_3->addLayout(verticalLayout_2);

        labelListAlg = new QLabel(SelectAlgWindow);
        labelListAlg->setObjectName(QString::fromUtf8("labelListAlg"));

        verticalLayout_3->addWidget(labelListAlg);

        scrollArea = new QScrollArea(SelectAlgWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 358, 349));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        retranslateUi(SelectAlgWindow);

        QMetaObject::connectSlotsByName(SelectAlgWindow);
    } // setupUi

    void retranslateUi(QDialog *SelectAlgWindow)
    {
        SelectAlgWindow->setWindowTitle(QApplication::translate("SelectAlgWindow", "Select algorithm", 0, QApplication::UnicodeUTF8));
        checkAll_Button->setText(QApplication::translate("SelectAlgWindow", "Check all string matching algorithms", 0, QApplication::UnicodeUTF8));
        uncheckAll_Button->setText(QApplication::translate("SelectAlgWindow", "Uncheck all string matching algorithms", 0, QApplication::UnicodeUTF8));
        update_Button->setText(QApplication::translate("SelectAlgWindow", "Update", 0, QApplication::UnicodeUTF8));
        labelListAlg->setText(QApplication::translate("SelectAlgWindow", "List of all string matching algorithms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectAlgWindow: public Ui_SelectAlgWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTALGWINDOW_H
