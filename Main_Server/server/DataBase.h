#ifndef TEST_OF_BD_H
#define TEST_OF_BD_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QString>

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
    QString sendQuerry (QString str, QString command,int descriptor) {// функция сделать запрос к БД (статистика)
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
    QString sendQuerry (QString str, QString command,QString right,int descriptor) {// функция сделать запрос к БД (task1 - task4)

        QSqlQuery query(db);
        query.exec(str);
        int res1;
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
        qDebug()<<res;
        QSqlQuery query1(db);
        query1.prepare("UPDATE users SET "+ command +" = " + res + " WHERE Socket_id = " + QString::number(descriptor) );
        query1.exec();
    }
    bool sendQuerry (QString str, QString command, QString login, QString password, int descriptor){  //перегрузка для авторизации
        if (command=="author"){
            qDebug()<<descriptor;
            qDebug()<<QString::number(descriptor).toUtf8();
            QSqlQuery query(db); // запрос, который узнаёт, находится ли данный пользователь в БД
            query.exec(str);
            QString res = "";
            while (query.next()) {
               res = query.value(0).toString();
            }
            if (res==""){
                return false;
            }
            else{
                QSqlQuery query1(db);
                query1.exec("UPDATE users SET Socket_id = "+ QString::number(descriptor) + " WHERE login = \'" + login + "\' and password = " + password);
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
