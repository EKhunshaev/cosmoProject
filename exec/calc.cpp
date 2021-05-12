#include "../headers/header.h"

double high(Planet &p1, Ship &s1)
{
    double dist = mod(p1.getCoord() - s1.getCoord()) - p1.getRad();
    return (dist);
}

Force force(Planet &p1, Ship &s1) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.getWeight() * s1.getWeight() / pow(mod(p1.getCoord() - s1.getCoord()) ,3);
    Force f12 = Force(coeff * (s1.getCoord().getX() - p1.getCoord().getX()), coeff * (s1.getCoord().getY() - p1.getCoord().getY()));
    return(f12);
}

void changeVelocity(Planet &p1, Ship &s1) {
    Force f12 = force(p1, s1);
    s1.setVel(s1.getVel() - f12 * (DT / s1.getWeight()));
}

void changeVelocity(Force &f1, Ship &s1) {
    s1.setVel(s1.getVel() - f1 * (DT / s1.getWeight()));
}

Velocity relVelocity (Planet &p1, Ship &s1) {
    Velocity rel = s1.getVel()-p1.getVel();
    return rel;
}

Point dockPoint (Planet &p1, Ship &s1) {
    Point r12 = s1.getCoord() - p1.getCoord();
    Point dock = p1.getCoord() + r12 * ((p1.getRad() + 2.5) / r12.mod());
    return dock;
}

Velocity radVelocity (Planet &p1, Ship &s1) {
    Velocity rad = (s1.getCoord() - p1.getCoord()) * (1 / mod(s1.getCoord() - p1.getCoord()));
    return rad;
}
