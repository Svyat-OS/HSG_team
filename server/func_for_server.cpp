#include "func_for_server.h"
#include <QStringList>


QString parsing(QString str){ //name_of_func||param1||param2||...
    QStringList ans = str.split("||");
    QString func = ans[0];
    ans.pop_front();
    if (func=="task1\r\n"){
        func=task1(ans);}
    else if (func=="task2\r\n"){
        func=task2(ans);}
    else if (func=="task3\r\n"){
        func=task3(ans);}
    else if (func=="task4\r\n"){
        func=task4(ans);}
    else if (func=="authorization\r\n"){
        func=autor(ans);}
    else if (func=="registration\r\n"){
        func=reg(ans);}
    else if (func=="statistics\r\n"){
        func=stat(ans);}
    else {
        func = "ERROR!";
    }
    return (func+'\n');
}

QString task1(QStringList params){
    std::string a="task1";
    QString ans = QString::fromStdString(a);
    return ans;
}
QString task2(QStringList params){
    std::string a="task2";
    QString ans = QString::fromStdString(a);
    return ans;
}
QString task3(QStringList params){
    std::string a="task3";
    QString ans = QString::fromStdString(a);
    return ans;
}
QString task4(QStringList params){
    std::string a="task4";
    QString ans = QString::fromStdString(a);
    return ans;
}
QString autor(QStringList params){
    std::string a="autor";
    QString ans = QString::fromStdString(a);
    return ans;
}
QString reg(QStringList params){
    std::string a="reg";
    QString ans = QString::fromStdString(a);
    return ans;
}
QString stat(QStringList params){
    std::string a="stat";
    QString ans = QString::fromStdString(a);
    return ans;
}

