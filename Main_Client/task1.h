#ifndef TASK1_H
#define TASK1_H

#include <QWidget>
#include "ui_tasks.h"
#include <QMessageBox>
#include <QString>
#include "random.h"
#include "tasks.h"
#include <QList>
#include <QSet>
#include <QDebug>

namespace Ui {
class task1;
}

/**
 * @brief Класс задача №1 - Кодер Прюффера
 */
class task1 : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса task1
     * @param QWidget * pointer = nullptr - Аргумент по умолчанию
     */
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
