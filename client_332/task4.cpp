#include "task4.h"
#include "ui_task4.h"
#include "singletonclient.h"
#include <QRandomGenerator>

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

void task4::on_pushButton_clicked() // получить условие задания
{
    // в этом участке кода идёт генерация глобальных переменных для 1 задания
    QMessageBox msgBox;
    msgBox.setText("Условие задания");
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
    QString query = "task4||"+ ans_stud + "||" + QString::number(x_4) + "||" + QString::number(y_4);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

