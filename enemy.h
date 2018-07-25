#ifndef ENEMY_H
#define ENEMY_H

#include "flight.h"

class enemy : public flight
{


protected:


    //运动轨迹
public:
   enemy();

   int enemyID;

   enum{                            //enemyID
    enemy_littlebrother = 0,
    enemy_secondbrother,
       enemy_thirdbrother,
       enemy_4thbrother,
       enemy_5thbrother,
       enemy_6thbrother,
       enemy_7thbrother,
       enemy_father

   };


};

#endif // ENEMY_H
