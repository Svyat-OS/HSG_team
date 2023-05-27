#include "func_for_server.h"
#include "DataBase.h"
#include <random>

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
    QString answer_stud = params[0]; // если правильно +1, если нет, то -1   В будущем каждый будет это реализовывать, когда будет делать для своей задачи
    QString right_answer = ""; // считаем правильный ответ
    QList <QString> Edges; // рёбер всего 8, матрица 8 на 2, каждая строка - это ребро, левый стоблик - левая вершина, правый столбик - правая вершина
    Edges.clear();
    Edges.push_back(params[1]);Edges.push_back(params[2]);Edges.push_back(params[1]);Edges.push_back(params[7]);Edges.push_back(params[1]);Edges.push_back(params[8]);
    Edges.push_back(params[2]);Edges.push_back(params[6]);Edges.push_back(params[3]);Edges.push_back(params[5]);Edges.push_back(params[4]);
    Edges.push_back(params[5]);Edges.push_back(params[5]);Edges.push_back(params[6]);Edges.push_back(params[5]);Edges.push_back(params[9]);
    QMap <QString,int> spisok; // будем считать, скольким рёбрам инцидентна каждая вершина
    spisok.clear();
    for (int i=1;i<10;i++){ // пока все вершины встречаеются 0 раз
        spisok[QString::number(i)]=0;
    }
    for (int i=0;i<Edges.size();i++){//считаем, скольким рёбрам инцидентна каждая вершина
        spisok[Edges[i]]++;
    }
    QString temp; // текущая вершина, которая является листом
    for (int j=0;j<((Edges.size()/2)-1);j++){ // этот процесс происходит p-1 раз, где p - это кол-во рёбер
        for (int k=1;k<10;k++){
            if (spisok[QString::number(k)]==1){ // проверка на лист
                temp = QString::number(k); // наш минимальный листок
                break;
            }
        }
        for (int i=0;i<8;i++){
            if (Edges[i*2]==temp){
                spisok[Edges[i*2]]--; spisok[Edges[i*2+1]]--; // количество этих вершин уменьшается на 1
                right_answer += Edges[i*2+1];
                Edges[i*2] = "-1"; Edges[i*2+1] = "-1"; // забываем про это ребро
                break;
            }
            if (Edges[i*2+1]==temp){
                spisok[Edges[i*2]]--; spisok[Edges[i*2+1]]--; // количество этихх вершин уменьшается на 1
                right_answer += Edges[i*2];
                Edges[i*2] = "-1"; Edges[i*2+1] = "-1"; // забываем про это ребро
                break;
            }
        }
        //for (int i=0;i<Edges.size();i++){
        //    qDebug()<<Edges[i].toUtf8();
        //}
        qDebug()<<"Here";
    }
    QString right;
    if (answer_stud==right_answer){ // проверка условия
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
        return "Ответ неверный, правильный ответ: " + right_answer;
    }
}
QString task2(QStringList params, int descriptor){
    QString answer_stud = params[0];
    QString condition = params[1];
    QList <int> astud;
    QList <int> prufer_code;
    prufer_code.clear();
    qDebug() << astud;
    QString right_answer;
    int in;
    for(int i = 0; i < 7; i++)
    {
        in = condition.toInt();
    }
    qDebug() << in;
    for(int i = 0; i < 7; i++)
    {
        int g = in % 10;
        qDebug() << g;
        prufer_code.push_front(g);
        in = in /10;
    }
    qDebug() << prufer_code;
    QList <int> Eges;
    int n = (int) prufer_code.size() + 2;
    qDebug() << n;
    Eges.clear();
    for (int i=1;i<=n;i++)
    {
        Eges.push_back(i);

    }
    qDebug() << Eges;
    QList <int> Min;
    Min.clear();
    QList <int> Answer;
    for (int i=1;i<=n;i++)
    {
        int c = i;
        int k = 0;
        for (int y : prufer_code)
        {
            if (c == y)
            {
                k++;
            }
        }

        if (k == 0)
        {
            Min.push_back(c);
        }

    }
    qDebug() << Min;
    int K = 1;
    while(prufer_code.empty() == false){
    QList <int>::iterator p = Eges.begin();
    int position = 0;
    QList <int>::iterator p1 = Min.begin();
    int position1 = 0;
    int min = n + 1;
    for (int T : Eges)
    {
        int k1 = 0;
        for (int y : prufer_code)
        {
            if (T == y)
            {
                k1++;
            }
        }

        for (int M : Min)
        {
            if (T == M)
            {
                k1++;
            }
        }

        if (k1 == 0)
        {
            Min.push_back(T);
        }

    }

        for (int z : Min)
        {
            if (z < min)
            {
                min = z;
            }
        }

        for (int it : Eges)
        {
            if (min == it)
            {
                p += position;
            }
            position++;
        }

        for (int it1 : Min)
        {
            if (min == it1)
            {
                p1 += position1;
            }
            position1++;
        }
        qDebug() << *p;
        Eges.erase(p);
        Answer.push_back(prufer_code.front());
        Answer.push_back(min);
        Min.erase(p1);
        prufer_code.pop_front();

    K++;
    qDebug() << min;
    qDebug() << Answer;
    qDebug() << Eges;
    qDebug() << Min;
    qDebug() << prufer_code;
    qDebug() << K;
    qDebug() << '/';
    }
    astud = Answer + Eges;
    for(int u : astud)
    {
        right_answer += QString::number(u);
    }
    qDebug() << right_answer;
    qDebug() << answer_stud;
    QString right;
    if (answer_stud==right_answer){ // проверка условия
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
        return "Ответ неверный, правильный ответ: " + right_answer;
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

