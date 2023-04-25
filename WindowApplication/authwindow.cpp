#include "authwindow.h"
#include "ui_authwindow.h"
#include "mainwindow.h"

authWindow::authWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authWindow)
{
    ui->setupUi(this);
    this->change_mode(true);
}

void authWindow::change_mode(bool mode) {
    ui->button_sign_in->setVisible(mode);
    ui->button_sign_up->setVisible(!mode);

    ui->line_input_email->setVisible(!mode);
    ui->label_email->setVisible(!mode);

    ui->line_input_repeat_passwd->setVisible(!mode);
    ui->label_repeat_passwd->setVisible(!mode);

    if (mode) {
        ui->button_change->setText("to sign up");
    }
    else {
        ui->button_change->setText("to sign in");
    }

}

authWindow::~authWindow()
{
    delete ui;
}

void authWindow::on_button_sign_in_clicked()
{
    qDebug() << "autherization||" + ui->line_input_login->text()
        + "||" + ui->line_input_passwd->text();

    ui->line_input_login->clear();
    ui->line_input_passwd->clear();

    this->hide();

    MainWindow * w2 = new MainWindow;
    w2->show();

}

void authWindow::on_button_sign_up_clicked() {
    QString email = ui->line_input_email->text();
    QString repeat_passwd = ui->line_input_repeat_passwd->text();

    qDebug() << "registration||" + ui->line_input_login->text()
        + "||" +email + "||" + ui->line_input_passwd->text()
        + "||" + repeat_passwd;

    ui->line_input_login->clear();
    ui->line_input_email->clear();
    ui->line_input_passwd->clear();
    ui->line_input_repeat_passwd->clear();

    this->hide();

    MainWindow * w2 = new MainWindow;
    w2->show();

}

void authWindow::on_button_change_clicked()
{
    this->change_mode(ui->button_sign_up->isVisible());
}

