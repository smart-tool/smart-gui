#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    // icon
    QIcon icon(":/icon.png");
    w.setWindowIcon(icon);

    w.show();

    return a.exec();
}
