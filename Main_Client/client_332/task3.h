#ifndef TASK3_H
#define TASK3_H

#include <QWidget>
#include "ui_tasks.h"

namespace Ui {
class task3;
}

class task3 : public QWidget
{
    Q_OBJECT

public:
    explicit task3(QWidget *parent = nullptr);
    ~task3();

private:
    Ui::task3 *ui;
};

#endif // TASK3_H
