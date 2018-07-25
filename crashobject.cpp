#include "crashobject.h"

crashObject::crashObject(QObject *parent) : QObject(parent)
{

}


bool crashObject::crash(crashObject *obj)
{
    if(this->x + this->W >= obj->x
            && obj->x + obj->W >= this->x
            && this->y + this->H >= obj->y
            && obj->y + obj->H >= this->y)
        return true;
    else
        return false;
}
