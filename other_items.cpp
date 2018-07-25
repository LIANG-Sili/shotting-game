#include "other_items.h"


items_healthrecover::items_healthrecover(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::items_healthrecover;

    flag = f;

    H = 40;
    W = 40;
    imagepath = ":/source/image/items/i3.png";

    pace = 13;
}


items_changeweapon::items_changeweapon(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::items_changeweapon;

    flag = f;

    H = 40;
    W = 40;
    imagepath = ":/source/image/items/i9.png";

    pace = 13;
}

items_addclearnum::items_addclearnum(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::items_addclearnum;

    flag = f;

    H = 40;
    W = 40;
    imagepath = ":/source/image/items/i6.png";

    pace = 13;
}
