#include "func_for_server.h"

QString parsing(QString str){ //name_of_func||param1||param2||...
    QStringList ans = str.split("||");
    std::string temp = ""; // вспомогательная переменная, чтобы избавить от \r\n на конце
    for (int i=0;i<((ans[ans.size()-1]).toUtf8()).length()-2;i++){   // цикл для удаления \r\n на конце последней переменной
        temp += (ans[ans.size()-1].toUtf8())[i];
    }
    ans[ans.size()-1] = QString::fromStdString(temp);
    QString func = ans[0];
    ans.pop_front(); // внимательно! теперь в этом листе названия функции уже нет
    if (func=="task1"){
        func=task1(ans);}
    else if (func=="task2"){
        func=task2(ans);}
    else if (func=="task3"){
        func=task3(ans);}
    else if (func=="task4"){
        func=task4(ans);}
    else if (func=="authorization"){
        func=author(ans);}
    else if (func=="registration"){
        func=reg(ans);}
    else if (func=="statistics"){
        func=stat(ans);}
    else {
        func = "ERROR!";
    }
    return (func+'\r'+'\n');
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
QString author(QStringList params){
    std::string a="author";
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
// при желании можно добавить по образцу функций выше новые функции (в parsing и h файл тоже надо не забыть их добавить)

