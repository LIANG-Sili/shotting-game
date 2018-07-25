#ifndef ITEMS_H
#define ITEMS_H

#include "crashobject.h"
#include <QVector>

class items : public crashObject
{

public:

    static QVector<items *> itemsls;

    enum{
        tools=0,
        hurtuser,
        hurtenemy,
        hurtboth
    }; //flag

    enum{
        bullet_nottrack_10=0,
        bullet_track_10,
        bullet_unottrack_10,
        bullet_utrack_10,
        bullet_slow_12,
    };//itemsID 以后从items派生出的类的名字都放在这里

    enum{

        items_healthrecover = 0,
        items_changeweapon,
        items_addclearnum,







        no_items,
        items_end,
    };//


    int flag;
    items();

    int itemsID;

protected:

};

#endif // ITEMS_H
