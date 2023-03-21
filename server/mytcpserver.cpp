#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        qDebug() << "New client connected";
        QTcpSocket* curr_mTcpSocket;
        curr_mTcpSocket = mTcpServer->nextPendingConnection();
        curr_mTcpSocket->write("Hello!\r\r\n");
        mTcpSocket[curr_mTcpSocket->socketDescriptor()]=curr_mTcpSocket;
        connect(curr_mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(curr_mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *curr_mTcpSocket = (QTcpSocket*)sender();
       QByteArray out_DATA;
       QString in_DATA;
       in_DATA.clear();
       while(curr_mTcpSocket->bytesAvailable()>0)
       {
           in_DATA += curr_mTcpSocket->readAll();
       }
       qDebug() << in_DATA.toUtf8();
       out_DATA = (parsing(in_DATA)).toUtf8();
       curr_mTcpSocket->write(out_DATA);
}

void MyTcpServer::slotClientDisconnected(){

    QTcpSocket* curr_mTcpSocket = ((QTcpSocket*)sender());
    int curr_mTcpSocket_desc = curr_mTcpSocket->socketDescriptor();
    mTcpSocket.erase(mTcpSocket.find(curr_mTcpSocket_desc),mTcpSocket.find(curr_mTcpSocket_desc));
    curr_mTcpSocket->close();
}

