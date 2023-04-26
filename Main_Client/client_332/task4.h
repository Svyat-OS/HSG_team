#ifndef TASK4_H
#define TASK4_H

#include <QWidget>
#include "ui_tasks.h"

namespace Ui {
class task4;
}

class task4 : public QWidget
{
    Q_OBJECT

public:
    explicit task4(QWidget *parent = nullptr);
    ~task4();

private:
    Ui::task4 *ui;
};

#endif // TASK4_H
