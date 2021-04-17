#ifndef CALC_H
#define CALC_H

#include "header.h"

const double G = 6.67e-11;

double high(Ship &S, Planet &P);

Force forceP(Planet &P1, Planet &P2);
void changeVelocity(Planet &P1, Planet &P2);



#endif
