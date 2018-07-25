#ifndef STAGECLEAR_H
#define STAGECLEAR_H

#include <QWidget>

namespace Ui {
class stageclear;
}

class stageclear : public QWidget
{
    Q_OBJECT

public:
    explicit stageclear(QWidget *parent = 0);
    ~stageclear();

private:
    Ui::stageclear *ui;
};

#endif // STAGECLEAR_H
