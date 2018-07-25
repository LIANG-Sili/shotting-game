#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QVector>
#include "bullet.h"

class weapon : public QObject
{
    Q_OBJECT
public:

    // 设定子弹数量 相对初始位置 子弹种类 子弹方向

    int num;
    QVector<int>locate_x;
    QVector<int>locate_y;

    QVector<int>bulletIDls;

    QVector<float>run_x;
    QVector<float>run_y;

    int weaponID;

    enum{
        weapon_enemyshotline = 0,
        weapon_usershotone,
        weapon_usershottwo,
        weapon_usershotthree,
        weapon_usershotfan,
        weapon_usershottritwotrack,
        weapon_enemyshottrifan,
        weapon_enemyshotlinetrack,
        weapon_enemyshottwo,
        weapon_enemyshottwotrack,
        weapon_enemyshotcircle,
        weapon_enemyshotswiftonetrack,
        weapon_enemyshottritwotrack,
        weapon_enemycircleshot,
        weapon_enemyrightcircle,
        weapon_enemyleftcircle,
        weapon_enemymiddlecircle,
    };//weaponID 以后从weapon派生出的类的名字都放在这里

    explicit weapon(QObject *parent = nullptr);

signals:

public slots:
};



#endif // WEAPON_H
