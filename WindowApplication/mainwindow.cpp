#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_1_clicked()
{
    qDebug() << "task1";
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "task2";
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "task3";
}

void MainWindow::on_action_task_1_triggered()
{
    this->on_pushButton_1_clicked();
}

void MainWindow::on_action_task_2_triggered()
{
    this->on_pushButton_2_clicked();
}

void MainWindow::on_action_task_3_triggered()
{
    this->on_pushButton_3_clicked();
}

void MainWindow::on_action_exit_triggered()
{
    this->on_pushButton_exit_clicked();
}
