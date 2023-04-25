#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class authWindow;
}

class authWindow : public QWidget
{
    Q_OBJECT

public:
    explicit authWindow(QWidget *parent = nullptr);
    ~authWindow();

private slots:
    void on_button_sign_up_clicked();

    void on_button_sign_in_clicked();

    void on_button_change_clicked();

private:
    Ui::authWindow *ui;

    void change_mode(bool mode);
};

#endif // AUTHWINDOW_H
