#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QDesktopWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>

namespace Ui {
class gameover;
}

class gameover : public QWidget
{
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = 0);
    ~gameover();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool enterBtn(QPoint p,QPushButton *btn);

private slots:
    void on_restart_clicked();

    void on_mainmenu_clicked();

    void on_exit_clicked();

private:
    Ui::gameover *ui;

signals:
    void go2mm();
    void go_restart();
};

#endif // GAMEOVER_H
