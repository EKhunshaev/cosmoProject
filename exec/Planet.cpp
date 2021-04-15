#include "../headers/header.h"

Planet::Planet() {
    weight = rad = 0;
    coord = Point(0, 0);
    vel = Velocity(0, 0);
}
Planet::Planet(const double &weight , const Point &coord, const double &rad, const Velocity &vel) {
    this->coord = coord;
    this->rad = rad;
    this->weight = weight ;
    this->vel = vel;
}

double Planet::getWeight() {
    return weight;
}

Point Planet::getCoord() {
    return coord;
}

double Planet::getRad() {
    return rad;
}
Velocity Planet::getVel() {
    return vel;
}

void Planet::setWeight(const double &weight) {
    this->weight = weight;
}

void Planet::setCoord(const Point &coord) {
    this->coord = coord;
}

void Planet::setRad(const double &rad) {
    this->rad = rad;
}

void Planet::setVel(const Velocity &vel) {
    this->vel = vel;
}

void changeVelocity(Planet &p1, Planet &p2) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.weight * p2.weight /
            pow(mod(p1.coord - p2.coord) ,3);
    Force f12 = Vector2D(coeff * (p2.coord.getX() - p1.coord.getX()),
                            coeff * (p2.coord.getY() - p1.coord.getY()));
    p1.vel += f12 * (DT / p1.getWeight());
    p2.vel -= f12 * (DT / p2.getWeight());
}

std::istream &operator>>(std::istream &in, Planet &p) {
    in >> p.weight >> p.rad >> p.coord >> p.vel;
    return in;
}