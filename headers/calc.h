#ifndef CALC_H
#define CALC_H

#include "header.h"

double high(Ship &s, Planet &p);

Force force(Planet &p1, Ship &s1);

void changeVelocity(Planet &p1, Ship &s1);
void changeVelocity(Force &f, Ship &s);

#endif
