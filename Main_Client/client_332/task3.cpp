#include "task3.h"
#include "ui_task3.h"
#include "singletonclient.h"

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
    QString right_answer = "Ответ верный?"; // зависит от ответа сервера                        // Переделать
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

