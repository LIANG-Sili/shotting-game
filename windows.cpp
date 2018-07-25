#include "windows.h"

windows::windows(QObject *parent) : QObject(parent)
{
    mm = new MainMenu;
    gm = new gamemenu;
    go = new gameover;
    mw = new mainWidget;


    gm->hide();
    go->hide();
    mw->hide();

    mm->show();

    connect(mm,&MainMenu::mm2mw,this,&windows::slot_mm2mw);
    connect(mw,&mainWidget::mw2gm,this,&windows::slot_mw2gm);
    connect(gm,&gamemenu::gm2mw,this,&windows::slot_gm2mw);
    connect(gm,&gamemenu::gm2mm,this,&windows::slot_gm2mm);
    connect(go,&gameover::go2mm,this,&windows::slot_go2mm);
    connect(mw,&mainWidget::game2go,this,&windows::slot_game2go);
    connect(gm,&gamemenu::gm_restart,this,&windows::slot_gm_restart);
    connect(go,&gameover::go_restart,this,&windows::slot_go_restart);
    connect(mw,&mainWidget::mw2mm,this,&windows::slot_mw2mm);

}

void windows::slot_mm2mw()
{
    mm->hide();
    mw->show();
    mw->init();
    mw->start();
    mw->playbg();
}

void windows::slot_mw2gm()
{

    mw->pause();
    gm->show();
}

void windows::slot_gm2mw()
{
    gm->hide();
    mw->show();

    mw->start();

    QCursor::setPos(mw->mouse_x,mw->mouse_y);
}

void windows::slot_gm2mm()
{
    gm->hide();

    mw->close();

    mm->show();
}

void windows::slot_go2mm()
{
    mw->init();//初始化函数

    go->hide();
    mm->show();

}

void windows::slot_game2go()
{
    mw->pause();
    go->show();
}

void windows::slot_gm_restart()
{
    gm->hide();
    mw->init();
    mw->start();
}

void windows::slot_go_restart()
{
    go->hide();
    mw->init();
    mw->start();
}

void windows::slot_mw2mm()
{
    mw->pause();
    mw->hide();
    mm->show();

}
