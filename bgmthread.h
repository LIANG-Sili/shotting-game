#ifndef BGMTHREAD_H
#define BGMTHREAD_H

#include <QObject>
#include <QSoundEffect>
#include <QDebug>

class bgmThread : public QObject
{
    Q_OBJECT
public:
    explicit bgmThread(QObject *parent = nullptr);

    void play();

    QSoundEffect effect;
signals:

};

#endif // BGMTHREAD_H
