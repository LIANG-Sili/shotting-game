#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameover)
{
    //    setAutoFillBackground(false);
    //    setWindowFlags(Qt::FramelessWindowHint);
    //    setAttribute(Qt::WA_TranslucentBackground, true);

        ui->setupUi(this);

    //    showFullScreen();

        QRect deskRect = QApplication::desktop()->availableGeometry();

        setWindowFlags(Qt::FramelessWindowHint);
        setFixedSize(deskRect.width() / 2,deskRect.height() +100);
        move((deskRect.width() - this->width()) / 2,(deskRect.height() - this->height()) / 2);

        int width = geometry().width();
        int height = geometry().height();

        ui->restart->move((width - ui->restart->width()) / 2,height * 0.6);
        ui->mainmenu->move((width - ui->mainmenu->width()) / 2,height * 0.7);
        ui->exit->move((width - ui->exit->width()) / 2,height * 0.8);

        QCursor cursor(QPixmap(":/source/image/cursor/normal.png"));
        QApplication::setOverrideCursor(cursor);

        setMouseTracking(true);
}

gameover::~gameover()
{
    delete ui;
}

void gameover::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/source/image/layout/gobg.jpg"));
}

void gameover::mouseMoveEvent(QMouseEvent *event)
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
        QCursor cursor(QPixmap(":/source/image/cursor/mainmenu_hover.png"));
        QApplication::setOverrideCursor(cursor);
    }
    else{
        QCursor cursor(QPixmap(":/source/image/cursor/normal.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

bool gameover::enterBtn(QPoint p, QPushButton *btn)
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
void gameover::on_restart_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/start_press.png"));
    QApplication::setOverrideCursor(cursor);

    emit go_restart();
}

void gameover::on_mainmenu_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/leave_press.png"));
    QApplication::setOverrideCursor(cursor);

    emit go2mm();
}

void gameover::on_exit_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/leave_press.png"));
    QApplication::setOverrideCursor(cursor);

    exit(0);
}
