#include "task1.h"
#include "ui_task1.h"
#include "singletonclient.h"

int x_1 = 2; // глобальные переменные
int y_1 = 2; // и т д

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
    // в этом участке кода идёт генерация глобальных переменных для 1 задания
    QMessageBox msgBox;
    msgBox.setText("Условие задания для 1 задания");
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
    QString query = "task1||"+ ans_stud + "||" + QString::number(x_1) + "||" + QString::number(y_1);
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    QMessageBox msgBox;
    msgBox.setText(right_answer);
    msgBox.exec();
}

