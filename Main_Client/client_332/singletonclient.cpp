#include "singletonclient.h"


Singleton::Singleton(QObject * parent):QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    m_pTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(m_pTcpSocket, SIGNAL(connected()),this, SLOT(slotconnected()));
    //connect(m_pTcpSocket, SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
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
    QString msg;
    msg.clear();
    //while(m_pTcpSocket->bytesAvailable()>0)
    //{
    //    msg += m_pTcpSocket->readAll();
    //}
    if (m_pTcpSocket->waitForConnected(500)){
        m_pTcpSocket->waitForReadyRead(500);
        msg = m_pTcpSocket->readAll();
    }
    //qDebug()<<msg<<"Проверка 1";

   return msg;
}

void Singleton::slotconnected()
{
    qDebug() << "Received the connected() signal";
}

Singleton * Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;
