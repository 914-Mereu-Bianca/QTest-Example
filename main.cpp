#include <QtTest>
#include <QApplication>
#include "tests/test.h"
#include "tests/testGUI.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    int status = 0;
    status |= QTest::qExec(new TestGUI, argc, argv);
    status |= QTest::qExec(new Test, argc, argv);

    return status;
}