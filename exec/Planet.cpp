#include "../headers/header.h"

Planet::Planet() {
    weight = rad = 0;
    coord = Point();
    vel = Velocity();
    circle.setFillColor(sf::Color(200, 50, 50));
}

Planet::Planet(const double &weight , const Point &coord, const double &rad, const Velocity &vel) {
    this->coord = coord;
    this->rad = rad;
    this->weight = weight ;
    this->vel = vel;
    this->circle.setRadius(rad);
    this->circle.setFillColor(sf::Color(200, 50, 50));
    this->circle.setPosition(this->coord.getX(), this->coord.getY());
    this->circle.setOrigin(rad, rad);
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

sf::CircleShape Planet::getCircle() {
    return circle;
}

void Planet::setWeight(const double &weight) {
    this->weight = weight;
}

void Planet::setCoord(const Point &coord) {
    this->coord = coord;
    this->circle.setPosition(this->coord.getX(), this->coord.getY());
}

void Planet::setRad(const double &rad) {
    this->rad = rad;
    this->circle.setRadius(rad);
    this->circle.setOrigin(rad, rad);
}

void Planet::setVel(const Velocity &vel) {
    this->vel = vel;
}

void Planet::setColor(const sf::Color &color) {
    this->circle.setFillColor(color);
}

Force force(Planet &p1, Planet &p2) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.getWeight() * p2.getWeight() / pow(mod(p1.getCoord() - p2.getCoord()) ,3);
    Force f12 = Force(coeff * (p2.getCoord().getX() - p1.getCoord().getX()), coeff * (p2.getCoord().getY() - p1.getCoord().getY()));
    return(f12);
}

void changeVelocity(Planet &p1, Planet &p2) {
    Force f12 = force(p1, p2);
    p1.setVel(p1.getVel() + f12 * (DT / p1.getWeight()));
    p2.setVel(p2.getVel() - f12 * (DT / p2.getWeight()));
}     


std::istream &operator>>(std::istream &in, Planet &p) {
    in >> p.weight >> p.rad >> p.coord >> p.vel;
    p.circle.setRadius(p.rad);
    p.circle.setFillColor(sf::Color(200, 50, 50));
    p.circle.setPosition(p.coord.getX(), p.coord.getY());
    p.circle.setOrigin(p.rad, p.rad);
    return in;
}
