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

    void loadChart();

private slots:
    void on_actionSelect_algorithms_triggered();
    void on_actionAbout_SMART_GUI_triggered();
    void on_checkBox_released();
    void on_lineEdit_8_textChanged(const QString &arg1);
    void on_lineEdit_9_textChanged(const QString &arg1);
    void on_lineEdit_6_textChanged(const QString &arg1);
    void on_lineEdit_7_textChanged(const QString &arg1);
    void on_pushButton_pressed();
    void on_pushButton_released();

public slots:
    void updateGUI();
    void processEnded();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
