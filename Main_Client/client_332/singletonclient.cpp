#include "singletonclient.h"
#include "mainwindow.h"

Singleton::Singleton(QObject * parent):QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    m_pTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotconnected()));
    //connect(m_pTcpSocket, SIGNAL(readyRead()), this,SLOT(slotReadyRead()));
}

void Singleton::slotsendMessage(QString str)
{
    {
       // qDebug()<<str<<"send";
        m_pTcpSocket->write(str.toUtf8());
    }
}

QString Singleton::slotReadyRead()
{
    QString in_DATA;
    in_DATA.clear();
    while(m_pTcpSocket->bytesAvailable()>0)
    {
        in_DATA += m_pTcpSocket->readAll();
    }
    //qDebug()<<in_DATA<<"Проверка 1";
    return in_DATA;

}

void Singleton::slotconnected()
{
     qDebug() << "Received the connected() signal";
}

Singleton * Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;
