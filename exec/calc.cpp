#include "../headers/header.h"

double high(Ship &S, Planet &P)
{
    double D = mod(P.getCoord() - S.getCoord()) - P.getRad();
    return (D);
}

Force force(Planet &p1, Ship &s1) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.getWeight() * s1.getWeight() / pow(mod(p1.getCoord() - s1.getCoord()) ,3);
    Force f12 = 100 * Force(coeff * (s1.getCoord().getX() - p1.getCoord().getX()), coeff * (s1.getCoord().getY() - p1.getCoord().getY()));
    return(f12);
}

void changeVelocity(Planet &p1, Ship &s1) {
    Force f12 = force(p1, s1);
    s1.setVel(s1.getVel() - f12 * (DT / s1.getWeight()));
}

void changeVelocity(Force &f, Ship &s) {
    s.setVel(s.getVel() - f * (DT / s.getWeight()));
}
