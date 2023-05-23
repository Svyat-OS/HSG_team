#include <QtTest>
#include "../server/func_for_server.h"

// add necessary includes here

class task_test : public QObject
{
    Q_OBJECT

public:
    task_test();
    ~task_test();

private slots:
    void test_case1();

};

task_test::task_test()
{

}

task_test::~task_test()
{
}

void task_test::test_case1()
{
    QStringList params1;
    params1.push_back("6466724");
    params1.push_back("4");
    params1.push_back("2");
    params1.push_back("1");
    params1.push_back("5");
    params1.push_back("6");
    params1.push_back("7");
    params1.push_back("3");
    params1.push_back("9");
    params1.push_back("8");
    QCOMPARE(task1(params1, 0),"Ответ верный");
    QStringList params2;
    params2.push_back("2999214");
    params2.push_back("2");
    params2.push_back("1");
    params2.push_back("5");
    params2.push_back("6");
    params2.push_back("9");
    params2.push_back("3");
    params2.push_back("4");
    params2.push_back("8");
    params2.push_back("7");
    QCOMPARE(task1(params2, 0),"Ответ неверный, правильный ответ: 2999213");
}

QTEST_APPLESS_MAIN(task_test)

#include "tst_task_test.moc"
