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

/**
 * @brief Класс задача №2 - Декодер Прюффера
 */
class task2 : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса task2
     * @param QWidget * pointer = nullptr - Аргумент по умолчанию
     */
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
