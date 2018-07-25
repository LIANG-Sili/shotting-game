#ifndef OTHER_ITEMS_H
#define OTHER_ITEMS_H

#include "items.h"

class items_healthrecover : public items
{

public:
    items_healthrecover(int X,int Y,float V_x, float V_y,int f);
};


class items_changeweapon : public items
{

public:
    items_changeweapon(int X,int Y,float V_x, float V_y,int f);
};

class items_addclearnum :public items
{
public:
    items_addclearnum(int X,int Y,float V_x, float V_y,int f);
};
#endif // OTHER_ITEMS_H
