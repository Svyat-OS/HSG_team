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

    QString sendQuerry (QString str) {// функция сделать запрос к БД
        QSqlQuery query(db);
        query.exec(str);
        QSqlRecord rec = query.record();
        const int asd1 = rec.indexOf(str);//номер "столбца"
        //const int passwordIndex = rec.indexOf("password");
        qDebug() << asd1;
        QString res = "";
        while(query.next()){
            //res.append(query.value(loginIndex).toString()).append("\t").append(query.value(passwordIndex).toString()).append("\n");
            res.append(query.value(asd1).toString());
        }
        qDebug()<<res.toUtf8();
        return res;
    }

};

DataBase * DataBase::p_instance;
DataBaseDestroyer DataBase::destroyer;
#endif // TEST_OF_BD_H
