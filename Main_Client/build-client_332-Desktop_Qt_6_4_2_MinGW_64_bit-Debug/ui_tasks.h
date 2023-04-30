/********************************************************************************
** Form generated from reading UI file 'tasks.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKS_H
#define UI_TASKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tasks
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *tasks)
    {
        if (tasks->objectName().isEmpty())
            tasks->setObjectName("tasks");
        tasks->resize(303, 298);
        pushButton = new QPushButton(tasks);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 80, 101, 41));
        pushButton_2 = new QPushButton(tasks);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 160, 101, 41));
        pushButton_3 = new QPushButton(tasks);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 80, 101, 41));
        pushButton_4 = new QPushButton(tasks);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(190, 160, 101, 41));
        pushButton_5 = new QPushButton(tasks);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(100, 230, 101, 41));
        pushButton_6 = new QPushButton(tasks);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(100, 20, 101, 41));

        retranslateUi(tasks);

        QMetaObject::connectSlotsByName(tasks);
    } // setupUi

    void retranslateUi(QWidget *tasks)
    {
        tasks->setWindowTitle(QCoreApplication::translate("tasks", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("tasks", "\320\240\320\265\321\210\320\270\321\202\321\214 1 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tasks", "\320\240\320\265\321\210\320\270\321\202\321\214 3 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton_3->setText(QCoreApplication::translate("tasks", "\320\240\320\265\321\210\320\270\321\202\321\214 2 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton_4->setText(QCoreApplication::translate("tasks", "\320\240\320\265\321\210\320\270\321\202\321\214 4 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton_5->setText(QCoreApplication::translate("tasks", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pushButton_6->setText(QCoreApplication::translate("tasks", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tasks: public Ui_tasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKS_H
