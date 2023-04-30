#include "task1.h"
#include "ui_task1.h"
#include "singletonclient.h"

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
    QMessageBox msgBox;
    msgBox.setText("Условие задания");
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
    QString right_answer = "Ответ верный?"; // зависит от ответа сервера                        // Переделать
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

