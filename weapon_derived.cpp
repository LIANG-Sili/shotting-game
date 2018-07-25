#include "weapon_derived.h"

weapon_enemyshotline::weapon_enemyshotline()
{
    num = 1;
    bulletIDls.push_back(items::bullet_nottrack_10);

    run_x.push_back(0);
    run_y.push_back(1);

    locate_x.push_back(0);
    locate_y.push_back(0);


    weaponID = weapon::weapon_enemyshotline;
}




weapon_usershotone::weapon_usershotone()
{
    weaponID = weapon::weapon_usershotone;

    num = 1;
    bulletIDls.push_back(items::bullet_unottrack_10);

    run_x.push_back(0);
    run_y.push_back(-1);

    locate_x.push_back(0);
    locate_y.push_back(0);
}


weapon_usershottwo::weapon_usershottwo()
{
    weaponID = weapon::weapon_usershottwo;

    num = 2;
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_x.push_back(0);
    run_y.push_back(-1);

    locate_x.push_back(-40);
    locate_y.push_back(0);

    locate_x.push_back(40);
    locate_y.push_back(0);

}

weapon_usershotthree::weapon_usershotthree()
{
    weaponID = weapon::weapon_usershotthree;

    num = 3;
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_x.push_back(0);
    run_y.push_back(-1);

    locate_x.push_back(-60);
    locate_y.push_back(0);

    locate_x.push_back(60);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);
}

weapon_usershotfan::weapon_usershotfan()
{
    weaponID = weapon::weapon_usershotfan;

    num = 5;

    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_y.push_back(-0.66);
    run_x.push_back(0.33);

    run_y.push_back(-0.66);
    run_x.push_back(-0.33);

    run_x.push_back(0.66);
    run_y.push_back(-0.33);

    run_x.push_back(-0.66);
    run_y.push_back(-0.33);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);
}

weapon_enemyshottrifan::weapon_enemyshottrifan()
{
    weaponID = weapon::weapon_enemyshottrifan;

    num = 3;

    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);

    run_x.push_back(0);
    run_y.push_back(1);

    run_y.push_back(0.66);
    run_x.push_back(-0.33);

    run_y.push_back(0.66);
    run_x.push_back(0.33);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);
}

weapon_enemyshotlinetrack::weapon_enemyshotlinetrack()
{
    weaponID = weapon::weapon_enemyshotlinetrack;

    bulletIDls.push_back(items::bullet_track_10);

    num = 1;

    run_x.push_back(0);
    run_y.push_back(1);

    locate_x.push_back(0);
    locate_y.push_back(0);

}

weapon_enemyshottwo::weapon_enemyshottwo()
{
    weaponID = weapon::weapon_enemyshottwo;

    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);

    num = 2;

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    locate_x.push_back(-30);
    locate_y.push_back(0);

    locate_x.push_back(30);
    locate_y.push_back(0);

}

weapon_enemyshottwotrack::weapon_enemyshottwotrack()
{
    weaponID = weapon::weapon_enemyshottwotrack;

    bulletIDls.push_back(items::bullet_track_10);
    bulletIDls.push_back(items::bullet_track_10);

    num = 2;

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    locate_x.push_back(-30);
    locate_y.push_back(0);

    locate_x.push_back(30);
    locate_y.push_back(0);

}

weapon_enemyshotcircle::weapon_enemyshotcircle()
{
    int H = 80;
    int W = 64;

    weaponID = weapon::weapon_enemyshotcircle;

    num = 8;

    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);

    run_x.push_back(-1);
    run_y.push_back(0);

    run_x.push_back(-0.5);
    run_y.push_back(0.5);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0.5);
    run_y.push_back(0.5);

    run_x.push_back(1);
    run_y.push_back(0);

    run_x.push_back(0.5);
    run_y.push_back(-0.5);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_x.push_back(-0.5);
    run_y.push_back(-0.5);

    locate_x.push_back(0);
    locate_y.push_back(-1.2*H);

    locate_x.push_back(-0.5*W);
    locate_y.push_back(-H);

    locate_x.push_back(-0.7*W);
    locate_y.push_back(-0.5*H);

    locate_x.push_back(-0.5*W);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0.2*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(0);

    locate_x.push_back(0.7*W);
    locate_y.push_back(-0.5*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(-H);


}


weapon_enemyshotswiftonetrack::weapon_enemyshotswiftonetrack()
{
    weaponID = weapon::weapon_enemyshotswiftonetrack;

    bulletIDls.push_back(items::bullet_track_10);
    bulletIDls.push_back(items::bullet_track_10);
    bulletIDls.push_back(items::bullet_track_10);
    bulletIDls.push_back(items::bullet_track_10);
    bulletIDls.push_back(items::bullet_track_10);

    num = 5;

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);
}

weapon_enemyshottritwotrack::weapon_enemyshottritwotrack()
{
    weaponID = weapon::weapon_enemyshottritwotrack;

    num = 5;

    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_nottrack_10);
    bulletIDls.push_back(items::bullet_track_10);
    bulletIDls.push_back(items::bullet_track_10);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);

    locate_x.push_back(-40);
    locate_y.push_back(0);

    locate_x.push_back(40);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);


    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);


}

weapon_usershottritwotrack::weapon_usershottritwotrack()
{
    weaponID = weapon::weapon_usershottritwotrack;

    num = 5;

    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_unottrack_10);
    bulletIDls.push_back(items::bullet_utrack_10);
    bulletIDls.push_back(items::bullet_utrack_10);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_x.push_back(0);
    run_y.push_back(-1);

    run_x.push_back(0);
    run_y.push_back(-1);

    locate_x.push_back(-60);
    locate_y.push_back(0);

    locate_x.push_back(60);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);

    run_x.push_back(0);
    run_y.push_back(1);

    run_x.push_back(0);
    run_y.push_back(1);


    locate_x.push_back(0);
    locate_y.push_back(0);

    locate_x.push_back(0);
    locate_y.push_back(0);


}

weapon_enemycircleshot::weapon_enemycircleshot()
{
    weaponID = weapon::weapon_enemycircleshot;

    int H = 80;
    int W = 64;

    num = 18;

    for(int i=0;i<18;i++)
    {
        bulletIDls.push_back(items::bullet_nottrack_10);
    }

    locate_x.push_back(0.173*W);
    locate_y.push_back(0.984*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(1*W);
    locate_y.push_back(0*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(-0.342*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(-0.642*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(-0.766*W);
    locate_y.push_back(-0.642*H);


    locate_x.push_back(-0.939*W);
    locate_y.push_back(-0.342*H);


    locate_x.push_back(-W);
    locate_y.push_back(0);

    locate_x.push_back(-0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(-0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(-0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(-0.173*W);
    locate_y.push_back(0.984*H);



    run_x.push_back(0.173);
    run_y.push_back(0.98);

    run_x.push_back(0.5);
    run_y.push_back(0.866);

    run_x.push_back(0.766);
    run_y.push_back(0.642);

    run_x.push_back(0.939);
    run_y.push_back(0.342);

    run_x.push_back(1);
    run_y.push_back(0);

    run_x.push_back(0.939);
    run_y.push_back(-0.342);

    run_x.push_back(0.766);
    run_y.push_back(-0.642);

    run_x.push_back(0.5);
    run_y.push_back(-0.866);


    run_x.push_back(0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.5);
    run_y.push_back(-0.866);


    run_x.push_back(-0.766);
    run_y.push_back(-0.642);


    run_x.push_back(-0.939);
    run_y.push_back(-0.342);


    run_x.push_back(-1);
    run_y.push_back(0);

    run_x.push_back(-0.939);
    run_y.push_back(0.342);

    run_x.push_back(-0.766);
    run_y.push_back(0.642);

    run_x.push_back(-0.5);
    run_y.push_back(0.866);

    run_x.push_back(-0.173);
    run_y.push_back(0.984);



}

weapon_enemyrightcircle::weapon_enemyrightcircle()
{
    weaponID = weapon::weapon_enemyrightcircle;

    int H = 80;
    int W = 64;

    num = 18;

    for(int i=0;i<18;i++)
    {
        bulletIDls.push_back(items::bullet_slow_12);
    }

    locate_x.push_back(-W);
    locate_y.push_back(0);

    locate_x.push_back(-0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(-0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(-0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(-0.173*W);
    locate_y.push_back(0.984*H);


    locate_x.push_back(0.173*W);
    locate_y.push_back(0.984*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(1*W);
    locate_y.push_back(0*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(-0.342*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(-0.642*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(-0.766*W);
    locate_y.push_back(-0.642*H);


    locate_x.push_back(-0.939*W);
    locate_y.push_back(-0.342*H);



    run_x.push_back(-1);
    run_y.push_back(0);

    run_x.push_back(-0.939);
    run_y.push_back(0.342);

    run_x.push_back(-0.766);
    run_y.push_back(0.642);

    run_x.push_back(-0.5);
    run_y.push_back(0.866);

    run_x.push_back(-0.173);
    run_y.push_back(0.984);


    run_x.push_back(0.173);
    run_y.push_back(0.98);

    run_x.push_back(0.5);
    run_y.push_back(0.866);

    run_x.push_back(0.766);
    run_y.push_back(0.642);

    run_x.push_back(0.939);
    run_y.push_back(0.342);

    run_x.push_back(1);
    run_y.push_back(0);

    run_x.push_back(0.939);
    run_y.push_back(-0.342);

    run_x.push_back(0.766);
    run_y.push_back(-0.642);

    run_x.push_back(0.5);
    run_y.push_back(-0.866);


    run_x.push_back(0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.5);
    run_y.push_back(-0.866);


    run_x.push_back(-0.766);
    run_y.push_back(-0.642);


    run_x.push_back(-0.939);
    run_y.push_back(-0.342);
}

weapon_enemyleftcircle::weapon_enemyleftcircle()
{
    weaponID = weapon::weapon_enemyleftcircle;

    int H = 80;
    int W = 64;

    num = 18;

    for(int i=0;i<18;i++)
    {
        bulletIDls.push_back(items::bullet_slow_12);
    }
    locate_x.push_back(1*W);
    locate_y.push_back(0*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(-0.342*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(-0.642*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(-0.766*W);
    locate_y.push_back(-0.642*H);


    locate_x.push_back(-0.939*W);
    locate_y.push_back(-0.342*H);


    locate_x.push_back(-W);
    locate_y.push_back(0);

    locate_x.push_back(-0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(-0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(-0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(-0.173*W);
    locate_y.push_back(0.984*H);

    locate_x.push_back(0.173*W);
    locate_y.push_back(0.984*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(0.342*H);


    run_x.push_back(1);
    run_y.push_back(0);

    run_x.push_back(0.939);
    run_y.push_back(-0.342);

    run_x.push_back(0.766);
    run_y.push_back(-0.642);

    run_x.push_back(0.5);
    run_y.push_back(-0.866);


    run_x.push_back(0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.5);
    run_y.push_back(-0.866);


    run_x.push_back(-0.766);
    run_y.push_back(-0.642);


    run_x.push_back(-0.939);
    run_y.push_back(-0.342);


    run_x.push_back(-1);
    run_y.push_back(0);

    run_x.push_back(-0.939);
    run_y.push_back(0.342);

    run_x.push_back(-0.766);
    run_y.push_back(0.642);

    run_x.push_back(-0.5);
    run_y.push_back(0.866);

    run_x.push_back(-0.173);
    run_y.push_back(0.984);





    run_x.push_back(0.173);
    run_y.push_back(0.98);

    run_x.push_back(0.5);
    run_y.push_back(0.866);

    run_x.push_back(0.766);
    run_y.push_back(0.642);

    run_x.push_back(0.939);
    run_y.push_back(0.342);


}

weapon_enemymiddlecircle::weapon_enemymiddlecircle()
{
    weaponID = weapon::weapon_enemymiddlecircle;

    int H = 80;
    int W = 64;

    num = 18;

    for(int i=0;i<18;i++)
    {
        bulletIDls.push_back(items::bullet_slow_12);
    }
    locate_x.push_back(0.173*W);
    locate_y.push_back(0.984*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(1*W);
    locate_y.push_back(0*H);

    locate_x.push_back(0.939*W);
    locate_y.push_back(-0.342*H);

    locate_x.push_back(0.766*W);
    locate_y.push_back(-0.642*H);

    locate_x.push_back(0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.173*W);
    locate_y.push_back(-0.984*H);


    locate_x.push_back(-0.5*W);
    locate_y.push_back(-0.866*H);


    locate_x.push_back(-0.766*W);
    locate_y.push_back(-0.642*H);


    locate_x.push_back(-0.939*W);
    locate_y.push_back(-0.342*H);


    locate_x.push_back(-W);
    locate_y.push_back(0);

    locate_x.push_back(-0.939*W);
    locate_y.push_back(0.342*H);

    locate_x.push_back(-0.766*W);
    locate_y.push_back(0.642*H);

    locate_x.push_back(-0.5*W);
    locate_y.push_back(0.866*H);

    locate_x.push_back(-0.173*W);
    locate_y.push_back(0.984*H);



    run_x.push_back(0.173);
    run_y.push_back(0.98);

    run_x.push_back(0.5);
    run_y.push_back(0.866);

    run_x.push_back(0.766);
    run_y.push_back(0.642);

    run_x.push_back(0.939);
    run_y.push_back(0.342);

    run_x.push_back(1);
    run_y.push_back(0);

    run_x.push_back(0.939);
    run_y.push_back(-0.342);

    run_x.push_back(0.766);
    run_y.push_back(-0.642);

    run_x.push_back(0.5);
    run_y.push_back(-0.866);


    run_x.push_back(0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.173);
    run_y.push_back(-0.984);


    run_x.push_back(-0.5);
    run_y.push_back(-0.866);


    run_x.push_back(-0.766);
    run_y.push_back(-0.642);


    run_x.push_back(-0.939);
    run_y.push_back(-0.342);


    run_x.push_back(-1);
    run_y.push_back(0);

    run_x.push_back(-0.939);
    run_y.push_back(0.342);

    run_x.push_back(-0.766);
    run_y.push_back(0.642);

    run_x.push_back(-0.5);
    run_y.push_back(0.866);

    run_x.push_back(-0.173);
    run_y.push_back(0.984);


}
