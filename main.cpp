#include "windows.h"
#include <QApplication>

#include "startlogo.h"    //

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    startlogo sl;
    sl.show();
    Sleep(2000);
    sl.close();


    windows wd;

    return a.exec();
}
