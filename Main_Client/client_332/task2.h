#ifndef TASK2_H
#define TASK2_H

#include <QWidget>
#include "ui_tasks.h"
#include <QMessageBox>
#include <QString>
#include "tasks.h"

namespace Ui {
class task2;
}

class task2 : public QWidget
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    ~task2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::task2 *ui;
};

#endif // TASK2_H
