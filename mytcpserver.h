#pragma once
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QWidget>

class QTcpSocket;
class QTcpServer;
class QTextEdit;


class MyServer : public QWidget
{
   Q_OBJECT
   private:
    QTcpServer* m_ptcpServer;
    QTextEdit* m_ptxt;
    quint16 m_nNextBlockSize;
private:
    void sendToClient (QTcpSocket* pSocket, const QString& str);
public:
    MyServer(int nPort, QWidget* pwgt = 0);
public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};
#endif // MYTCPSERVER_H

