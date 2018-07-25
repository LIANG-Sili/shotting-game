#ifndef USER_H
#define USER_H

#include <QObject>
#include "flight.h"
#include "weapon_derived.h"
#include "other_items.h"

class user : public flight
{
    Q_OBJECT
public:
    explicit user(int x,int y);

    static int clearscreen_num;

    int addnum;

    int changeitems_num;

signals:

    void changeclearnumlabel(int);
    void healthbarRefresh(int);
    void gameover();

public slots:
    void slot_healthloss(int);
    void slot_getitems(int);
};

#endif // USER_H
