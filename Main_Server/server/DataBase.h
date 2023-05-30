#ifndef TEST_OF_BD_H
#define TEST_OF_BD_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QString>

class DataBase;

/**
 * @brief Класс уничтожение экземпляра класса DataBase
 */
class DataBaseDestroyer
{
    private:
        DataBase * DataBasePointer;
    public:
        ~DataBaseDestroyer() { delete DataBasePointer;}
        /**
         * @brief Инициализация указателя DataBasePointer
         * @param DataBase * pointer
         */
        void initialize(DataBase * p) {DataBasePointer = p;}
};

/**
 * @brief Класс база данных в синглтоне
 */
class DataBase
{
    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;
        QSqlDatabase db;
    protected:
        DataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("./my_data_base.db");
            if(!db.open())
                qDebug()<<p_instance->db.lastError().text();
        }

        /**
         * @brief Уничтожение объекта при вызове конструктора
         */
        DataBase(const DataBase& ) = delete;

        /**
         * @brief Удаление экземпляра класса при его создании, если экземпляр уже существует
         */
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {db.close();}
        /**
         * @brief Дружественный класс c классом DataBase
         */
        friend class DataBaseDestroyer;
    public:
        /**
         * @brief Возвращает экземпляр класса DataBase
         * @return Pointer
         */
        static DataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        /**
     * @brief Перегрузка функции для получения статистики из базы данных
     * @param QString query
     * @param QString command
     * @param int descriptor
     * @return QString object
     */
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

    /**
     * @brief Перегрузка функции для получения сведений о задачах из базы данных
     * @param QString query
     * @param QString command
     * @param QString right
     * @param int descriptor
     * @return NAN
     */
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

    /**
     * @brief Перегрузка функции для авторизации пользователя
     * @param QString query
     * @param QString command
     * @param QString login
     * @param QString password
     * @param int descriptor
     * @return bool
     */
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

    /**
     * @brief Перегрузка функции для регистрации пользователя
     * @param QString query
     * @param QString command
     * @param QString login
     * @param QString password
     * @param QString email
     * @return bool
     */
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
