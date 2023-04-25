#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_exit_clicked();

    void on_action_task_1_triggered();

    void on_action_task_2_triggered();

    void on_action_task_3_triggered();

    void on_action_exit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
