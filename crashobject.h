#ifndef CRASHOBJECT_H
#define CRASHOBJECT_H

#include <QObject>
#include <QString>

class crashObject : public QObject
{
    Q_OBJECT
public:
    //之后有新的类名记得加到这里
    enum{
        user = 0,
        enemy,
        bullet,
        items
    };


    explicit crashObject(QObject *parent = nullptr);


    int x,y;
    int H;
    int W;

    float run_x;
    float run_y;
    int pace;

    bool crash(crashObject *);

    QString imagepath;

signals:




public slots:

};

#endif // CRASHOBJECT_H
