#ifndef SELEZIONE_H
#define SELEZIONE_H

#include <QDialog>

namespace Ui {
class Selezione;
}

class Selezione : public QDialog
{
    Q_OBJECT

public:
    explicit Selezione(QWidget *parent = 0);
    ~Selezione();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Selezione *ui;
};

#endif // SELEZIONE_H
