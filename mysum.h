#ifndef MYSUM
#define MYSUM

#include <QObject>
class Mysum:public QObject
{
Q_OBJECT
public:
    Mysum(QObject *parent=0):QObject(parent),s(0){}
    ~Mysum(){}
    Q_INVOKABLE int mysum(int a,int b)
    {
        s++;
        return a+b+s;
    }
private:
    int s;
};

#endif // MYSUM

