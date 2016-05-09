/********************************************************************************
** Form generated from reading UI file 'addalgo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDALGO_H
#define UI_ADDALGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAlgo
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *textEdit;
    QProgressBar *progressBar;

    void setupUi(QDialog *AddAlgo)
    {
        if (AddAlgo->objectName().isEmpty())
            AddAlgo->setObjectName(QStringLiteral("AddAlgo"));
        AddAlgo->resize(786, 426);
        gridLayout = new QGridLayout(AddAlgo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddAlgo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(AddAlgo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        checkBox = new QCheckBox(AddAlgo);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        pushButton = new QPushButton(AddAlgo);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea = new QScrollArea(AddAlgo);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 766, 340));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(3, 4, 761, 361));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 2, 0, 1, 1);

        progressBar = new QProgressBar(AddAlgo);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);


        retranslateUi(AddAlgo);

        QMetaObject::connectSlotsByName(AddAlgo);
    } // setupUi

    void retranslateUi(QDialog *AddAlgo)
    {
        AddAlgo->setWindowTitle(QApplication::translate("AddAlgo", "Add algorithm", 0));
        label->setText(QApplication::translate("AddAlgo", "Name Algorthms", 0));
        checkBox->setText(QApplication::translate("AddAlgo", "Select ?", 0));
        pushButton->setText(QApplication::translate("AddAlgo", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAlgo: public Ui_AddAlgo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDALGO_H
