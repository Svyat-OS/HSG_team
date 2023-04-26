/********************************************************************************
** Form generated from reading UI file 'task2.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK2_H
#define UI_TASK2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task2
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QWidget *task2)
    {
        if (task2->objectName().isEmpty())
            task2->setObjectName("task2");
        task2->resize(373, 238);
        lineEdit = new QLineEdit(task2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(230, 120, 113, 20));
        pushButton = new QPushButton(task2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 30, 181, 61));
        pushButton_2 = new QPushButton(task2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 170, 80, 18));
        pushButton_3 = new QPushButton(task2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(260, 170, 81, 20));
        label = new QLabel(task2);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 120, 121, 16));

        retranslateUi(task2);

        QMetaObject::connectSlotsByName(task2);
    } // setupUi

    void retranslateUi(QWidget *task2)
    {
        task2->setWindowTitle(QCoreApplication::translate("task2", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("task2", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\203\321\201\320\273\320\276\320\262\320\270\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("task2", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pushButton_3->setText(QCoreApplication::translate("task2", "\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("task2", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};



QT_END_NAMESPACE

#endif // UI_TASK2_H
