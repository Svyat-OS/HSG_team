/********************************************************************************
** Form generated from reading UI file 'task1.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_H
#define UI_TASK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task1
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *task1)
    {
        if (task1->objectName().isEmpty())
            task1->setObjectName("task1");
        task1->resize(404, 253);
        pushButton = new QPushButton(task1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 10, 221, 61));
        pushButton_2 = new QPushButton(task1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 150, 101, 18));
        pushButton_3 = new QPushButton(task1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(250, 150, 111, 20));
        lineEdit = new QLineEdit(task1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(250, 100, 113, 20));
        label = new QLabel(task1);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 100, 131, 16));

        retranslateUi(task1);

        QMetaObject::connectSlotsByName(task1);
    } // setupUi

    void retranslateUi(QWidget *task1)
    {
        task1->setWindowTitle(QCoreApplication::translate("task1", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("task1", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\203\321\201\320\273\320\276\320\262\320\270\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("task1", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pushButton_3->setText(QCoreApplication::translate("task1", "\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("task1", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task1: public Ui_task1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_H
