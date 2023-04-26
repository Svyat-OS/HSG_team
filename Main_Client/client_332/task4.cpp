#include "task4.h"
#include "ui_task4.h"

task4::task4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task4)
{
    ui->setupUi(this);
}

task4::~task4()
{
    delete ui;
}
