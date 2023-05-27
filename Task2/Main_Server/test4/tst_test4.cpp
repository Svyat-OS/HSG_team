#include <QtTest>
#include "../Server/HSG_team-dev_ilya/server/func_for_server.h"
// add necessary includes here

class test4 : public QObject
{
    Q_OBJECT

public:
    test4();
    ~test4();

private slots:
    void test_case1();

};

test4::test4()
{

}

test4::~test4()
{

}

void test4::test_case1()
{
    QStringList params1;
    params1.push_back("6257653843146169");
    params1.push_back("6");
    params1.push_back("1");
    params1.push_back("4");
    params1.push_back("3");
    params1.push_back("6");
    params1.push_back("5");
    params1.push_back("6");


    QCOMPARE(task2(params1, 0),"Ответ верный");


}

QTEST_APPLESS_MAIN(test4)

#include "tst_test4.moc"
