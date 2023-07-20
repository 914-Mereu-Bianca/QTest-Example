#ifndef _TESTGUI_H_
#define _TESTGUI_H_

#include <QObject>


class TestGUI : public QObject {
    Q_OBJECT
    
private slots:

    void testGUI();
    void testKeyActionWidget();
    void testEventKeyAction();
    void testTableWidget();
    void testButtonClicked();
};

#endif