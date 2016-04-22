#ifndef ADDALGO_H
#define ADDALGO_H

#include <QDialog>

namespace Ui {
class AddAlgo;
}

class AddAlgo : public QDialog
{
    Q_OBJECT

public:
    explicit AddAlgo(QWidget *parent = 0);
    ~AddAlgo();
    bool Selected;
    QString NameAlgo;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddAlgo *ui;
};

#endif // ADDALGO_H
