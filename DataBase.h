#ifndef TEST_OF_BD_H
#define TEST_OF_BD_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QString>
#include <QTcpSocket>

//DataBase::getInstance();

class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * DataBasePointer;
    public:
        ~DataBaseDestroyer() { delete DataBasePointer;}
        void initialize(DataBase * p) {DataBasePointer = p;}
};

class DataBase
{
    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;
        QSqlDatabase db;
    protected:
        DataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("../server/my_data_base.db"); // не может открыть
            if(!db.open())
                qDebug()<<p_instance->db.lastError().text();
        }
        DataBase(const DataBase& ) = delete;
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {db.close();}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
    QString sendQuerry (QString str, QString command) {// функция сделать запрос к БД
       if (command=="stat"){
           QSqlQuery query(db);
           query.exec(str);
           QString res = "";
           while (query.next()) {
               res.append(query.value(0).toString()).append('\t');
               res.append(query.value(1).toString()).append('\t');
               res.append(query.value(2).toString()).append('\t');
               res.append(query.value(3).toString()).append('\t');
           }
           return res;
       }
    }
    QString sendQuerry (QString str, QString command,QString right) {// функция сделать запрос к БД
        QSqlQuery query(db);
        query.exec(str);
        int res1 = -1;
        while (query.next()) {
            res1 = query.value(0).toInt();
        }
        if (right=="+"){
            res1++;
        }
        else{
            res1--;
        }
        std::string res2 = std::to_string(res1);
        QString res = QString::fromStdString(res2);
        QSqlQuery query1(db);
        query1.prepare("UPDATE users SET "+ command +" = " + res + " WHERE id = " + "2");  // Вместо id (и двойки) - нужен текущий Socket_id авторизованного пользователя(и его дискриптор)
        query1.exec();
        return res;
    }
    bool sendQuerry (QString str, QString command, QString login, QString password){  //перегрузка для авторизации
        if (command=="author"){
            QSqlQuery query(db); // запрос, который узнаёт, находится ли данный пользователь в БД
            query.prepare(str);
            query.bindValue(":login", login);
            query.bindValue(":password", password);
            query.exec();
            QString res = "";
            while (query.next()) {
               res = query.value(0).toString();
            }
            //qDebug()<<res.toUtf8();
            if (res==""){
                return false;
            }
            else{  // в этой части присваиваем новому соединению сокет (пока неизвестно кап qintpt перевести в INT)  (с Update аккуратнее - может потребуется по-другому это реализовать, см выше как)
                //query.prepare("UPDATE users SET Socket_id = :Socket_id WHERE login = :login AND password = :password");
                //query.bindValue(":login", login);
                //query.bindValue(":password", password);
                //query.bindValue(":Socket_id", (((QTcpSocket*)sender())->socketDescriptor()));
                //query.exec();
                return true;
            }
        }
    }
    bool sendQuerry (QString str, QString command, QString login, QString password1, QString email){  //перегрузка для регистрации
        if (command=="reg"){
            QSqlQuery query1(db); // посчитаем количество интов
            query1.exec("SELECT COUNT(*) FROM users");
            int id;
            while (query1.next()) {
                id = query1.value(0).toInt();
            }
            id++; // так мы посчитали количество id и назанчаем следующий по счёту
            QSqlQuery query(db); // запрос, который узнаёт, находится ли данный пользователь в БД
            query.prepare(str);
            query.bindValue(":login", login);
            query.bindValue(":password", password1);
            query.bindValue(":email", email);
            query.bindValue(":id", id);
            query.exec();
            return true;// при регистрации сокет не назначаем
        }
    }
};

DataBase * DataBase::p_instance;
DataBaseDestroyer DataBase::destroyer;
#endif // TEST_OF_BD_H
