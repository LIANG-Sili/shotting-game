#include "bullet_derived.h"

bullet_nottrack_10::bullet_nottrack_10(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::bullet_nottrack_10;

    flag = f;

    H = 30;
    W = 30;
    imagepath = ":/source/image/bullets/b9.png";
    damage = 10;
    pace = 30;
}



bullet_track_10::bullet_track_10(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::bullet_track_10;

    flag = f;

    H = 30;
    W = 30;
    imagepath = ":/source/image/bullets/b5.png";
    damage = 10;
    pace = 20;
}

bullet_unottrack_10::bullet_unottrack_10(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::bullet_unottrack_10;

    flag = f;

    H = 30;
    W = 30;
    imagepath = ":/source/image/bullets/b8.png";
    damage = 10;
    pace = 35;

}

bullet_utrack_10::bullet_utrack_10(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::bullet_utrack_10;

    flag = f;

    H = 30;
    W = 30;
    imagepath = ":/source/image/bullets/b4.png";
    damage = 10;
    pace = 40;
}

bullet_slow_12::bullet_slow_12(int X,int Y,float V_x, float V_y,int f)
{
    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    itemsID = items::bullet_slow_12;

    flag = f;

    H = 30;
    W = 30;
    imagepath = ":/source/image/bullets/b13.png";
    damage = 12;
    pace = 12;
}
