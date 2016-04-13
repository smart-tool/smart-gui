/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_algorithms;
    QAction *actionAbout_SMART_GUI;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_9;
    QLabel *label_8;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(764, 276);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionSelect_algorithms = new QAction(MainWindow);
        actionSelect_algorithms->setObjectName(QString::fromUtf8("actionSelect_algorithms"));
        actionAbout_SMART_GUI = new QAction(MainWindow);
        actionAbout_SMART_GUI->setObjectName(QString::fromUtf8("actionAbout_SMART_GUI"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 4, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 5, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 1, 3, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 7, 1, 1);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 1, 4, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 7, 1, 1);

        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setMaxLength(1000);

        gridLayout->addWidget(lineEdit_8, 1, 5, 1, 1);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 1, 2, 1, 1);

        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setMaxLength(100);

        gridLayout->addWidget(lineEdit_9, 1, 6, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 6, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox_6 = new QCheckBox(centralWidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setChecked(true);

        gridLayout_2->addWidget(checkBox_6, 0, 5, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(false);

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 0, 3, 1, 1);

        checkBox_5 = new QCheckBox(centralWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setChecked(true);
        checkBox_5->setTristate(false);

        gridLayout_2->addWidget(checkBox_5, 0, 4, 1, 1);

        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(pushButton);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 764, 27));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, lineEdit_8);
        QWidget::setTabOrder(lineEdit_8, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, comboBox);
        QWidget::setTabOrder(comboBox, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_5);
        QWidget::setTabOrder(checkBox_5, checkBox_6);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionSelect_algorithms);
        menuOptions->addAction(actionAbout_SMART_GUI);
        mainToolBar->addAction(actionSelect_algorithms);
        mainToolBar->addAction(actionAbout_SMART_GUI);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SMART-GUI", 0, QApplication::UnicodeUTF8));
        actionSelect_algorithms->setText(QApplication::translate("MainWindow", "Select algorithms", 0, QApplication::UnicodeUTF8));
        actionAbout_SMART_GUI->setText(QApplication::translate("MainWindow", "About SMART-GUI", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Plen L", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Plen U", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Simple P ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Tb", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "all", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "EnglishTexts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ItalianTexts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Genone", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Protein", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand128", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rand250", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Pset", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Tsize (Mb)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Simple T ", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Short", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "Occ", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("MainWindow", "Std", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MainWindow", "Txt", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindow", "Dif", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Start S.M.A.R.T", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
