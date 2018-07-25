#include "bgmthread.h"



bgmThread::bgmThread(QObject *parent) : QObject(parent)
{

}

void bgmThread::play()
{

    effect.setSource(QUrl::fromLocalFile(":/source/music/bgm.wav"));

    effect.setLoopCount(QSoundEffect::Infinite);

    effect.setVolume(0.5f);

    effect.play();
}
