#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

// Соединение с БД

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","mydb");
db.setHostName("localhost");
db.setDatabaseName("databse_name");
db.setUserName("username");
db.setPassword("password");

if (!db.open())
{
    qDebug() << db.lastError().text();
}else
{
    qDebug() << "Database connection established successfully!";
}

// После подключения выполняем запросы к базе данных

QSqlQuery query;
query.exec("SELECT * FROM table_name");

while (query.next())
{
    QString id = query.value(0).toString();
    QString name = query.value(1).toString();
    // и так далее
}

