#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QDialog>

namespace Ui {
class setupWindow;
}

class setupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit setupWindow(QWidget *parent = 0);
    ~setupWindow();

private slots:
    void on_chooseFolder_pushButton_clicked();

    void on_save_pushButton_clicked();

private:
    Ui::setupWindow *ui;
};

#endif // SETUPWINDOW_H
