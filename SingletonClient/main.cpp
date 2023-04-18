#include <QCoreApplication>
#include "singletonclient.h"
//#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Singleton::getInstance()->slotsendMessage("Hello!");

    return a.exec();
}
