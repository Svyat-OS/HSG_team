#include "mytcpserver.h"
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    MyServer server(2323);
    server.show();

    return a.exec();
}
