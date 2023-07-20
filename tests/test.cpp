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


// GUI examples


void Test::testGUI() // the test from the official page: https://doc.qt.io/qt-6/qttestlib-tutorial3-example.html
{
    QLineEdit lineEdit;
    
    QTest::keyClicks(&lineEdit, "hello world");

    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void Test::testEventKeyAction()
{
    /*
    QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
    
    QApplication::sendEvent(QApplication::focusWidget(), &keyEvent);  // signal 11 (SIGSEGV), code 1, for address 0x0000000000000008 

    QVERIFY(keyEvent.isAccepted());
    */
}

void Test::testKeyActionWidget() 
{
    QWidget widget;

    QTest::keyPress(&widget, Qt::Key_Enter);  //simulating pressing Enter key

    QVERIFY(widget.isEnabled()); //check if the key action is triggered
}


void Test::testTableWidget()
{
    QTableWidget tableWidget;
    tableWidget.setRowCount(1);
    tableWidget.setColumnCount(1);
    
    QTableWidgetItem *item = new QTableWidgetItem(QString("item"));
    tableWidget.setItem( 0, 0, item);
    
    QString s = tableWidget.model()->data(tableWidget.model()->index(0,0)).toString();

    QCOMPARE(s, QString("item"));
}

void Test::testButtonClicked()
{
    QPushButton button("Button");

    QCOMPARE(button.text(), QString("Button"));

    QSignalSpy clickedSpy(&button, SIGNAL(clicked()));
    
    QTest::mouseClick(&button, Qt::LeftButton);

    QTest::qWait(50);

    QCOMPARE(clickedSpy.count(), 1);
}

QTEST_MAIN(Test)

