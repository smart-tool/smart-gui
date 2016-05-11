#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class aboutWindow;
}

class aboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit aboutWindow(QWidget *parent = 0);
    ~aboutWindow();

private:
    Ui::aboutWindow *ui;
};

#endif // ABOUTWINDOW_H
