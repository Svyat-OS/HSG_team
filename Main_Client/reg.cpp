#include "reg.h"
#include "ui_reg.h"
#include "singletonclient.h"

reg::reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
}

reg::~reg()
{
    delete ui;
}

void reg::on_pushButton_clicked() // вернуться в авторизацию
{
    this->hide();
    MainWindow *a = new MainWindow;
    a->show();
}

void reg::on_pushButton_2_clicked() // пройти регистрацию
{
    QString login = ui->lineEdit->text(); QString email = ui->lineEdit_2->text();
    QString passwd =  ui->lineEdit_3->text(); QString repeat_passwd = ui->lineEdit_4->text();

    QString query = "registration||"+login + "||" + email + "||" + passwd + "||" + repeat_passwd;
    //qDebug() << query;
    ui->lineEdit->clear(); ui->lineEdit_2->clear(); ui->lineEdit_3->clear(); ui->lineEdit_4->clear();
    Singleton::getInstance()->slotsendMessage(query);
    QString str = Singleton::getInstance()->slotReadyRead();
    qDebug() <<str;
    if (str == "Пользователь зарегистрирован!\r\r\n"){
        this->hide();
        tasks *a = new tasks;
        a->show();
    }
    else{
        QMessageBox::critical(this, "Регистрация не прошла", str);
    }
}

