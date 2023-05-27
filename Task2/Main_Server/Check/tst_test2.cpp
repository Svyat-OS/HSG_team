#include <QtTest>
#include "C:/Server/HSG_team-dev_ilya/Main_Server/server/func_for_server.h"
// add necessary includes here

class Test2 : public QObject
{
    Q_OBJECT

public:
    Test2();
    ~Test2();

private slots:
    void test_case1();
    void test_case2();

};

Test2::Test2()
{

}

Test2::~Test2()
{

}

void Test2::test_case1()
{
    QStringList params1;
    params1.push_back("9146342352759789");

    params1.push_back("9432579");

    QCOMPARE(task2(params1, 0),"Ответ верный");

}


void Test2::test_case2()
{
    QStringList params2;
    params2.push_back("9146343527789468");

    params2.push_back("9432579");

    QCOMPARE(task2(params2, 0),"Ответ неверный, правильный ответ: 9146342352759789");

}

QTEST_APPLESS_MAIN(Test2)

#include "tst_test2.moc"
