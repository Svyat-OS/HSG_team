#ifndef TASKS_H
#define TASKS_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"
#include "reg.h"
#include <QDebug>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

namespace Ui {
class tasks;
}

/**
 * @brief Класс окно с задачами
 */
class tasks : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса tasks
     * @param QWidget * pointer = nullptr - Аргумент по умолчанию
     */
    explicit tasks(QWidget *parent = nullptr);
    ~tasks();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::tasks *ui;
};

#endif // TASKS_H
