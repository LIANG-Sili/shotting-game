#include "stageclear.h"
#include "ui_stageclear.h"

stageclear::stageclear(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stageclear)
{
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->setupUi(this);

    showFullScreen();
}

stageclear::~stageclear()
{
    delete ui;
}
