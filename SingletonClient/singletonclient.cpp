#include "singletonclient.h"

Singleton::Singleton(QObject * parent):QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    m_pTcpSocket->connectToHost("localhost", 2323);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotconnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), this,SLOT(slotReadyRead()));
}

void Singleton::slotsendMessage(QString str)
{
    {
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_2);
        out << quint16(0) << (str);

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));

        m_pTcpSocket->write(arrBlock);
       // m_pTcpSocket->write(str.toUtf8());
    }
}

void Singleton::slotReadyRead()
{

    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_5_3);
    for(;;) {
       if(!m_nNextBlockSize) {
            if (m_pTcpSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize)
        {
            break;
        }
    }
    QString str;
    in >> str;

    qDebug()<<str;
}

void Singleton::slotconnected()
{
     qDebug() << "Received the connected() signal";
}

Singleton * Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;

