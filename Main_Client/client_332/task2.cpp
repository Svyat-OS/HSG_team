#include "task2.h"
#include "ui_task2.h"

task2::task2(QWidget *parent) :
    QWidget(parent)
{
    ui->setupUi(this);
}

task2::~task2()
{
    delete ui;
}
