#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>
#include <QTime>
#include <QCoreApplication>
#include <QThread>
#include "user.h"
#include "enemyfactory.h"
#include "bullet_derived.h"
#include "header.h"
#include "kits.h"
#include "bgmthread.h"

#include "gamemenu.h"


#include <QDebug>




namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();

    void slot_changeclearnumlabel(int num);

    void slot_appearitems(int ,int);

    void slot_changeScoreLabel(int);

    QString showgrade(int score,int section);

    void slot_GetScore(int ID);
    void pause();
    void start();

    void init();
    void playbg();

    int mouse_x;
    int mouse_y;

    int times;


    int score;

    int section;



    Ui::mainWidget *ui;

    user *ur;

    int bulletTimeId;
    int enemyappearTimeId;
    int enemyshotTimeId;

    int paintTimeId;

    int usershotTimeId;
    int BossTimeId;


    enemyfactory factory;

    QVector<items *> itemsls;

    QVector<picture *> clear_picture;

    QString bgpath;


    int bgX;
    int bgY;
    int bgH;
    int bgW;
    int bgpace;

    bgmThread *bgmT;
    QThread *thread;

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *);

signals:
    void addenemy(int,int); //enemyID
    void healthloss(int);
    void ehealthloss(int,int);
    void enemyfactoryshot(int);
    void getitems(int);
    void playbgm();

    void mw2gm();
    void game2go();

    void changeScoreLabel(int);

    void mw2mm();

public slots:

    void slot_gameover();


private slots:
    void on_progressBar_valueChanged(int value);
};

void Sleep(unsigned int msec);


#endif // MAINWIDGET_H
