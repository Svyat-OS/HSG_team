#include "authwindow.h"
#include "ui_authwindow.h"

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
    qDebug() << "authentication\n" << "login: " << ui->line_input_login->text()
        << "\npassword: " << ui->line_input_passwd->text();

    ui->line_input_login->clear();
    ui->line_input_passwd->clear();
}

void authWindow::on_button_sign_up_clicked() {
    this->on_button_sign_in_clicked();
}

void authWindow::on_button_change_clicked()
{
    this->change_mode(ui->button_sign_up->isVisible());
}

