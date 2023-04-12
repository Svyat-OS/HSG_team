#include "func_for_server.h"
#include "DataBase.h"

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
    QString right = "+"; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString id = "2" ; //вместо id (где '2') должен быть Socket_id (пока есть проблема)
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task1 FROM users WHERE id = " + id,"task1",right); // вместо id (где '2') должен быть Socket_id (пока есть проблема)
    return ans;
}
QString task2(QStringList params){
    QString right = "+"; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString id = "2" ; //вместо id (где '2') должен быть Socket_id (пока есть проблема)
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task2 FROM users WHERE id = " + id,"task2",right); // вместо id (где '2') должен быть Socket_id (пока есть проблема)
    return ans;
}
QString task3(QStringList params){
    QString right = "+"; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString id = "2" ; //вместо id (где '2') должен быть Socket_id (пока есть проблема)
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task3 FROM users WHERE id = " + id,"task3",right); // вместо id (где '2') должен быть Socket_id (пока есть проблема)
    return ans;
}
QString task4(QStringList params){
    QString right = "+"; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString id = "2" ; //вместо id (где '2') должен быть Socket_id (пока есть проблема)
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task4 FROM users WHERE id = " + id,"task4",right); // вместо id (где '2') должен быть Socket_id (пока есть проблема)
    return ans;
}
QString author(QStringList params){
    QString login=params[0];
    QString password=params[1];
    if (DataBase::getInstance()->sendQuerry("SELECT id FROM users where login = :login and password = :password","author",login,password)){
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
QString stat(QStringList params){
    QString id = "2" ; //вместо id (где '2') должен быть Socket_id (пока есть проблема)
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task1,task2,task3,task4 FROM users WHERE id = " + id,"stat"); // вместо id (где '2') должен быть Socket_id (пока есть проблема)
    return ans;
}
// при желании можно добавить по образцу функций выше новые функции (в parsing и h файл тоже надо не забыть их добавить)

