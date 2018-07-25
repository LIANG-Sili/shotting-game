#include "enemy_derived.h"


enemy_littlebrother::enemy_littlebrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_littlebrother;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 15;
    pace = 5;

    imagepath = ":/source/image/enemy/e2.png";

    wp = new weapon_enemyshotline;
}

enemy_secondbrother::enemy_secondbrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_secondbrother;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 25;
    pace = 5;

    imagepath = ":/source/image/enemy/e3.png";

    wp = new weapon_enemyshottwo;
}

enemy_thirdbrother::enemy_thirdbrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_thirdbrother;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 50;
    pace = 2;

    imagepath = ":/source/image/enemy/e4.png";

    wp = new weapon_enemyshotlinetrack;
}

enemy_4thbrother::enemy_4thbrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_4thbrother;


    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 100;
    pace = 1;

    imagepath = ":/source/image/enemy/e5.png";

    wp = new weapon_enemyshottwotrack;
}

enemy_5thbrother::enemy_5thbrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_5thbrother;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 300;
    pace = 0;

    imagepath = ":/source/image/enemy/e6.png";

    wp = new weapon_enemyshottrifan();
}

enemy_6thbrother::enemy_6thbrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_6thbrother;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 500;
    pace = 0;

    imagepath = ":/source/image/enemy/e7.png";

    wp = new weapon_enemyshotcircle();
}

enemy_7thbrother::enemy_7thbrother(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_7thbrother;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 160;
    W = 128;
    health = 1000;
    pace = 0;

    imagepath = ":/source/image/enemy/e14.png";

    wp = new weapon_enemyshotswiftonetrack();
}


enemy_father::enemy_father(int X,int Y,float V_x, float V_y)
{
    enemyID = enemy::enemy_father;

    x = X;
    y = Y;
    run_x = V_x;
    run_y = V_y;

    H = 354;
    W = 220;
    health = 3000;
    pace = 2;

    shadowappear = false; //

    imagepath = ":/source/image/enemy/boss1.png";   //  000

    wp = new weapon_enemyshotswiftonetrack();
}
