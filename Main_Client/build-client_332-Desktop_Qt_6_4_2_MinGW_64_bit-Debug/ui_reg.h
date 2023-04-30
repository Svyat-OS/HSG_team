/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_H
#define UI_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName("reg");
        reg->resize(398, 265);
        label = new QLabel(reg);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 0, 71, 51));
        label_2 = new QLabel(reg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 101, 16));
        label_3 = new QLabel(reg);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 111, 16));
        label_4 = new QLabel(reg);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 130, 121, 16));
        label_5 = new QLabel(reg);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 160, 131, 16));
        lineEdit = new QLineEdit(reg);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 70, 113, 20));
        lineEdit_2 = new QLineEdit(reg);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(270, 100, 113, 20));
        lineEdit_3 = new QLineEdit(reg);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(270, 130, 113, 20));
        lineEdit_4 = new QLineEdit(reg);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(270, 160, 113, 20));
        pushButton = new QPushButton(reg);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 200, 101, 21));
        pushButton_2 = new QPushButton(reg);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 200, 111, 21));

        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QWidget *reg)
    {
        reg->setWindowTitle(QCoreApplication::translate("reg", "Form", nullptr));
        label->setText(QCoreApplication::translate("reg", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("reg", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("reg", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\321\207\321\202\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("reg", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("reg", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("reg", "\320\222\321\213\321\205\320\276\320\264 \320\262 \320\234\320\265\320\275\321\216", nullptr));
        pushButton_2->setText(QCoreApplication::translate("reg", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H
