#ifndef TASK1_H
#define TASK1_H

#include <QWidget>
#include "ui_tasks.h"
#include <QMessageBox>
#include <QString>
#include "tasks.h"

namespace Ui {
class task1;
}

class task1 : public QWidget
{
    Q_OBJECT

public:
    explicit task1(QWidget *parent = nullptr);
    ~task1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::task1 *ui;
};

#endif // TASK1_H
