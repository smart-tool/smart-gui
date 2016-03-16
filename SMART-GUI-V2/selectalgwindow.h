#ifndef SELECTALGWINDOW_H
#define SELECTALGWINDOW_H

#include <QDialog>

namespace Ui {
class SelectAlgWindow;
}

class SelectAlgWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SelectAlgWindow(QWidget *parent = 0);
    ~SelectAlgWindow();

private slots:


    void on_checkAll_Button_clicked();

    void on_uncheckAll_Button_clicked();

    void on_update_Button_clicked();

private:
    Ui::SelectAlgWindow *ui;
};

#endif // SELECTALGWINDOW_H
