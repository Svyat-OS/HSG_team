#include "task2.h"
#include "ui_task2.h"
#include "singletonclient.h"

QList <int> prufer_code;
QString task;

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
    task = "";

    QSet <int> temp;
    temp.clear();
    const int ming1 = 1;
    const int maxg1 = 9;
    std::random_device rd1;
    std::mt19937 mt1(rd1());
    std::uniform_int_distribution<int> ds1(ming1, maxg1);
    for(int w = 0;w < 7; w++)
    {
         prufer_code.push_back(ds1(mt1));
    }

    for(int i : prufer_code)
    {
        task += QString::number(i);
    }

    qDebug() << task;

    //foreach (int r : prufer_code) task << QString("%1").arg(r);
    QMessageBox msgBox;
    msgBox.setText("Напишите код Прюфера для Дерево T = (V, E), декодировав код Прюфера: (" + task + ")}.\nФормат ответа: 4431587");
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
    // Отправляем серверу запрос в виде : task1||<сгенерированая условием переменная>||<ответ пользователя>>
    QString ans_stud = ui->lineEdit->text();
    QMessageBox msgBox;
    if (!prufer_code.empty()){
    QString query = "task2||"+ ans_stud + "||" + task;
    Singleton::getInstance()->slotsendMessage(query);
    QString right_answer = Singleton::getInstance()->slotReadyRead();  "Ответ верный?"; // зависит от ответа сервера
    msgBox.setText(right_answer);
    while (!prufer_code.empty()){prufer_code.pop_back();}
    msgBox.exec();
    }
    else{
       msgBox.setText("Получите условие!");
       msgBox.exec();
    }
}


