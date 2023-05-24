#include "mainwindow.h"
#include "singletonclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Singleton::getInstance()->slotconnected();
    MainWindow w;
    w.show();
    return a.exec();
}
