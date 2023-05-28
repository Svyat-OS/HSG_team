
#include <QtTest>
#include "../func_for_server.h"

// add necessary includes here

class task3_unit_test : public QObject
{
    Q_OBJECT

public:
    task3_unit_test();
    ~task3_unit_test();

private slots:
    void test_case1();
    void test_case2();

};

task3_unit_test::task3_unit_test()
{

}

task3_unit_test::~task3_unit_test()
{

}

void task3_unit_test::test_case1()
{
    QStringList params;
    params.push_back("22"); // ответ пользователя верный
    params.push_back("19");
    params.push_back("30");
    params.push_back("29");
    params.push_back("13");
    params.push_back("23");
    params.push_back("18");
    params.push_back("30");
    params.push_back("4");
    params.push_back("25");
    params.push_back("29");



    QCOMPARE(task3(params, 0), "Ответ верный");
}

void task3_unit_test::test_case2()
{
    QStringList params;
    params.push_back("0"); // ответ пользователя неверный
    params.push_back("19");
    params.push_back("30");
    params.push_back("29");
    params.push_back("13");
    params.push_back("23");
    params.push_back("18");
    params.push_back("30");
    params.push_back("4");
    params.push_back("25");
    params.push_back("29");



    QCOMPARE(task3(params, 0), "Ответ неверный, правильный ответ: 22");
}

QTEST_APPLESS_MAIN(task3_unit_test)

#include "tst_task3_unit_test.moc"
