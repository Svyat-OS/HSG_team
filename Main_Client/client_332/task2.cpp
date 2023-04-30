#include "task2.h"
#include "ui_task2.h"
#include "singletonclient.h"

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
    QString right_answer = "Ответ верный?"; // зависит от ответа сервера                        // Переделать
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}


