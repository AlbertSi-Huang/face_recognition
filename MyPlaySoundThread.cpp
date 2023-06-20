#include "MyPlaySoundThread.h"

CMyPlaySoundThread::~CMyPlaySoundThread()

{

}
void CMyPlaySoundThread::run()
{
    msleep(200);
    while(true)
    {
        msleep(500);
        std::string str = "./resource/helmet.wav";
        if(_bPlay == -1)
        {
            continue;
        }else if(_bPlay == 1)
        {
            str = "./resource/coat.wav";
        }else if(_bPlay == 2)
        {
            str = "./resource/helmet_coat.wav";
        }
        _bPlay = -1;
        PlaySoundA(str.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void CMyPlaySoundThread::onPlaySoundHandle(int bPlay)
{
    _bPlay = bPlay;
}

CMyPlaySoundThread::CMyPlaySoundThread():_bPlay(-1)
{

}
