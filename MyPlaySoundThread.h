#pragma once
#include <Windows.h>
#include <QThread>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")

class CMyPlaySoundThread:public QThread
{
    Q_OBJECT

public:
    static CMyPlaySoundThread* signle()
    {
        static CMyPlaySoundThread s;
        return &s;
    }
    ~CMyPlaySoundThread();
    void run();

public slots:
    void onPlaySoundHandle(int bPlay);

private :
    CMyPlaySoundThread();
    int _bPlay;
};
