#include "task3.h"
#include "ui_task3.h"

task3::task3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);
}

task3::~task3()
{
    delete ui;
}
