/********************************************************************************
** Form generated from reading UI file 'setupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPWINDOW_H
#define UI_SETUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setupWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *info_label;
    QLabel *folder_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *chooseFolder_pushButton;
    QPushButton *save_pushButton;

    void setupUi(QDialog *setupWindow)
    {
        if (setupWindow->objectName().isEmpty())
            setupWindow->setObjectName(QStringLiteral("setupWindow"));
        setupWindow->resize(415, 135);
        verticalLayout_2 = new QVBoxLayout(setupWindow);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        info_label = new QLabel(setupWindow);
        info_label->setObjectName(QStringLiteral("info_label"));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        info_label->setFont(font);
        info_label->setLayoutDirection(Qt::LeftToRight);
        info_label->setAutoFillBackground(false);

        verticalLayout->addWidget(info_label);

        folder_label = new QLabel(setupWindow);
        folder_label->setObjectName(QStringLiteral("folder_label"));

        verticalLayout->addWidget(folder_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chooseFolder_pushButton = new QPushButton(setupWindow);
        chooseFolder_pushButton->setObjectName(QStringLiteral("chooseFolder_pushButton"));

        horizontalLayout->addWidget(chooseFolder_pushButton);

        save_pushButton = new QPushButton(setupWindow);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));

        horizontalLayout->addWidget(save_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(setupWindow);

        QMetaObject::connectSlotsByName(setupWindow);
    } // setupUi

    void retranslateUi(QDialog *setupWindow)
    {
        setupWindow->setWindowTitle(QApplication::translate("setupWindow", "Setup", 0));
        info_label->setText(QApplication::translate("setupWindow", "info", 0));
        folder_label->setText(QApplication::translate("setupWindow", "folder", 0));
        chooseFolder_pushButton->setText(QApplication::translate("setupWindow", "Choose folder", 0));
        save_pushButton->setText(QApplication::translate("setupWindow", "Save!", 0));
    } // retranslateUi

};

namespace Ui {
    class setupWindow: public Ui_setupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPWINDOW_H
