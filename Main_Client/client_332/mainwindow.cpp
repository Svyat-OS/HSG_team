#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singletonclient.h"

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
    ui->lineEdit->clear(); ui->lineEdit_2->clear();
    Singleton::getInstance()->slotsendMessage(query);
    QString str = Singleton::getInstance()->slotReadyRead();
    //qDebug() << str << "Проверка 2";
    if (str == "Авторизация прошла успешно!\r\r\n"){
        this->hide();
        tasks *a = new tasks;
        a->show();
    }
    else{
        QMessageBox::critical(this, "Авторизация не прошла", "Пользователь не найден");
    }
}


void MainWindow::on_pushButton_2_clicked() // перейти в регистрацию
{
    this->hide();
    reg *a = new reg;
    a->show();
}

