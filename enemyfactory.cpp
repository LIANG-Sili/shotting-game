#include "enemyfactory.h"

enemyfactory::enemyfactory(QObject *parent) : QObject(parent)
{

}


void enemyfactory::slot_addenemy(int ID, int AppearPos)
{
    if(ID == enemy::enemy_littlebrother)
    {
        ls.push_back(new enemy_littlebrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_secondbrother)
    {
        ls.push_back(new enemy_secondbrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_thirdbrother)
    {
        ls.push_back(new enemy_thirdbrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_4thbrother)
    {
        ls.push_back(new enemy_4thbrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_5thbrother)
    {
        ls.push_back(new enemy_5thbrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_6thbrother)
    {
        ls.push_back(new enemy_6thbrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_7thbrother)
    {
        ls.push_back(new enemy_7thbrother(AppearPos,0,0,1));
    }
    if(ID == enemy::enemy_father)
    {
        ls.push_back(new enemy_father(AppearPos,0,1,0));
    }

}

void enemyfactory::slot_ehealthloss(int i,int damage)
{
    ls[i]->health -= damage;
    if(ls[i]->health <= 0)
    {
        emit GetScore(ls[i]->enemyID);
        emit appearitems(ls[i]->x,ls[i]->y);
        delete ls[i];
        ls.erase(ls.begin()+i);
    }
    if(ls[i]->enemyID == enemy::enemy_father && ls[i]->health <= 2333)
    {
        if(dynamic_cast<enemy_father*>(ls[i])->shadowappear == false)
        {
            dynamic_cast<enemy_father*>(ls[i])->shadowappear = true;
            ls[i]->W = 385;
            ls[i] -> x -= 165;
            ls[i]->imagepath = ":/source/image/enemy/boss2.png";
        }
    }
}
