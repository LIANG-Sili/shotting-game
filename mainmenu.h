#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include <QPoint>
#include <QDesktopWidget>
#include <QPainter>



namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    bool enterBtn(QPoint p,QPushButton *btn);
    void paintEvent(QPaintEvent *event);

private slots:
    void on_exit_clicked();

    void on_start_clicked();

private:
    Ui::MainMenu *ui;



signals:
    void mm2mw();

};

#endif // MAINMENU_H
