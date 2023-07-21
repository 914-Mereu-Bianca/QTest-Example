#include <QtTest/QtTest>
#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QMouseEvent>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QCoreApplication>
#include "test.h"

// basic examples 

void Test::testAddNr() {
    QVERIFY(1+1==2);
}

void Test::testCompare()
{
    QCOMPARE(10, 10);
}

void Test::testFailure()
{
    int value = 10;
    QEXPECT_FAIL("", "Expected failure: Value is not equal to 0", Continue);
    QCOMPARE(value, 0);
}

void Test::testException()
{
    QVERIFY_THROWS_EXCEPTION(std::runtime_error, throw std::runtime_error("Test exception"));
}


//QTEST_MAIN(Test)
static Test TEST_QSTRING;