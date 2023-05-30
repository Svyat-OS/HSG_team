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

/**
 * @brief Класс сервер с использованием протокола Tcp
 */
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор класса MyTcpServer
     * @param QObject * pointer
     */
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    /**
     * @brief Подключение нового клиента к серверу
     */
    void slotNewConnection();

    /**
     * @brief Отключение клиента от сервера
     */
    void slotClientDisconnected();

    /**
     * @brief Получение сервером сообщений от клиента
     */
    void slotServerRead();
    //void slotReadClient();
private:
    QTcpServer * mTcpServer;
    QMap <qintptr, QTcpSocket*> mTcpSocket;
    int server_status;
};
#endif // MYTCPSERVER_H







