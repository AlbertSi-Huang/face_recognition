#ifndef XINITTHREAD_H
#define XINITTHREAD_H
#include <QThread>

class XInitThread : public QThread
{
    Q_OBJECT

public:
    XInitThread();
    virtual void run();

private:
    void loadWriteList();

signals:
    void initSignal(int);
};

#endif // XINITTHREAD_H
