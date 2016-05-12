#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createChart();
    void inizializeAll();

private slots:
    void on_actionSelect_algorithms_triggered();
    void on_actionAbout_SMART_GUI_triggered();

    void on_Short_checkBox_released();

    void on_SimpleP_lineEdit_textChanged(const QString &arg1);
    void on_SimpleT_lineEdit_textChanged(const QString &arg1);
    void on_PlenU_lineEdit_textChanged(const QString &arg1);
    void on_PlenL_lineEdit_textChanged(const QString &arg1);

    void on_start_pushButton_pressed();
    void on_start_pushButton_released();

    void on_stop_pushButton_released();

    void on_actionAdd_Algorithms_triggered();
    void on_actionSetup_SMART_GUI_triggered();

    void on_AllCheckBox_clicked();

public slots:
    void runProcess();
    void updateGUI();
    void processEnded();
    void showResultFunction();
    void printPDF();


    QString createHeadEXP();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
