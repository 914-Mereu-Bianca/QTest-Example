#ifndef _TEST_H_
#define _TEST_H_

#include "../suite.h"

class Test : public TestSuite {
    Q_OBJECT
    
public:
    using TestSuite::TestSuite;

private slots:
    void testAddNr();
    void testCompare();
    void testFailure();
    void testException();

};

#endif