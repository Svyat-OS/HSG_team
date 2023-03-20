#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QtNetwork>
#include <QByteArray>

class QTextEdit;
class QLineEdit;

class MyClient : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit* m_ptxtInfo;
    QLineEdit* m_ptxtInput;
    quint16 m_nNextBlockSize;

public:
    MyClient(const QString& strHost, int nPort, QWidget *pwgt = 0);

private slots:
    void slotReadyRead ();
    void slotError (QAbstractSocket::SocketError);
    void slotSendToServer ();
    void slotConnected ();
};
#endif // MAINWINDOW_H
