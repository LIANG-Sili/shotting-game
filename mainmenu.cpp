#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    showFullScreen();

    QRect deskRect = QApplication::desktop()->availableGeometry();
    ui->start->move((deskRect.width() - ui->start->width()) / 2,deskRect.height() * 0.6);
    ui->exit->move((deskRect.width() - ui->exit->width()) / 2,deskRect.height() * 0.8);

    QCursor cursor(QPixmap(":/source/image/cursor/normal.png"));
    QApplication::setOverrideCursor(cursor);

    setMouseTracking(true);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::paintEvent(QPaintEvent *)
{
    QPainter q(this);
    q.drawPixmap(0,0,width(),height(),QPixmap(":/source/image/layout/bg.png"));
}

void MainMenu::mouseMoveEvent(QMouseEvent *event)
{
    if(enterBtn(event->pos(),ui->start)){

        QCursor cursor(QPixmap(":/source/image/cursor/start_hover.png"));
        QApplication::setOverrideCursor(cursor);
    }
    else if(enterBtn(event->pos(),ui->exit)){
        QCursor cursor(QPixmap(":/source/image/cursor/leave_hover.png"));
        QApplication::setOverrideCursor(cursor);
    }
    else{
        QCursor cursor(QPixmap(":/source/image/cursor/normal.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

bool MainMenu::enterBtn(QPoint p, QPushButton *btn)
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

void MainMenu::on_exit_clicked()
{
    QCursor cursor(QPixmap(":/source/image/cursor/leave_press.png"));
    QApplication::setOverrideCursor(cursor);
    exit(0);
}

void MainMenu::on_start_clicked()
{
    QApplication::setOverrideCursor(Qt::BlankCursor);

    emit mm2mw();
}
