#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QObject>
#include <QDebug>


class Singleton;

class SingletonDestroyer
{
    private:
        Singleton * p_instance;
    public:
        ~SingletonDestroyer() { delete p_instance;}
        void initialize(Singleton * p){p_instance = p;}
};


class Singleton: public QObject
{
    Q_OBJECT
    private:
        static Singleton * p_instance;
        static SingletonDestroyer destroyer;
        QTcpSocket* m_pTcpSocket;
        quint16 m_nNextBlockSize;
    protected:
        Singleton(QObject *parent = nullptr);
        Singleton(const Singleton& ) = delete;
        Singleton& operator = (Singleton &)=delete;
        ~Singleton() {
            m_pTcpSocket->close();
        }
        friend class SingletonDestroyer;
    public:
        static Singleton* getInstance(){
            if (!p_instance)
            {
                p_instance = new Singleton();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
public slots:
        void slotReadyRead();
        void slotconnected();
        void slotsendMessage(QString str);
};


#endif // SINGLETONCLIENT_H
