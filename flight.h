#ifndef FLIGHT_H
#define FLIGHT_H

#include "crashobject.h"
#include <QVector>
#include "weapon.h"

class flight : public crashObject
{

public:
    flight();


    int health;
    weapon* wp;
};

#endif // FLIGHT_H
