#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // пройти авторизацию
{
    QString login = ui->lineEdit->text();QString passwd =  ui->lineEdit_2->text();

    QString query = "authorization||"+login + "||" + passwd;
    qDebug() << query;
    ui->lineEdit->clear(); ui->lineEdit_2->clear();

    //отправляем запрос (query) серверу о регистрации, сверяемся, прошла ли авторизация?
    QString str ="Авторизация прошла успешно!\r\r\n";      //узнаем, существует ли пользователь?                                                // ПОМЕНЯТЬ
    if (str == "Авторизация прошла успешно!\r\r\n"){
        this->hide();
        tasks *a = new tasks;
        a->show();
    }
    else{
        QMessageBox::critical(this, "Авторизация не прошла", str);
    }
}


void MainWindow::on_pushButton_2_clicked() // перейти в регистрацию
{
    this->hide();
    reg *a = new reg;
    a->show();
}

