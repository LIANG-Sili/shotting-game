#include "mainwidget.h"
#include "ui_mainwidget.h"

int HEIGHT = 0;
int WIDTH = 0;

void Sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget),ur(new user(width()/2,height()-50))
{

    bgmT = new bgmThread();
    thread = new QThread(this);
    bgmT->moveToThread(thread);

    times = 1;

    connect(this ,&mainWidget::playbgm,bgmT,&bgmThread::play);


    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    ui->setupUi(this);



    showFullScreen();

    HEIGHT = height();
    WIDTH = width();

    connect(this,&mainWidget::healthloss,ur,&user::slot_healthloss);
    connect(ur,&user::gameover,this,&mainWidget::slot_gameover);
    connect(ur,&user::healthbarRefresh,this,&mainWidget::on_progressBar_valueChanged);
    connect(ur,&user::changeclearnumlabel,this,&mainWidget::slot_changeclearnumlabel);
    connect(this,&mainWidget::ehealthloss,&factory,&enemyfactory::slot_ehealthloss);
    connect(this,&mainWidget::addenemy,&factory ,&enemyfactory::slot_addenemy);
    connect(this, &mainWidget::getitems,ur,&user::slot_getitems);
    connect(&factory,&enemyfactory::appearitems,this,&mainWidget::slot_appearitems);

    connect(&factory,&enemyfactory::GetScore,this,&mainWidget::slot_GetScore);


    ui->progressBar->move(width()-30,height()-200);

    slot_changeclearnumlabel(ur->clearscreen_num);

    ui->label->move(width()-290,height()-100);

    ui->score->move(100,height() - 100);


    mouse_x = width()/2-64;
    mouse_y = height()-160;

    score = 0;

}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();


    if(x <= ceil(ur->W/2.0))
        x = ceil(ur->W/2.0);
    else if(x >= ceil(this->width()-ur->W/2.0))
        x = ceil(this->width()-ur->W/2.0);
    if(y <= ceil(ur->H/2.0))
        y = ceil(ur->H/2.0);
    else if(y >= ceil(height()-ur->H/2.0))
        y = ceil(height()-ur->H/2.0);

    //QCursor::setPos();

    this -> ur->x = x-ceil(ur->W/2.0);
    this -> ur->y = y-ceil(ur->H/2.0);

    mouse_x = x;
    mouse_y = y;

}

void mainWidget::mousePressEvent(QMouseEvent *ev)
{
//    if(ev->button() == Qt::LeftButton)
//    {
//        for(int i = 0;i<ur.wp->num;i++)
//        {
//            if(ur.wp->bulletIDls[i] == items::bullet_nottrack_10)
//            {
//               this->itemsls.push_back(new bullet_nottrack_10(ur.x+ur.W/2+ur.wp->locate_x[i],ur.y+ur.wp->locate_y[i],ur.wp->run_x[i],ur.wp->run_y[i],items::hurtenemy));


//            }

//            //

//        }




//    }
    /*else*/ if(ev->button() == Qt::RightButton)   //右键 清屏大招？？
    {
        if( ur->clearscreen_num > 0)
        {
            clear_picture.push_back(new picture(0,height()-329,407,329,":/source/image/layout/123.png"));

            //
            QSoundEffect effect;

            effect.setSource(QUrl::fromLocalFile(":/source/music/clearscreen.wav"));

            effect.setLoopCount(QSoundEffect::Infinite);

            effect.setVolume(10.0f);

            effect.play();
            //


            for(int i=0;i<itemsls.size();i++)
            {
                if(itemsls[i]->flag == items::hurtuser || itemsls[i]->flag == items::hurtboth)
                {
                    delete itemsls[i];
                    itemsls.erase(itemsls.begin()+i);
                    i--;
                }
            }

            for(int i=0;i<factory.ls.size();i++)
            {
                factory.ls[i]->health -= 100;

                if(factory.ls[i]->health <= 0)
                {
                    slot_GetScore(factory.ls[i]->enemyID);
                    slot_appearitems(factory.ls[i]->x,factory.ls[i]->y);
                    delete factory.ls[i];
                    factory.ls.erase(factory.ls.begin()+i);
                    i--;
                }

            }

            Sleep(1500);

            delete clear_picture[0];
            clear_picture.erase(clear_picture.begin());

            ur->clearscreen_num--;

            slot_changeclearnumlabel(ur->clearscreen_num);

        }


    }
}

void mainWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
//    case Qt::Key_Up :

//        if(this->ur.y1 != 0)
//        {
//            this->ur.y1 -= ur.pace;
//            this->ur.y2 -= ur.pace;
//        }
//        break;

//    case Qt::Key_Down :
//        if(this->ur.y2 != height())
//        {
//            this->ur.y1 += ur.pace;
//            this->ur.y2 += ur.pace;
//        }
//        break;

//    case Qt::Key_Left :
//        if(this->ur.x1!=0)
//        {
//            this->ur.x1 -= ur.pace;
//            this->ur.x2 -= ur.pace;
//        }
//        break;

//    case Qt::Key_Right :
//        if(this->ur.x2!=width())
//        {
//            this->ur.x1 += ur.pace;
//            this->ur.x2 += ur.pace;
//        }
//        break;

//    case Qt::Key_X :
//       this->ur.shot();
    case Qt::Key_Escape :
        emit mw2gm();//出个弹窗
        pause();
        break;
    }
}

void mainWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);



    p.drawPixmap(bgX,bgY,bgW,bgH,QPixmap(bgpath)); //背景图待定

    p.drawPixmap(this->ur->x,this->ur->y,ur->W,ur->H,QPixmap(ur->imagepath));

    for(int i=0;i<factory.ls.size();i++)
    {
        p.drawPixmap( factory.ls[i]->x, factory.ls[i]->y, factory.ls[i]->W, factory.ls[i]->H,QPixmap( factory.ls[i]->imagepath));
    }

    for(int i=0;i<this->itemsls.size();i++)
    {
        p.drawPixmap(this->itemsls[i]->x,this->itemsls[i]->y,this->itemsls[i]->W,this->itemsls[i]->H,QPixmap(this->itemsls[i]->imagepath));
    }

    if(clear_picture.size()!=0)
    {
        for(auto i:clear_picture)
        {
            p.drawPixmap(i->x,i->y,i->w,i->h,QPixmap(i->Path));
        }
    }
}

void mainWidget::timerEvent(QTimerEvent *event)
{
    if(event ->timerId() == this ->bulletTimeId)
    {

        bgY += 2;
        if(bgY >= 0)
        {
            bgY = 0;
        }

        for(int i=0;i<this->factory.ls.size();i++)
        {
            factory.ls[i]->x += factory.ls[i]->run_x*factory.ls[i]->pace;
            factory.ls[i]->y += factory.ls[i]->run_y*factory.ls[i]->pace;

            if(factory.ls[i]->x<0
                    ||
                    factory.ls[i]->x+factory.ls[i]->W>width()
                    ||
                    factory.ls[i]->y<0
                    ||
                    factory.ls[i]->y+factory.ls[i]->H>height())
            {
                delete factory.ls[i];
                factory.ls.erase(factory.ls.begin()+i);
                i--;
            }

//            for(int j=0;j<this->factory.ls[i]->wp->ls.size();j++)
//            {
//                factory.ls[i]->wp->ls[j]->x += factory.ls[i]->wp->ls[j]->run.x();
//                factory.ls[i]->wp->ls[j]->y += factory.ls[i]->wp->ls[j]->run.y();

//                if(factory.ls[i]->wp->ls[j]->x<0
//                        ||
//                        factory.ls[i]->wp->ls[j]->x+factory.ls[i]->wp->ls[j]->W>width()
//                        ||
//                        factory.ls[i]->wp->ls[j]->y<0
//                        ||
//                        factory.ls[i]->wp->ls[j]->y+factory.ls[i]->wp->ls[j]->H>height())
//                {
//                    delete factory.ls[i]->wp->ls[j];
//                    factory.ls[i]->wp->ls.erase(factory.ls[i]->wp->ls.begin()+j);
//                    j--;
//                }

//                if(factory.ls[i](factory.ls[i]->wp->ls[j]))

//            }

        }

        for(int i=0;i<(this->itemsls).size();i++)
        {
            itemsls[i]->x += itemsls[i]->run_x*itemsls[i]->pace;
            itemsls[i]->y += itemsls[i]->run_y*itemsls[i]->pace;
            if(itemsls[i]->y!=0 && itemsls[i]->y!=height()-ceil(itemsls[i]->H/2.0) && itemsls[i]->x!=0 && itemsls[i]->x != width()-ceil(itemsls[i]->W/2.0))
            {
                if(itemsls[i]->flag == items::tools)
                {
                    if(ur->crash(itemsls[i]))
                    {
                        emit getitems(itemsls[i]->itemsID);

                        delete itemsls[i];
                        itemsls.erase(itemsls.begin()+i);
                        i--;
                    }
                }
                else if(itemsls[i]->flag == items::hurtuser)
                {
                    if(ur->crash(itemsls[i]))
                    {
                        emit healthloss(dynamic_cast<bullet*>(itemsls[i])->damage);

                        delete itemsls[i];
                        itemsls.erase(itemsls.begin()+i);
                        i--;
                    }
                }
                else if(itemsls[i]->flag == items::hurtenemy)
                {
                    for(int j=0;j<factory.ls.size();j++)
                    {
                        if(factory.ls[j]->crash(itemsls[i]))
                        {
                            emit ehealthloss(j,dynamic_cast<bullet*>(itemsls[i])->damage);

                            delete itemsls[i];
                            itemsls.erase(itemsls.begin()+i);
                            i--;
                        }
                    }

                }
                else if(itemsls[i]->flag == items::hurtboth)
                {

                }
            }
            else
            {
                delete itemsls[i];
                itemsls.erase(itemsls.begin()+i);
                i--;
            }
        }
    }
    else if(event ->timerId() == this -> enemyappearTimeId)  //这部分需要修改 有着怎样的流程
    {
//        times = 17; // //

//        // //////////////////////////////////////////////////////////////////////////////////

                if(factory.ls.size() != 0)   return;

                int CutWidth = WIDTH / 6;

                if(times == 1){
                    for(int i = 1; i <= 5; i++){
                        emit addenemy(enemy::enemy_littlebrother,CutWidth * i);
                    }
                }
                else if(times == 2){
                    emit addenemy(enemy::enemy_littlebrother,CutWidth);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_littlebrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_littlebrother,CutWidth * 5);
                }
                else if(times == 3){
                    for(int i = 1; i <= 5; i++){
                        emit addenemy(enemy::enemy_secondbrother,CutWidth * i);
                    }
                }
                else if(times == 4){
                    emit addenemy(enemy::enemy_secondbrother,CutWidth);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 5);
                }
                else if(times == 5){
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 4);
                }
                else if(times == 6){
                    //

                    clear_picture.push_back(new picture(width()/2-250,height()/2-150,500,300,":/source/image/level/LevelComplete.png"));


                    clear_picture.push_back(new picture(width()/2-250,height()/2-350,500,300,showgrade(score,section)));
                    //
                    QSoundEffect effect;

                    effect.setSource(QUrl::fromLocalFile(":/source/music/victory.wav"));

                    effect.setLoopCount(QSoundEffect::Infinite);

                    effect.setVolume(1.0f);

                    effect.play();


                    Sleep(5000);
                    //
                    for(int i=0;i<clear_picture.size();)
                    {
                        delete clear_picture[i];
                        clear_picture.erase(clear_picture.begin()+i);
                    }

                    score = 0;

                    bgH = 800*width()/520;
                    bgW = width();

                    bgX = 0;
                    bgY = -bgH+height();

                    section ++;

                    bgpath = ":/source/image/layout/bg1.jpg";



                    //
                    emit addenemy(enemy::enemy_secondbrother,CutWidth);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 5);
                }
                else if(times == 7){
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 5);
                }
                else if(times == 8){
                    emit addenemy(enemy::enemy_4thbrother,CutWidth);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_6thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 5);
                }
                else if(times == 9){
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_5thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 4);
                }
                else if(times == 10){
                    emit addenemy(enemy::enemy_5thbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_6thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_5thbrother,CutWidth * 4);
                }
                else if(times == 11){

                    clear_picture.push_back(new picture(width()/2-250,height()/2-150,500,300,":/source/image/level/LevelComplete.png"));


                    clear_picture.push_back(new picture(width()/2-250,height()/2-350,500,300,showgrade(score,section)));
                    //
                    QSoundEffect effect;

                    effect.setSource(QUrl::fromLocalFile(":/source/music/victory.wav"));

                    effect.setLoopCount(QSoundEffect::Infinite);

                    effect.setVolume(1.0f);

                    effect.play();

                    Sleep(5000);


                    //
                    for(int i=0;i<clear_picture.size();)
                    {
                        delete clear_picture[i];
                        clear_picture.erase(clear_picture.begin()+i);
                    }

                    score = 0;

                    section ++;

                    bgH = 800*width()/520;
                    bgW = width();

                    bgX = 0;
                    bgY = -bgH+height();

                    bgpath = ":/source/image/layout/bg3.jpg";


                    //

                    emit addenemy(enemy::enemy_thirdbrother,CutWidth);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_6thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 5);
                }
                else if(times == 12){
                    emit addenemy(enemy::enemy_4thbrother,CutWidth);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_5thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 5);
                }
                else if(times == 13){
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_7thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 5);
                }
                else if(times == 14){
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth);
                    emit addenemy(enemy::enemy_7thbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_secondbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_7thbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_thirdbrother,CutWidth * 5);
                }
                else if(times == 15){
                    emit addenemy(enemy::enemy_4thbrother,CutWidth);
                    emit addenemy(enemy::enemy_7thbrother,CutWidth * 2);
                    emit addenemy(enemy::enemy_5thbrother,CutWidth * 3);
                    emit addenemy(enemy::enemy_6thbrother,CutWidth * 4);
                    emit addenemy(enemy::enemy_4thbrother,CutWidth * 5);
                }

                else if(times == 16)
                {
                    clear_picture.push_back(new picture(width()/2-250,height()/2-150,500,300,":/source/image/level/LevelComplete.png"));


                    clear_picture.push_back(new picture(width()/2-250,height()/2-350,500,300,showgrade(score,section)));
                    QSoundEffect effect;

                    effect.setSource(QUrl::fromLocalFile(":/source/music/victory.wav"));

                    effect.setLoopCount(QSoundEffect::Infinite);

                    effect.setVolume(1.0f);

                    effect.play();

                    Sleep(5000);


                    //
                    for(int i=0;i<clear_picture.size();)
                    {
                        delete clear_picture[i];
                        clear_picture.erase(clear_picture.begin()+i);
                    }

                    score = 0;

                    section ++;

                    bgH = 800*width()/520;
                    bgW = width();

                    bgX = 0;
                    bgY = -bgH+height();

                    bgpath = ":/source/image/layout/bg2.jpg";//


                    clear_picture.push_back(new picture(width()/2-250,height()/2-150,500,300,":/source/image/level/BOSS.png"));




                    //

                    effect.setSource(QUrl::fromLocalFile(":/source/music/boss_warning.wav"));

                    effect.setLoopCount(QSoundEffect::Infinite);

                    effect.setVolume(1.0f);

                    effect.play();

                    //

                    Sleep(5000);

                    for(int i=0;i<clear_picture.size();)
                    {
                        delete clear_picture[i];
                        clear_picture.erase(clear_picture.begin()+i);
                    }

                    //enemyshotTimeId = this ->startTimer(1500);
                    emit addenemy(enemy::enemy_father,CutWidth * 3);

                }

                else if(times == 17)
                {
                    clear_picture.push_back(new picture(width()/2-250,height()/2-150,500,300,":/source/image/level/LevelComplete.png"));


                    clear_picture.push_back(new picture(width()/2-250,height()/2-350,500,300,showgrade(score,section)));
                    QSoundEffect effect;

                    effect.setSource(QUrl::fromLocalFile(":/source/music/victory.wav"));

                    effect.setLoopCount(QSoundEffect::Infinite);

                    effect.setVolume(1.0f);

                    effect.play();

                    Sleep(5000);

                    for(int i=0;i<clear_picture.size();)
                    {
                        delete clear_picture[i];
                        clear_picture.erase(clear_picture.begin()+i);
                    }

                    clear_picture.push_back(new picture(width()/2-350,0,700,1245,":/source/image/layout/the_end.jpg"));



                    Sleep(3000);

                    for(int i=0;i<clear_picture.size();)
                    {
                        delete clear_picture[i];
                        clear_picture.erase(clear_picture.begin()+i);
                    }

                    emit mw2mm();
                    //

                    //game_complete

                }
                times++;
        // /////////////////////////////////////////////////////////////////////////////////
    }
    else if(event -> timerId() == this -> enemyshotTimeId)
    {
        for(int i=0;i<factory.ls.size();i++)
        {
            static int locate_flag = 0;
            for(int j=0;j<factory.ls[i]->wp->num;j++)
            {
                if(factory.ls[i]->wp->bulletIDls[j] == items::bullet_nottrack_10)
                {
                   this->itemsls.push_back(new bullet_nottrack_10(factory.ls[i]->x+factory.ls[i]->W/2+factory.ls[i]->wp->locate_x[j]-15,factory.ls[i]->y+factory.ls[i]->H+factory.ls[i]->wp->locate_y[j]-15,factory.ls[i]->wp->run_x[j],factory.ls[i]->wp->run_y[j],items::hurtuser));
                }
                else if(factory.ls[i]->wp->bulletIDls[j] == items::bullet_track_10)
                {

                    int X = factory.ls[i]->x+factory.ls[i]->W/2+factory.ls[i]->wp->locate_x[j]-15;
                    int Y = factory.ls[i]->y+factory.ls[i]->H/2+factory.ls[i]->wp->locate_y[j]-15;
                    float L = sqrt((float)(ur->x+ur->W/2-X)*(ur->x+ur->W/2-X)+(ur->y+ur->H/2-Y)*(ur->y+ur->H/2-Y));
                    factory.ls[i]->wp->run_x[j] = (ur->x+ur->W/2-X)/L;
                    factory.ls[i]->wp->run_y[j] = (ur->y+ur->H/2-Y)/L;

                    X += locate_flag * factory.ls[i]->wp->run_x[j]*20;
                    Y += locate_flag * factory.ls[i]->wp->run_y[j]*20;

                   this->itemsls.push_back(new bullet_track_10(X,Y,factory.ls[i]->wp->run_x[j],factory.ls[i]->wp->run_y[j],items::hurtuser));
                }
                else if(factory.ls[i]->wp->bulletIDls[j] == items::bullet_slow_12)
                {
                    int X = factory.ls[i]->x+factory.ls[i]->W/2+factory.ls[i]->wp->locate_x[j]-15;
                    int Y = factory.ls[i]->y+factory.ls[i]->H/2+factory.ls[i]->wp->locate_y[j]-15;
                    X += locate_flag * factory.ls[i]->wp->run_x[j]*5;
                    Y += locate_flag * factory.ls[i]->wp->run_y[j]*5;
                    this->itemsls.push_back(new bullet_slow_12(X,Y,factory.ls[i]->wp->run_x[j],factory.ls[i]->wp->run_y[j],items::hurtuser));



                   if(factory.ls[i]->wp->weaponID == weapon::weapon_enemymiddlecircle)
                    {
                       if(j<factory.ls.size()/2)
                            this->itemsls.push_back(new bullet_slow_12(X,Y,factory.ls[i]->wp->run_x[factory.ls.size()-j],factory.ls[i]->wp->run_y[factory.ls.size()-j],items::hurtuser));
                       else
                           break;
                    }

                }
                //



                locate_flag ++;

            }

            locate_flag = 0;
        }
    }
    else if(event -> timerId() == this -> usershotTimeId)
    {
//        if(factory.ls.size() > 0)
//        {
            for(int i = 0;i<ur->wp->num;i++)
            {
                if(ur->wp->bulletIDls[i] == items::bullet_unottrack_10)
                {
                   this->itemsls.push_back(new bullet_unottrack_10(ur->x+ur->W/2+ur->wp->locate_x[i]-15,ur->y+ur->wp->locate_y[i]-15,ur->wp->run_x[i],ur->wp->run_y[i],items::hurtenemy));


                }
                else if(ur->wp->bulletIDls[i] == items::bullet_utrack_10)
                {
                    int n = 0;
                    if(factory.ls.size() == 0)
                    {
                        break;
                    }
                    else if(factory.ls.size() == 1)
                    {
                    }
                    else
                    {
                        for(int i=1;i<factory.ls.size();i++)
                        {
                                if(abs(factory.ls[n]->x+factory.ls[n]->W/2-ur->x-ur->W/2)+abs(factory.ls[n]->y+factory.ls[n]->H/2-ur->y-ur->H/2)>abs(factory.ls[i]->x+factory.ls[i]->W/2-ur->x-ur->W/2)+abs(factory.ls[i]->y+factory.ls[i]->H/2-ur->y-ur->H/2))
                                {
                                    n = i;
                                }
                        }
                    }
                        int X = factory.ls[n]->x+factory.ls[n]->W/2 - ur->x-ur->W/2;
                        int Y = factory.ls[n]->y+factory.ls[n]->H/2 - ur->y-ur->H/2;
                        float L = sqrt(float(X*X)+Y*Y);

                        this->itemsls.push_back(new bullet_utrack_10(ur->x+ur->W/2+ur->wp->locate_x[i]-15,ur->y+ur->wp->locate_y[i]-15,X/L,Y/L,items::hurtenemy));

                }

                //

            }
        //}


     }
    else if(event -> timerId() == this -> paintTimeId)
    {
        update();
    }
    else if(event->timerId() == this -> BossTimeId)
    {

        if(factory.ls.size() == 1 && factory.ls[0]->enemyID == enemy::enemy_father)
        {
            static int Bosstimes = 0;
            if(dynamic_cast<enemy_father *>(factory.ls[0])->shadowappear == false && Bosstimes == 5)
            {
                if(factory.ls[0]->wp != nullptr)
                    delete factory.ls[0]->wp;
                switch(qrand()%3+weapon::weapon_enemyshotcircle)
                {
                case weapon::weapon_enemyshotcircle:
                    factory.ls[0]->wp = new weapon_enemyshotcircle;
                    break;
                case weapon::weapon_enemyshotswiftonetrack:
                    factory.ls[0]->wp = new weapon_enemyshotswiftonetrack;
                    break;
                case weapon::weapon_enemyshottritwotrack:
                    factory.ls[0]->wp = new weapon_enemyshottritwotrack;
                }

                Bosstimes = 0;
            }
            else if(dynamic_cast<enemy_father *>(factory.ls[0])->shadowappear == true && Bosstimes == 5)
            {
                if(factory.ls[0]->wp != nullptr)
                    delete factory.ls[0]->wp;
                switch (qrand()%5 + weapon::weapon_enemyshotswiftonetrack)
                {
                case weapon::weapon_enemyshotswiftonetrack:
                    factory.ls[0]->wp = new weapon_enemyshotswiftonetrack;
                    break;
                case weapon::weapon_enemyshottritwotrack:
                    factory.ls[0]->wp = new weapon_enemyshottritwotrack;

                case weapon::weapon_enemycircleshot:
                    factory.ls[0]->wp = new weapon_enemycircleshot;
                    break;
                case weapon::weapon_enemyrightcircle:
                    factory.ls[0]->wp = new weapon_enemyrightcircle;
                    break;
                case weapon::weapon_enemyleftcircle:
                    factory.ls[0]->wp = new weapon_enemyleftcircle;
                    break;
//                case weapon::weapon_enemymiddlecircle:
//                    factory.ls[0]->wp = new weapon_enemymiddlecircle;

                }

                Bosstimes = 0;
            }

            if(factory.ls[0]->x < width()/6 - factory.ls[0]->W/2)
            {
                factory.ls[0]->run_x = 1;
            }
            else if(factory.ls[0]->x > 5*width()/6 - factory.ls[0]->W/2)
            {
                factory.ls[0]->run_x = -1;
            }

            Bosstimes ++;
        }
    }
}

void mainWidget::slot_gameover()
{
    emit game2go();
    //弹出一个什么界面
}

void mainWidget::slot_appearitems(int x,int y)
{
    int flag = qrand()%items::items_end;
    if(flag == items::items_healthrecover)
    {
        itemsls.push_back(new items_healthrecover(x,y,0,1,items::tools));
    }
    else if(flag == items::items_changeweapon)
    {
        itemsls.push_back(new items_changeweapon(x,y,0,1,items::tools));
    }
    else if(flag == items::items_addclearnum)
    {
        itemsls.push_back(new items_addclearnum(x,y,0,1,items::tools));
    }
}

void mainWidget::slot_GetScore(int ID)
{
    if(ID == enemy::enemy_littlebrother){
        score +=10;
    }
    else if(ID == enemy::enemy_secondbrother){
        score +=20;
    }
    else if(ID == enemy::enemy_thirdbrother){
        score +=20;
    }
    else if(ID == enemy::enemy_4thbrother){
        score +=40;
    }
    else if(ID == enemy::enemy_5thbrother){
        score +=60;
    }
    else if(ID == enemy::enemy_6thbrother){
        score +=80;
    }
    else if(ID == enemy::enemy_7thbrother){
        score +=100;
    }
    else if(ID == enemy::enemy_father){
        score +=10000;
    }

    slot_changeScoreLabel(score);
}

void mainWidget::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}

void mainWidget::slot_changeclearnumlabel(int num)
{
    ui->label->setText(QString("<h1>NUM LEFT: %1</h1>").arg(num));
}

void mainWidget::slot_changeScoreLabel(int score)
{
    ui->score->setText(QString("<h1>YOUR SCORE: %1</h1>").arg(score));
}

void mainWidget::pause()
{
    setMouseTracking(false);

    killTimer(bulletTimeId);
    killTimer(enemyappearTimeId);
    killTimer(enemyshotTimeId);
    killTimer(usershotTimeId);
    killTimer(paintTimeId);
    killTimer(BossTimeId);

}

void mainWidget::start()
{
    bulletTimeId = this -> startTimer(100);
    enemyappearTimeId = this -> startTimer(10000);
    enemyshotTimeId = this -> startTimer(1800);
    usershotTimeId = this -> startTimer(400);
    paintTimeId = this -> startTimer(10);
    BossTimeId = this -> startTimer(1000);//

    setMouseTracking(true);
    QApplication::setOverrideCursor(Qt::BlankCursor);
    thread->start();

    QCursor::setPos(mouse_x,mouse_y);
}

void mainWidget::playbg()
{
    emit playbgm();
}

void mainWidget::init()
{
    for(int i=0;i<clear_picture.size();)
    {
        delete clear_picture[i];
        clear_picture.erase(clear_picture.begin()+i);
    }

    for(int i=0;i<factory.ls.size();)
    {
        delete factory.ls[i];
        factory.ls.erase(factory.ls.begin()+i);
    }

    for(int i=0;i<itemsls.size();)
    {
        delete itemsls[i];
        itemsls.erase(itemsls.begin()+i);
    }

    ur->x = mouse_x;
    ur->y = mouse_y;
    times = 1;
    ur->health = 100;
    if(ur->wp != nullptr)
        delete ur->wp;
    ur->wp = new weapon_usershotone; // //

    ur->addnum = 0;
    ur->changeitems_num = 0;
    ur->clearscreen_num = 3;
    slot_changeclearnumlabel(3);
    slot_changeScoreLabel(0);
    on_progressBar_valueChanged(100);

    bgH = 800*width()/520;
    bgW = width();

    bgX = 0;
    bgY = -bgH+height();

    section = 1;

    bgpath = ":/source/image/layout/bg0.jpg";
}

QString mainWidget::showgrade(int score,int section)
{
    if(section == 1){
        if(score <=250){
            return ":/source/image/level/S.png";
        }
        else if(score <= 380){
            return ":/source/image/level/SS.png";
        }else{
            return ":/source/image/level/SSS.png";
        }
    }
    else if(section == 2){
        if(score <= 400){
            return ":/source/image/level/S.png";
        }else if(score <= 700){
            return ":/source/image/level/SS.png";
        }else{
            return ":/source/image/level/SSS.png";
        }
    }
    else if(section == 3){
        if(score <= 700){
            return ":/source/image/level/S.png";
        }else if(score <= 960){
          return ":/source/image/level/SS.png";
        }else{
            return ":/source/image/level/SSS.png";
        }
    }
    else // ////////////////////////
    {
        return ":/source/image/layout/the_end";
    }
}
