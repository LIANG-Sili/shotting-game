#ifndef WINDOWS_H
#define WINDOWS_H

#include <QObject>
#include "mainmenu.h"
#include "mainwidget.h"
#include "gamemenu.h"
#include "gameover.h"

class windows : public QObject
{
    Q_OBJECT
public:
    explicit windows(QObject *parent = nullptr);

signals:

public slots:

    void slot_mm2mw();
    void slot_mw2gm();
    void slot_gm2mw();
    void slot_gm2mm();
    void slot_go2mm();
    void slot_game2go();
    void slot_gm_restart();
    void slot_go_restart();
    void slot_mw2mm();


private:

    MainMenu *mm;
    mainWidget *mw;
    gamemenu *gm;
    gameover *go;


};

#endif // WINDOWS_H
