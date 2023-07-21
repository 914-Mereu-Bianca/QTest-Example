#include <QtTest>
#include <QApplication>
#include "tests/test.h"
#include "tests/testGUI.h"
#include "suite.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    auto &suite = TestSuite::suite();
    for (auto it = suite.begin(); it != suite.end(); ++it) {
        runTest(*it);
    }
}