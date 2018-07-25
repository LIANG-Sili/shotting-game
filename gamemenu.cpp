#include "gamemenu.h"
#include "ui_gamemenu.h"

bool gamemenu::IsOpen = true;

gamemenu::gamemenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamemenu)
{
    ui->setupUi(this);

//    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    setWindowModality(Qt::WindowModal);        //此两行设置模态窗口，无效就删除

//    setAutoFillBackground(false);
//    setWindowFlags(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground, true);      //透明背景设置

//   showFullScreen();

    QRect deskRect = QApplication::desktop()->availableGeometry();

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(deskRect.width() / 2,deskRect.height()+100);
    move((deskRect.width() - this->width()) / 2,(deskRect.height() - this->height()) / 2);

    int width = geometry().width();
    int height = geometry().height();

    ui->continue_2->move((width - ui->continue_2->width()) / 2,height * 0.2);
    ui->restart->move((width - ui->restart->width()) / 2,height * 0.4);
    ui->mainmenu->move((width - ui->mainmenu->width()) / 2,height * 0.6);
    ui->exit->move((width - ui->exit->width()) / 2,height * 0.8);

    QCursor cursor(QPixmap(":/source/image/cursor/normal.png"));
    QApplication::setOverrideCursor(cursor);

    setMouseTracking(true);
}

gamemenu::~gamemenu()
{
    delete ui;
}

void gamemenu::mouseMoveEvent(QMouseEvent *event)
{
    if(enterBtn(event->pos(),ui->restart)){

        QCursor cursor(QPixmap(":/source/image/cursor/start_hover.png"));
        QApplication::setOverrideCursor(cursor);
    }
    else if(enterBtn(event->pos(),ui->exit)){
        QCursor cursor(QPixmap(":/source/image/cursor/leave_hover.png"));
        QApplication::setOverrideCursor(cursor);
    }
    else if(enterBtn(event->pos(),ui->mainmenu)){
        QCursor cursor(QPixmap(":/source/image/cursor/start_hover.png"));
        QApplication::setOverrideCursor(cursor);
    }
    else{
        QCursor cursor(QPixmap(":/source/image/cursor/normal.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

bool gamemenu::enterBtn(QPoint p, QPushButton *btn)
{
    int height = btn->height();
    int width = btn->width();
    QPoint btnMinPos = btn->pos();
    QPoint btnMaxPos = btn->pos();
    btnMaxPos.setX(btn->pos().x()+width);
    btnMaxPos.setY(btn->pos().y()+height);
    if(p.x() >= btnMinPos.x() && p.y() >= btnMinPos.y()
            && p.x() <= btnMaxPos.x() && p.y() <= btnMaxPos.y())
        return true;
    else  return false;
}
void gamemenu::on_exit_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/leave_press.png"));
    QApplication::setOverrideCursor(cursor);

    exit(0);
}

void gamemenu::on_restart_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/start_press.png"));
    QApplication::setOverrideCursor(cursor);

    emit gm_restart();
}

void gamemenu::on_mainmenu_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/start_press.png"));
    QApplication::setOverrideCursor(cursor);

    emit gm2mm();

}

void gamemenu::on_continue_2_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/start_press.png"));
    QApplication::setOverrideCursor(cursor);

    emit gm2mw();

}

void gamemenu::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/source/image/layout/gm.jpg"));
}
