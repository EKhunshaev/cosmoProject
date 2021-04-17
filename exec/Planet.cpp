#include "../headers/header.h"

Planet::Planet() {
    weight = rad = 0;
    coord = Point();
    vel = Velocity();
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
sf::CircleShape Planet::getShape() { 
    sf::CircleShape p(rad);
    p.setPosition(coord.getX(), coord.getY());
    p.setFillColor(sf::Color(128, 128, 128));
    return p;
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

std::istream &operator>>(std::istream &in, Planet &p) {
    in >> p.weight >> p.rad >> p.coord >> p.vel;
    return in;
}
