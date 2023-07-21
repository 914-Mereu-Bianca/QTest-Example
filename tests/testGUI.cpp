#include <QtTest/QtTest>
#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QMouseEvent>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QCoreApplication>
#include "testGUI.h"

// GUI examples

void TestGUI::testGUI() // the test from the official page: https://doc.qt.io/qt-6/qttestlib-tutorial3-example.html
{
    QLineEdit lineEdit;
    
    QTest::keyClicks(&lineEdit, "hello world");

    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void TestGUI::testEventKeyAction()
{
    /*
    QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
    
    QApplication::sendEvent(QApplication::focusWidget(), &keyEvent);  // signal 11 (SIGSEGV), code 1, for address 0x0000000000000008 

    QVERIFY(keyEvent.isAccepted());
    */
}

void TestGUI::testKeyActionWidget() 
{
    QWidget widget;

    QTest::keyPress(&widget, Qt::Key_Enter);  //simulating pressing Enter key

    QVERIFY(widget.isEnabled()); //check if the key action is triggered
}


void TestGUI::testTableWidget()
{
    
    QTableWidget tableWidget;
    tableWidget.setRowCount(1);
    tableWidget.setColumnCount(1);
    
    QTableWidgetItem *item = new QTableWidgetItem(QString("item"));
    tableWidget.setItem( 0, 0, item);
    
    QString s = tableWidget.model()->data(tableWidget.model()->index(0,0)).toString();

    QCOMPARE(s, QString("item"));
}

void TestGUI::testButtonClicked()
{
    QPushButton button("Button");

    QCOMPARE(button.text(), QString("Button"));

    QSignalSpy clickedSpy(&button, SIGNAL(clicked()));
    
    QTest::mouseClick(&button, Qt::LeftButton);

    QTest::qWait(50);

    QCOMPARE(clickedSpy.count(), 1);
}

//QTEST_MAIN(TestGUI)
static TestGUI TEST_QSTRING;
