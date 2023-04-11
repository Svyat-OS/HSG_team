#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QString>
#include <QMap>
#include "func_for_server.h"  // подключаем класс функций


class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();
private:
    QTcpServer * mTcpServer;
    QMap <qintptr, QTcpSocket*> mTcpSocket;
    int server_status;
};
#endif // MYTCPSERVER_H







