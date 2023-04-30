#include "task4.h"
#include "ui_task4.h"
#include "singletonclient.h"

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
    QString right_answer = "Ответ верный?"; // зависит от ответа сервера                        // Переделать
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

