#ifndef BULLET_H
#define BULLET_H

#include "items.h"

class bullet : public items //bullet是由items派生的直接写在itemsID里面
{

public:
    bullet();


    int damage;

};



#endif // BULLET_H
