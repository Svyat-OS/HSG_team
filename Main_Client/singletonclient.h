#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QObject>
#include <QDebug>
#include "mainwindow.h"
#include <QString>

class Singleton;

/**
 * @brief Класс уничтожение экземпляра класса Singleton
 */
class SingletonDestroyer
{
    private:
        Singleton * p_instance;
    public:
        ~SingletonDestroyer() {
            delete p_instance;}

        /**
         * @brief Инициализация указателя SingletonDestroyer
         * @param Singleton * pointer - Указатель класса Singleton
         */
        void initialize(Singleton * p){p_instance = p;}
};

/**
 * @brief Класс клиент в синглтоне
 */
class Singleton: public QObject
{
    Q_OBJECT
    private:
        static Singleton * p_instance;
        static SingletonDestroyer destroyer;
        QTcpSocket* m_pTcpSocket;
        quint16 m_nNextBlockSize;
    protected:
        /**
         * @brief Конструктор класса Singleton
         * @param QObject * pointer = nullptr - Аргумент по умолчанию
         */
        explicit Singleton(QObject *parent = nullptr);
        /**
         * @brief Уничтожение объекта при вызове конструктора
         */
        Singleton(const Singleton& ) = delete;

        /**
         * @brief Удаление экземпляра класса при его создании, если экземпляр уже существует
         */
        Singleton& operator = (Singleton &)=delete;
        ~Singleton() {
            m_pTcpSocket->close();
        }

        /**
         * @brief Дружественный класс с классом Singleton
         */
        friend class SingletonDestroyer;
    public:
        /**
         * @brief Возвращает указатель на экземпляр класса Singleton
         * @return Pointer - указатель на экземпляр класса
         */
        static Singleton* getInstance(){
            if (!p_instance)
            {
                p_instance = new Singleton();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        /**
         * @brief Отправляет сообщение на сервер
         * @param QString object - Текст сообщения клиента
         */
        void slotsendMessage(QString str);
public slots:
        /**
         * @brief Получение клиентом сообщения от сервера
         * @return QString object - Текст сообщения от сервера
         */
        QString slotReadyRead();

        /**
         * @brief Если клиент подключен к серверу
         */
        void slotconnected();
};


#endif // SINGLETONCLIENT_H
