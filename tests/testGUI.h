#ifndef _TESTGUI_H_
#define _TESTGUI_H_

#include "../suite.h"

class TestGUI : public TestSuite {
    Q_OBJECT
    
public:
    using TestSuite::TestSuite;

private slots:

    void testGUI();
    void testKeyActionWidget();
    void testEventKeyAction();
    void testTableWidget();
    void testButtonClicked();
};

#endif