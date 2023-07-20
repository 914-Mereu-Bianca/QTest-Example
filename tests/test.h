#ifndef _TEST_H_
#define _TEST_H_

#include <QObject>

class Test : public QObject {
    Q_OBJECT
    
private slots:
    void testAddNr();
    void testCompare();
    void testFailure();
    void testException();

};

#endif