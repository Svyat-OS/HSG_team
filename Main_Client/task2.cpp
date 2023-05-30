#include "task2.h"
#include "ui_task2.h"
#include "singletonclient.h"

int x_2 = 2; // глобальные переменные
int y_2 = 2; // и т д

task2::task2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
}

task2::~task2()
{
    delete ui;
}

void task2::on_pushButton_clicked() // получить условие задания
{
    // в этом участке кода идёт генерация глобальных переменных для 1 задания
    QMessageBox msgBox;
    msgBox.setText("Условие задания");
    msgBox.exec();
}


void task2::on_pushButton_2_clicked() // выйти из задачи
{
    this->hide();
    tasks *a = new tasks;
    a->show();
}


void task2::on_pushButton_3_clicked() //отправить ответ
{
    // Отправляем серверу запрос в виде : task2||<сгенерированая условием переменная>||<ответ пользователя>>
    QString ans_stud = ui->lineEdit->text();
    QString query = "task2||"+ ans_stud + "||" + QString::number(x_2) + "||" + QString::number(y_2);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}


