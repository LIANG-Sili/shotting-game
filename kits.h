#ifndef KITS_H
#define KITS_H

#include <QString>

class picture
{
public:
    int x;
    int y;
    int w;
    int h;
    QString Path;


    picture(int X,int Y,int W,int H,QString path);
};

#endif // KITS_H
