#ifndef STARTLOGO_H
#define STARTLOGO_H

#include <QWidget>

namespace Ui {
class startlogo;
}

class startlogo : public QWidget
{
    Q_OBJECT

public:
    explicit startlogo(QWidget *parent = 0);
    ~startlogo();

private:
    Ui::startlogo *ui;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // STARTLOGO_H
