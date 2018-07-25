#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <QObject>
#include "enemy_derived.h"
#include <QVector>
#include <QSoundEffect>

#include "header.h"

class enemyfactory : public QObject
{
    Q_OBJECT
public:
    explicit enemyfactory(QObject *parent = nullptr);



    QVector<enemy*> ls;
signals:
    void appearitems(int ,int);

    void GetScore(int);

public slots:
    void slot_addenemy(int, int AppearPos);
    void slot_ehealthloss(int , int);

};

#endif // ENEMYFACTORY_H
