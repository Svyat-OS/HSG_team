#include "mainwindow.h"
#include "authwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    authWindow w1;
    w1.show();
    MainWindow w2;
    w2.show();
    return a.exec();
}
