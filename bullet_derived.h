#ifndef BULLET_DERIVED_H
#define BULLET_DERIVED_H

#include "bullet.h"

class bullet_nottrack_10 : public bullet
{

public:

    bullet_nottrack_10(int X,int Y,float V_x, float V_y,int f);
};



class bullet_track_10 : public bullet
{
    //这个v要设的时候根据坐标

public:



    bullet_track_10(int X,int Y,float V_x, float V_y,int f);
};

class bullet_unottrack_10 : public bullet
{
public:

    bullet_unottrack_10(int X,int Y,float V_x, float V_y,int f);

};

class bullet_utrack_10 : public bullet
{
public:

    bullet_utrack_10(int X,int Y,float V_x, float V_y,int f);
};

class bullet_slow_12 : public bullet
{
public:
    bullet_slow_12(int X,int Y,float V_x, float V_y,int f);
};










#endif // BULLET_DERIVED_H
