#include "task3.h"
#include "ui_task3.h"
#include "singletonclient.h"
#include <QRandomGenerator>

QList <int> spisok3; // глобальные переменные и т д

task3::task3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);
}

task3::~task3()
{
    delete ui;
}

void task3::on_pushButton_clicked() // получить условие задания
{
    spisok3.clear();
    for (int i = 0;i!=10 ;i++){
        spisok3.push_back(QRandomGenerator::global()->bounded(1, 31));
    }
    QMessageBox msgBox;
    msgBox.setText("Найти максимальный поток и минимальный разрез между вершинами s и t в транспортной сети с ориентированным графом: S = (V, E, s, t, c) есть транспортная сеть, где V = {s, 1, 2, 3, 4, t}, E = {e1=(s,1," + QString::number(spisok3[0])  + "), e2=(s,2," + QString::number(spisok3[1]) + "), e3=(1,2,"+QString::number(spisok3[2]) +"), e4=(1,3,"+ QString::number(spisok3[3]) +"), e5=(2,1,"+ QString::number(spisok3[4]) +"), e6=(2,4," + QString::number(spisok3[5]) + "), e7=(3,2," + QString::number(spisok3[6]) + "), e8=(3,t,"+ QString::number(spisok3[7]) +"), e9=(4,3,"+ QString::number(spisok3[8]) +"), e10=(4,t,"+ QString::number(spisok3[9]) +"))}");
    msgBox.exec();
}


void task3::on_pushButton_2_clicked() // выйти из задачи
{
    this->hide();
    tasks *a = new tasks;
    a->show();
}


void task3::on_pushButton_3_clicked() //отправить ответ
{
    // Отправляем серверу запрос в виде : task3||<сгенерированая условием переменная>||<ответ пользователя>>
    QString ans_stud = ui->lineEdit->text();
    QString query = "task3||"+ ans_stud + "||" + QString::number(spisok3[0])  + "||" + QString::number(spisok3[1]) + "||" + QString::number(spisok3[2]) + "||" + QString::number(spisok3[3]) + "||" + QString::number(spisok3[4]) + "||" + QString::number(spisok3[5]) + "||" + QString::number(spisok3[6]) + "||" + QString::number(spisok3[7]) + "||" + QString::number(spisok3[8]) + "||" + QString::number(spisok3[9]);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

