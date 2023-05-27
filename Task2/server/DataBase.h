#ifndef DATABASE_H
#define DATABASE_H
#include <QCoreApplication>
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
        static DataBaseDestroyer * destroyer;
        QSqlDatabase db;
    protected:
        DataBase(){}
        DataBase(const DataBase& ) = delete;
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {db.close();}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();
                p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
                p_instance->db.setDatabaseName("sqlite.db");

                if(!p_instance->db.open())
                    qDebug()<<p_instance->db.lastError().text();

                destroyer->initialize(p_instance);
            }
            return p_instance;
        }
    static QString sendQuerry (QString str) {return "...";} // функция сделать запрос к БД
};

#endif // DATABASE_H
