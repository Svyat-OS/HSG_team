/********************************************************************************
** Form generated from reading UI file 'task3.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK3_H
#define UI_TASK3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task3
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QWidget *task3)
    {
        if (task3->objectName().isEmpty())
            task3->setObjectName("task3");
        task3->resize(404, 305);
        lineEdit = new QLineEdit(task3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(250, 160, 113, 20));
        pushButton = new QPushButton(task3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 70, 181, 61));
        pushButton_2 = new QPushButton(task3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 210, 80, 18));
        pushButton_3 = new QPushButton(task3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(280, 210, 81, 20));
        label = new QLabel(task3);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 160, 121, 16));

        retranslateUi(task3);

        QMetaObject::connectSlotsByName(task3);
    } // setupUi

    void retranslateUi(QWidget *task3)
    {
        task3->setWindowTitle(QCoreApplication::translate("task3", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("task3", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\203\321\201\320\273\320\276\320\262\320\270\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("task3", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pushButton_3->setText(QCoreApplication::translate("task3", "\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("task3", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task3: public Ui_task3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK3_H
