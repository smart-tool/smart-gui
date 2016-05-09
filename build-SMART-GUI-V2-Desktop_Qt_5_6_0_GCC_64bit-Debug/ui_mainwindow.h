/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_algorithms;
    QAction *actionAbout_SMART_GUI;
    QAction *actionAdd_Algorithms;
    QAction *actionSetup_SMART_GUI;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *Pset_label;
    QLabel *Tsize_label;
    QLabel *PlenU_label;
    QLineEdit *Tsize_lineEdit;
    QLabel *Tb_label;
    QLineEdit *Tb_lineEdit;
    QLineEdit *SimpleT_lineEdit;
    QLineEdit *SimpleP_lineEdit;
    QLineEdit *PlenL_lineEdit;
    QLabel *SimpleT_label;
    QLabel *SimpleP_label;
    QLabel *PlenL_label;
    QLineEdit *Pset_lineEdit;
    QLineEdit *PlenU_lineEdit;
    QCheckBox *Short_checkBox;
    QCheckBox *Occ_checkBox;
    QCheckBox *Dif_checkBox;
    QCheckBox *Std_checkBox;
    QCheckBox *Txt_checkBox;
    QCheckBox *Tex_checkBox;
    QCheckBox *Pre_checkBox;
    QLabel *label;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *start_pushButton;
    QPushButton *stop_pushButton;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1255, 774);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionSelect_algorithms = new QAction(MainWindow);
        actionSelect_algorithms->setObjectName(QStringLiteral("actionSelect_algorithms"));
        actionAbout_SMART_GUI = new QAction(MainWindow);
        actionAbout_SMART_GUI->setObjectName(QStringLiteral("actionAbout_SMART_GUI"));
        actionAdd_Algorithms = new QAction(MainWindow);
        actionAdd_Algorithms->setObjectName(QStringLiteral("actionAdd_Algorithms"));
        actionSetup_SMART_GUI = new QAction(MainWindow);
        actionSetup_SMART_GUI->setObjectName(QStringLiteral("actionSetup_SMART_GUI"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        Pset_label = new QLabel(centralWidget);
        Pset_label->setObjectName(QStringLiteral("Pset_label"));
        Pset_label->setMaximumSize(QSize(16777215, 60));
        Pset_label->setLayoutDirection(Qt::LeftToRight);
        Pset_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Pset_label, 0, 0, 1, 1);

        Tsize_label = new QLabel(centralWidget);
        Tsize_label->setObjectName(QStringLiteral("Tsize_label"));
        Tsize_label->setMaximumSize(QSize(16777215, 60));
        Tsize_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Tsize_label, 0, 1, 1, 1);

        PlenU_label = new QLabel(centralWidget);
        PlenU_label->setObjectName(QStringLiteral("PlenU_label"));
        PlenU_label->setMaximumSize(QSize(16777215, 60));
        PlenU_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PlenU_label, 0, 3, 1, 1);

        Tsize_lineEdit = new QLineEdit(centralWidget);
        Tsize_lineEdit->setObjectName(QStringLiteral("Tsize_lineEdit"));

        gridLayout->addWidget(Tsize_lineEdit, 1, 1, 1, 1);

        Tb_label = new QLabel(centralWidget);
        Tb_label->setObjectName(QStringLiteral("Tb_label"));
        Tb_label->setMaximumSize(QSize(16777215, 60));
        Tb_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Tb_label, 0, 2, 1, 1);

        Tb_lineEdit = new QLineEdit(centralWidget);
        Tb_lineEdit->setObjectName(QStringLiteral("Tb_lineEdit"));

        gridLayout->addWidget(Tb_lineEdit, 1, 2, 1, 1);

        SimpleT_lineEdit = new QLineEdit(centralWidget);
        SimpleT_lineEdit->setObjectName(QStringLiteral("SimpleT_lineEdit"));
        SimpleT_lineEdit->setMaxLength(100);

        gridLayout->addWidget(SimpleT_lineEdit, 1, 6, 1, 1);

        SimpleP_lineEdit = new QLineEdit(centralWidget);
        SimpleP_lineEdit->setObjectName(QStringLiteral("SimpleP_lineEdit"));
        SimpleP_lineEdit->setMaxLength(1000);

        gridLayout->addWidget(SimpleP_lineEdit, 1, 5, 1, 1);

        PlenL_lineEdit = new QLineEdit(centralWidget);
        PlenL_lineEdit->setObjectName(QStringLiteral("PlenL_lineEdit"));

        gridLayout->addWidget(PlenL_lineEdit, 1, 4, 1, 1);

        SimpleT_label = new QLabel(centralWidget);
        SimpleT_label->setObjectName(QStringLiteral("SimpleT_label"));
        SimpleT_label->setMaximumSize(QSize(16777215, 60));
        SimpleT_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(SimpleT_label, 0, 6, 1, 1);

        SimpleP_label = new QLabel(centralWidget);
        SimpleP_label->setObjectName(QStringLiteral("SimpleP_label"));
        SimpleP_label->setMaximumSize(QSize(16777215, 60));
        SimpleP_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(SimpleP_label, 0, 5, 1, 1);

        PlenL_label = new QLabel(centralWidget);
        PlenL_label->setObjectName(QStringLiteral("PlenL_label"));
        PlenL_label->setMaximumSize(QSize(16777215, 60));
        PlenL_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PlenL_label, 0, 4, 1, 1);

        Pset_lineEdit = new QLineEdit(centralWidget);
        Pset_lineEdit->setObjectName(QStringLiteral("Pset_lineEdit"));

        gridLayout->addWidget(Pset_lineEdit, 1, 0, 1, 1);

        PlenU_lineEdit = new QLineEdit(centralWidget);
        PlenU_lineEdit->setObjectName(QStringLiteral("PlenU_lineEdit"));

        gridLayout->addWidget(PlenU_lineEdit, 1, 3, 1, 1);

        Short_checkBox = new QCheckBox(centralWidget);
        Short_checkBox->setObjectName(QStringLiteral("Short_checkBox"));
        Short_checkBox->setChecked(false);

        gridLayout->addWidget(Short_checkBox, 2, 0, 1, 1);

        Occ_checkBox = new QCheckBox(centralWidget);
        Occ_checkBox->setObjectName(QStringLiteral("Occ_checkBox"));

        gridLayout->addWidget(Occ_checkBox, 2, 1, 1, 1);

        Dif_checkBox = new QCheckBox(centralWidget);
        Dif_checkBox->setObjectName(QStringLiteral("Dif_checkBox"));

        gridLayout->addWidget(Dif_checkBox, 2, 2, 1, 1);

        Std_checkBox = new QCheckBox(centralWidget);
        Std_checkBox->setObjectName(QStringLiteral("Std_checkBox"));

        gridLayout->addWidget(Std_checkBox, 2, 3, 1, 1);

        Txt_checkBox = new QCheckBox(centralWidget);
        Txt_checkBox->setObjectName(QStringLiteral("Txt_checkBox"));
        Txt_checkBox->setChecked(true);
        Txt_checkBox->setTristate(false);

        gridLayout->addWidget(Txt_checkBox, 2, 4, 1, 1);

        Tex_checkBox = new QCheckBox(centralWidget);
        Tex_checkBox->setObjectName(QStringLiteral("Tex_checkBox"));
        Tex_checkBox->setChecked(true);

        gridLayout->addWidget(Tex_checkBox, 2, 5, 1, 1);

        Pre_checkBox = new QCheckBox(centralWidget);
        Pre_checkBox->setObjectName(QStringLiteral("Pre_checkBox"));

        gridLayout->addWidget(Pre_checkBox, 2, 6, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 3, 2, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 3, 1, 1, 1);

        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 3, 3, 1, 1);

        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout->addWidget(checkBox_4, 3, 4, 1, 1);

        checkBox_5 = new QCheckBox(centralWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        gridLayout->addWidget(checkBox_5, 3, 5, 1, 1);

        checkBox_6 = new QCheckBox(centralWidget);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        gridLayout->addWidget(checkBox_6, 3, 6, 1, 1);

        checkBox_7 = new QCheckBox(centralWidget);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        gridLayout->addWidget(checkBox_7, 4, 0, 1, 1);

        checkBox_8 = new QCheckBox(centralWidget);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        gridLayout->addWidget(checkBox_8, 4, 1, 1, 1);

        checkBox_9 = new QCheckBox(centralWidget);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        gridLayout->addWidget(checkBox_9, 4, 2, 1, 1);

        checkBox_10 = new QCheckBox(centralWidget);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        gridLayout->addWidget(checkBox_10, 4, 3, 1, 1);

        checkBox_11 = new QCheckBox(centralWidget);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));

        gridLayout->addWidget(checkBox_11, 4, 4, 1, 1);

        checkBox_12 = new QCheckBox(centralWidget);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));

        gridLayout->addWidget(checkBox_12, 4, 5, 1, 1);

        checkBox_13 = new QCheckBox(centralWidget);
        checkBox_13->setObjectName(QStringLiteral("checkBox_13"));

        gridLayout->addWidget(checkBox_13, 4, 6, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        start_pushButton = new QPushButton(centralWidget);
        start_pushButton->setObjectName(QStringLiteral("start_pushButton"));
        start_pushButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(start_pushButton);

        stop_pushButton = new QPushButton(centralWidget);
        stop_pushButton->setObjectName(QStringLiteral("stop_pushButton"));
        stop_pushButton->setEnabled(false);

        horizontalLayout->addWidget(stop_pushButton);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(Pset_lineEdit, Tsize_lineEdit);
        QWidget::setTabOrder(Tsize_lineEdit, Tb_lineEdit);
        QWidget::setTabOrder(Tb_lineEdit, PlenU_lineEdit);
        QWidget::setTabOrder(PlenU_lineEdit, PlenL_lineEdit);
        QWidget::setTabOrder(PlenL_lineEdit, SimpleP_lineEdit);
        QWidget::setTabOrder(SimpleP_lineEdit, SimpleT_lineEdit);

        mainToolBar->addAction(actionSelect_algorithms);
        mainToolBar->addAction(actionAdd_Algorithms);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSetup_SMART_GUI);
        mainToolBar->addAction(actionAbout_SMART_GUI);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SMART-GUI", 0));
        actionSelect_algorithms->setText(QApplication::translate("MainWindow", "Select algorithms", 0));
        actionAbout_SMART_GUI->setText(QApplication::translate("MainWindow", "About SMART-GUI", 0));
        actionAdd_Algorithms->setText(QApplication::translate("MainWindow", "Add algorithms", 0));
        actionSetup_SMART_GUI->setText(QApplication::translate("MainWindow", "Setup SMART-GUI", 0));
#ifndef QT_NO_TOOLTIP
        actionSetup_SMART_GUI->setToolTip(QApplication::translate("MainWindow", "Setup SMART-GUI", 0));
#endif // QT_NO_TOOLTIP
        Pset_label->setText(QApplication::translate("MainWindow", "Pset", 0));
        Tsize_label->setText(QApplication::translate("MainWindow", "Tsize (Mb)", 0));
        PlenU_label->setText(QApplication::translate("MainWindow", "Plen U", 0));
        Tb_label->setText(QApplication::translate("MainWindow", "Tb", 0));
        SimpleT_label->setText(QApplication::translate("MainWindow", "Simple T ", 0));
        SimpleP_label->setText(QApplication::translate("MainWindow", "Simple P ", 0));
        PlenL_label->setText(QApplication::translate("MainWindow", "Plen L", 0));
        Short_checkBox->setText(QApplication::translate("MainWindow", "Short", 0));
        Occ_checkBox->setText(QApplication::translate("MainWindow", "Occ", 0));
        Dif_checkBox->setText(QApplication::translate("MainWindow", "Dif", 0));
        Std_checkBox->setText(QApplication::translate("MainWindow", "Std", 0));
        Txt_checkBox->setText(QApplication::translate("MainWindow", "Txt", 0));
        Tex_checkBox->setText(QApplication::translate("MainWindow", "Tex", 0));
        Pre_checkBox->setText(QApplication::translate("MainWindow", "Pre", 0));
        label->setText(QApplication::translate("MainWindow", "Text:", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "englishTexts", 0));
        checkBox->setText(QApplication::translate("MainWindow", "all", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "italianTexts", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "genome", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "protein", 0));
        checkBox_6->setText(QApplication::translate("MainWindow", "rand2", 0));
        checkBox_7->setText(QApplication::translate("MainWindow", "rand4", 0));
        checkBox_8->setText(QApplication::translate("MainWindow", "rand8", 0));
        checkBox_9->setText(QApplication::translate("MainWindow", "rand16", 0));
        checkBox_10->setText(QApplication::translate("MainWindow", "rand32", 0));
        checkBox_11->setText(QApplication::translate("MainWindow", "rand64", 0));
        checkBox_12->setText(QApplication::translate("MainWindow", "rand128", 0));
        checkBox_13->setText(QApplication::translate("MainWindow", "rand250", 0));
        start_pushButton->setText(QApplication::translate("MainWindow", "Start S.M.A.R.T", 0));
        stop_pushButton->setText(QApplication::translate("MainWindow", "Stop S.M.A.R.T", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
