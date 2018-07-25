#include "user.h"

int user::clearscreen_num = 3;

user::user(int X,int Y)
{
    x = X;
    y = Y;

    imagepath = ":/source/image/enemy/e1.png";
    W = 128;
    H = 160;

    health = 100;

    wp = new weapon_usershotone;

    addnum = 0;
    changeitems_num = 0;
}


void user::slot_healthloss(int damage)
{
    health -= damage;
    emit healthbarRefresh(health);
    if(health <= 0)
    {
        emit gameover();
    }
}


void user::slot_getitems(int flag){

    if(flag == items::items_healthrecover )
    {
        health += 40;
        if(health >= 100)
            health = 100;

        emit healthbarRefresh(health);
    }
    else if(flag == items::items_changeweapon)
    {
        changeitems_num++;
        if(wp->weaponID == weapon::weapon_usershotone&&changeitems_num==3)
        {
            delete wp;

            wp = new weapon_usershottwo();
        }
        else if(wp->weaponID == weapon :: weapon_usershottwo&&changeitems_num==6)
        {
            delete wp;

            wp = new weapon_usershotthree();
        }
        else if(wp->weaponID == weapon :: weapon_usershotthree&&changeitems_num==10)
        {
            delete wp;

            wp = new weapon_usershotfan();
        }
        else if(wp->weaponID == weapon :: weapon_usershotfan&&changeitems_num==15)
        {
            delete wp;

            wp = new weapon_usershottritwotrack();
        }
    }
    else if(flag == items::items_addclearnum)
    {
        if(clearscreen_num<=9)
        {
            addnum++;
        }
        if(addnum == 3)
        {
            addnum = 0;
            clearscreen_num++;
            emit changeclearnumlabel(clearscreen_num);
        }
    }

}
