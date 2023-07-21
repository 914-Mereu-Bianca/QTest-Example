#ifndef _SUITE_H_
#define _SUITE_H_

#include <QObject>
#include <vector>

class TestSuite: public QObject
{
public:
     TestSuite();

     static std::vector<QObject*> & suite();
};

#endif