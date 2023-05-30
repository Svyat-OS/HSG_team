#include "task3.h"
#include "ui_task3.h"
#include "singletonclient.h"

int x_3 = 2; // глобальные переменные
int y_3 = 2; // и т д

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
    // в этом участке кода идёт генерация глобальных переменных для 1 задания
    QMessageBox msgBox;
    msgBox.setText("Условие задания");
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
    QString query = "task3||"+ ans_stud + "||" + QString::number(x_3) + "||" + QString::number(y_3);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

