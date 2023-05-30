#include <QtTest>
#include "..\server\func_for_server.h"

class task4_unit_test : public QObject
{
    Q_OBJECT

public:
    task4_unit_test();
    ~task4_unit_test();

private slots:
    void test_case1();
    void test_case2();

};

task4_unit_test::task4_unit_test()
{

}

task4_unit_test::~task4_unit_test()
{

}

void task4_unit_test::test_case1()
{
    QStringList params;
    params.push_back("8"); // ответ студента
    params.push_back("2");
    params.push_back("5");
    params.push_back("3");
    params.push_back("1");
    params.push_back("1");
    params.push_back("1");
    params.push_back("5");
    params.push_back("1");
    params.push_back("2");

    QCOMPARE(task4(params, 0), "Ответ верный");
}

void task4_unit_test::test_case2()
{
    QStringList params;
    params.push_back("999"); // ответ студента
    params.push_back("2");
    params.push_back("5");
    params.push_back("3");
    params.push_back("1");
    params.push_back("1");
    params.push_back("1");
    params.push_back("5");
    params.push_back("1");
    params.push_back("2");

    QCOMPARE(task4(params, 0), "Ответ неверный, правильный ответ 8");
}

QTEST_APPLESS_MAIN(task4_unit_test)

#include "tst_task4_unit_test.moc"
