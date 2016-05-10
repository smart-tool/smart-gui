#ifndef ADDALGO_H
#define ADDALGO_H

#include <QDialog>
#include <QProcess>

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
    QProcess* ProcAdd;

private slots:
    void on_pushButton_clicked();
public slots:
    void updateBar();
    void finPro();

private:
    Ui::AddAlgo *ui;
};

#endif // ADDALGO_H
