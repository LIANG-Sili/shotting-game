#include "startlogo.h"
#include "ui_startlogo.h"

#include <QPixmap>
#include <QPainter>
#include <QBitmap>

startlogo::startlogo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startlogo)
{
    ui->setupUi(this);

    QPixmap pix;
    pix.load(":/source/image/layout/startbg.png");
    resize(pix.size());
    setMask(pix.mask());
}

startlogo::~startlogo()
{
    delete ui;
}

void startlogo::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/source/image/layout/startbg.png"));
}
