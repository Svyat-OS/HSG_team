#include "func_for_server.h"
#include "DataBase.h"

QString parsing(QString str, int descriptor){ //name_of_func||param1||param2||...
    QStringList ans = str.split("||");
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
    int m = INT_MAX;
    QVector < QVector <int> > matrix_template = { {m, params[1].toInt(), params[2].toInt(), m, m, m},
        {m, m, m, params[3].toInt(), m, m}, {m, params[4].toInt(), m, params[5].toInt(), params[6].toInt(), m},
        {m, m, m, m, m, params[7].toInt()}, {m, m, m, params[8].toInt(), m, params[9].toInt()}, {m, m, m, m, m, m} };

    for (int i = 0; i < 6; i++) {
            matrix_template[i].resize(6);
        }

        bool visited[6]{};
        int D[6]{};

        for (int i = 0; i < 6; i++) {
            D[i] = matrix_template[0][i];
            visited[i] = false;
        }

        D[0] = 0;
        int index = 0, u = 0;

        for (int i = 0; i < 6; i++) {
            int min = INT_MAX;
            for (int j = 0; j < 6; j++) {
                if (!visited[j] && D[j] < min) {
                    min = D[j];
                    index = j;
                }
            }

            u = index;
            visited[u] = true;

            for (int j = 0; j < 6; j++) {
                if (!visited[j] && matrix_template[u][j] != INT_MAX && D[u] != INT_MAX && (D[u] + matrix_template[u][j] < D[j])) {
                    D[j] = D[u] + matrix_template[u][j];
                }
            }
        }

        // проверка на правильность ответа пользователя
        QChar right = params[0].toInt() == D[5] ? '+' : '-';

        // ИЗ-ЗА ЭТОЙ СТРОЧКИ РУШИТСЯ СЕРВЕР
        //QString ans = DataBase::getInstance()->sendQuerry("SELECT task4 FROM users WHERE Socket_id = " + QString::number(descriptor),"task4",right,descriptor);

        return right == '+' ? QString("Ответ верный") : QString("Ответ неверный, правильный ответ " + QString::number(D[5]));
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
            author(params,descriptor);
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

