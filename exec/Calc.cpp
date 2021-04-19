#include "../headers/header.h"

double high(Ship &S, Planet &P)
{
    double D = mod(P.getCoord() - S.getCoord()) - P.getRad();
    return (D);
}

Force force(Planet &p1, Planet &p2) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.getWeight() * p2.getWeight() / pow(mod(p1.getCoord() - p2.getCoord()) ,3);
    Force f12 = 10 * Force(coeff * (p2.getCoord().getX() - p1.getCoord().getX()), coeff * (p2.getCoord().getY() - p1.getCoord().getY()));
    return(f12);
}
Force force(Planet &p1, Ship &s1) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.getWeight() * s1.getWeight() / pow(mod(p1.getCoord() - s1.getCoord()) ,3);
    Force f12 = 100 * Force(coeff * (s1.getCoord().getX() - p1.getCoord().getX()), coeff * (s1.getCoord().getY() - p1.getCoord().getY()));
    return(f12);
}

void changeVelocity(Planet &p1, Planet &p2) {
    Force f12 = force(p1, p2);
    p1.setVel(p1.getVel() + f12 * (DT / p1.getWeight()));
    p2.setVel(p2.getVel() - f12 * (DT / p2.getWeight()));
}     
void changeVelocity(Planet &p1, Ship &s1) {
    Force f12 = force(p1, s1);
    s1.setVel(s1.getVel() - f12 * (DT / s1.getWeight()));
}

void changeVelocity(Force &f, Ship &s) {
    s.setVel(s.getVel() - f * (DT / s.getWeight()));
}
