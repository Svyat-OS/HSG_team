#include "task1.h"
#include "ui_task1.h"
#include "singletonclient.h"

QList <int> spisok; // глобальные переменные и т д

task1::task1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task1)
{
    ui->setupUi(this);
}

task1::~task1()
{
    delete ui;
}

void task1::on_pushButton_clicked() // получить условие задания
{
    QSet <int> temp;
    temp.clear();
    while (temp.size()!=9){          // пока мощность множества не станет равно 9
        temp.insert(Random::get(1, 9)); // заполняем наше множество случайными числами от 1 до 9 и без повторов
    }
    for (auto itr = temp.begin(); itr != temp.end(); itr++){ // переносим числа из множества в список
        spisok.push_back(*itr);
    }
    QMessageBox msgBox;
    msgBox.setText("Напишите код Прюфера для Дерево T = (V, E),\nгде V = {1,2,3,4,5,6,7,8,9}, E = {(" + QString::number(spisok[0]) + "," + QString::number(spisok[1]) + "), (" + QString::number(spisok[0]) + "," + QString::number(spisok[6]) + "), (" + QString::number(spisok[0]) + "," + QString::number(spisok[7]) + "), (" + QString::number(spisok[1]) + "," + QString::number(spisok[5]) + "), (" + QString::number(spisok[2]) + "," + QString::number(spisok[4]) + "), (" + QString::number(spisok[3]) + "," + QString::number(spisok[4]) + "), (" + QString::number(spisok[4]) + "," + QString::number(spisok[5]) + "), (" + QString::number(spisok[4]) + "," + QString::number(spisok[8]) + ")}.\nФормат ответа: 4431587");
    msgBox.exec();
}


void task1::on_pushButton_2_clicked() // выйти из задачи
{
    this->hide();
    tasks *a = new tasks;
    a->show();
}


void task1::on_pushButton_3_clicked() //отправить ответ
{
    // Отправляем серверу запрос в виде : task1||<сгенерированая условием переменная>||<ответ пользователя>>
    QString ans_stud = ui->lineEdit->text();
    QMessageBox msgBox;
    if (!spisok.empty()){
    QString query = "task1||"+ ans_stud + "||" + QString::number(spisok[0]) + "||" + QString::number(spisok[1]) + "||" + QString::number(spisok[2]) + "||" + QString::number(spisok[3]) + "||" + QString::number(spisok[4]) + "||" + QString::number(spisok[5]) + "||" + QString::number(spisok[6]) + "||" + QString::number(spisok[7]) + "||" + QString::number(spisok[8]);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    msgBox.setText(right_answer);
    while (!spisok.empty()){spisok.pop_back();}
    msgBox.exec();
    }
    else{
       msgBox.setText("Получите условие!");
       msgBox.exec();
    }
}

