#ifndef TASK2_H
#define TASK2_H

#include <QWidget>
#include "ui_tasks.h"

namespace Ui {
class task2;
}

class task2 : public QWidget
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    ~task2();

private:
    Ui::task2 *ui;
};

#endif // TASK2_H
