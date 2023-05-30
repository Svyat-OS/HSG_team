#include <vector>
#include <ctime>
#include "task4.h"
#include "ui_task4.h"
#include "singletonclient.h"

int x_4 = 2; // глобальные переменные
int y_4 = 2; // и т д

task4::task4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task4)
{
    ui->setupUi(this);
}

task4::~task4()
{
    delete ui;
}

// переменная со значениями весов ребер
QVector <int> w = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void weight_generator() {
    srand(unsigned(time(nullptr)));

    for (int i = 0 ; i < 9; i++) {
        w[i] = rand() % 10;
    }
}

void task4::on_pushButton_clicked() // получить условие задания
{
    weight_generator(); // генерация весов для ребер

    QMessageBox msgBox;
    QString text =
        "Найти кратчайший путь между вершинами s и t в нагруженном "
        "связном ориентированном графе G = (V, E), "
        "где V = {v1, v2, v3, v4, v5, v6}, s = v1, t = v6,\n"
        "E = {{v1,v2,"+QString::number(w[0])+"}, {v1,v3,"+QString::number(w[1])+"}, {v2,v4,"+QString::number(w[2])+"}, "
             "(v3,v2,"+QString::number(w[3])+"), {v3,v4,"+QString::number(w[4])+"}, {v3,v5,"+QString::number(w[5])+"}, "
             "{v4,v6,"+QString::number(w[6])+"}, (v5,v4,"+QString::number(w[7])+"), {v5,v6,"+QString::number(w[8])+"}";

    msgBox.setText(text); //записать сгенерированнное условие
    msgBox.exec();
}


void task4::on_pushButton_2_clicked() // выйти из задачи
{
    this->hide();
    tasks *a = new tasks;
    a->show();
}


void task4::on_pushButton_3_clicked() //отправить ответ
{
    // Отправляем серверу запрос в виде : task4||<сгенерированая условием переменная>||<ответ пользователя>>
    QString ans_stud = ui->lineEdit->text();
    QString query = "task4||"+ ans_stud + "||" + QString::number(w[0]) + "||" + QString::number(w[1]) + "||" + QString::number(w[2])
            + "||" + QString::number(w[3]) + "||" + QString::number(w[4]) + "||" + QString::number(w[5])
            + "||" + QString::number(w[6]) + "||" + QString::number(w[7]) + "||" + QString::number(w[8]);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

