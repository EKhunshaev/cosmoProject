#ifndef CALC_H
#define CALC_H

#include "header.h"

double high(Planet &p1, Ship &s1);

Force force(Planet &p1, Ship &s1);

void changeVelocity(Planet &p1, Ship &s1);
void changeVelocity(Force &f1, Ship &s1);
Velocity relVelocity (Planet &p1, Ship &s1);
Point dockPoint (Planet &p1, Ship &s1);
Velocity radVelocity (Planet &p1, Ship &s1);
#endif
