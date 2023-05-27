#ifndef REG_H
#define REG_H

#include <QWidget>
#include "tasks.h"
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class reg;
}

class reg : public QWidget
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::reg *ui;
};

#endif // REG_H
