#include "func_for_server.h"
#include "DataBase.h"

QString parsing(QString str, int descriptor){ //name_of_func||param1||param2||...
    //str = str.left(str.length()-2);  // может не пригодиться
    QStringList ans = str.split("||");
    qDebug()<<str;
    QString func = ans[0];
    ans.pop_front(); // внимательно! теперь в этом листе названия функции уже нет
    if (func=="task1"){
        func=task1(ans,descriptor);
        return func;}
    else if (func=="task2"){
        func=task2(ans,descriptor);
        return func;}
    else if (func=="task3"){
        func=task3(ans,descriptor);
        return func;}
    else if (func=="task4"){
        func=task4(ans,descriptor);
        return func;}
    else if (func=="authorization"){
        func=author(ans,descriptor);
        return func;}
    else if (func=="registration"){
        func=reg(ans,descriptor);
        return func;}
    else if (func=="statistics"){
        func=stat(ans,descriptor);
        return func;}
    else {
        func = "ERROR!";
        return (func+'\r'+'\n');
    }

}

QString task1(QStringList params, int descriptor){
    int answer_stud = params[0].toInt(); // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    int x_1 = params[1].toInt(); //переменные из условия задачи
    int y_1 = params[2].toInt(); // их столько, сколько нужно для задачи
    int real_ans = 0; // пока так
    // кусок кода, где cчитаем настоящий правильный ответ
    QString right;
    if (answer_stud==real_ans){
        right = '+';
    }
    else{
        right = '-';
    }
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task1 FROM users WHERE Socket_id = " + QString::number(descriptor),"task1",right,descriptor);
    if ( right =="+"){
        return "Ответ верный";
    }
    else{
        return "Ответ неверный";
    }
}
QString task2(QStringList params, int descriptor){
    int answer_stud = params[0].toInt(); // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    int x_2 = params[1].toInt(); //переменные из условия задачи
    int y_2 = params[2].toInt(); // их столько, сколько нужно для задачи
    int real_ans = 0; // пока так
    // кусок кода, где считаем настоящий правильный ответ
    QString right;
    if (answer_stud==real_ans){
        right = '+';
    }
    else{
        right = '-';
    }
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task2 FROM users WHERE Socket_id = " + QString::number(descriptor),"task2",right,descriptor);
    if ( right =="+"){
        return "Ответ верный";
    }
    else{
        return "Ответ неверный";
    }
}
QString task3(QStringList params, int descriptor){
    int answer_stud = params[0].toInt(); // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    int x_3 = params[1].toInt(); //переменные из условия задачи
    int y_4 = params[2].toInt(); // их столько, сколько нужно для задачи
    int real_ans = 0; // пока так
    // кусок кода, где считаем настоящий правильный ответ
    QString right;
    if (answer_stud==real_ans){
        right = '+';
    }
    else{
        right = '-';
    }
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task3 FROM users WHERE Socket_id = " + QString::number(descriptor),"task3",right,descriptor);
    if ( right =="+"){
        return "Ответ верный";
    }
    else{
        return "Ответ неверный";
    }
    return ans;
}
QString task4(QStringList params, int descriptor){
    int answer_stud = params[0].toInt(); // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    int x_4 = params[1].toInt(); //переменные из условия задачи
    int y_4 = params[2].toInt(); // их столько, сколько нужно для задачи
    int real_ans = 0; // пока так
    // кусок кода, где считаем настоящий правильный ответ
    QString right;
    if (answer_stud==real_ans){
        right = '+';
    }
    else{
        right = '-';
    }
    QString ans = DataBase::getInstance()->sendQuerry("SELECT task4 FROM users WHERE Socket_id = " + QString::number(descriptor),"task4",right,descriptor);
    if ( right =="+"){
        return "Ответ верный";
    }
    else{
        return "Ответ неверный";
    }
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
QString reg(QStringList params, int descriptor){
    QString login=params[0];
    QString email=params[1];
    QString password1=params[2];
    QString password2=params[3];
    if (password1==password2){
        if (DataBase::getInstance()->sendQuerry("INSERT INTO users(id, role, login, password, email, task1, task2, task3, task4) VALUES(:id,'stud', :login, :password, :email, 0, 0, 0, 0)","reg",login,password1,email)){
            QStringList params1;
            params1.push_back(login);
            params1.push_back(password1);
            author(params1,descriptor);
            qDebug()<<params1[0]<<" "<<params1[1];
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

