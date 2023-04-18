#include "func_for_server.h"
#include "DataBase.h"

QString parsing(QString str, int descriptor){ //name_of_func||param1||param2||...
    str = str.left(str.length()-2);
    QStringList ans = str.split("||");
    qDebug()<<str;
    QString func = ans[0];
    ans.pop_front(); // внимательно! теперь в этом листе названия функции уже нет
    if (func=="task1"){
        func=task1(ans,descriptor);}
    else if (func=="task2"){
        func=task2(ans,descriptor);}
    else if (func=="task3"){
        func=task3(ans,descriptor);}
    else if (func=="task4"){
        func=task4(ans,descriptor);}
    else if (func=="authorization"){
        func=author(ans,descriptor);}
    else if (func=="registration"){
        func=reg(ans);}
    else if (func=="statistics"){
        func=stat(ans,descriptor);}
    else {
        func = "ERROR!";
    }
    return (func+'\r'+'\n');
}

QString task1(QStringList params, int descriptor){
    QString right = params[0]; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task1 FROM users WHERE Socket_id = " + QString::number(descriptor),"task1",right,descriptor);
    return ans;
}
QString task2(QStringList params, int descriptor){
    QString right =  params[0]; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task2 FROM users WHERE Socket_id = " + QString::number(descriptor),"task2",right,descriptor);
    return ans;
}
QString task3(QStringList params, int descriptor){
    QString right = params[0]; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task3 FROM users WHERE Socket_id = " + QString::number(descriptor),"task3",right,descriptor);
    return ans;
}
QString task4(QStringList params, int descriptor){
    QString right = params[0]; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task4 FROM users WHERE Socket_id = " + QString::number(descriptor),"task4",right,descriptor);
    return ans;
}
QString author(QStringList params, int descriptor){
    QString login=params[0];
    QString password=params[1];
    if (DataBase::getInstance()->sendQuerry("SELECT id FROM users where login = \'" + login + "\' and password = " + password,"author",login,password,descriptor)){
        return "Авторизация прошла успешно!\r\r\n";
    }
    else {
        return "Данный пользователь не найден или неправильный пароль\r\r\n";
    }
}
QString reg(QStringList params){
    QString login=params[0];
    QString email=params[1];
    QString password1=params[2];
    QString password2=params[3];
    if (password1==password2){
        if (DataBase::getInstance()->sendQuerry("INSERT INTO users(id, role, login, password, email, task1, task2, task3, task4) VALUES(:id,'stud', :login, :password, :email, 0, 0, 0, 0)","reg",login,password1,email)){
            return "Пользователь зарегистрирован!\r\r\n";
        }
        else {
            return "Пользователь не зарегистрирован!\r\r\n";
        }
    }
    else{
        return "Пароли не совпадают\r\r\n";
    }
}
QString stat(QStringList params, int descriptor){
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task1,task2,task3,task4 FROM users WHERE Socket_id = " + QString::number(descriptor),"stat", descriptor);
    return ans;
}
// при желании можно добавить по образцу функций выше новые функции (в parsing и h файл тоже надо не забыть их добавить)

