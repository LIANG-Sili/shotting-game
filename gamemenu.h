#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>
#include <QDesktopWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QPalette>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>

namespace Ui {
class gamemenu;
}

class gamemenu : public QWidget
{
    Q_OBJECT

public:
    explicit gamemenu(QWidget *parent = 0);
    ~gamemenu();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool enterBtn(QPoint p,QPushButton *btn);

private slots:
    void on_exit_clicked();

    void on_restart_clicked();

    void on_mainmenu_clicked();

    void on_continue_2_clicked();


private:
    Ui::gamemenu *ui;

    static bool IsOpen;

signals:

    void gm2mw();
    void gm2mm();
    void closebgm();
    void gm_restart();

};

#endif // GAMEMENU_H
