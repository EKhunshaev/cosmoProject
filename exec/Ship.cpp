#include "../headers/header.h"

Ship::Ship() {
    weight =  0;
    coord = Point();
    vel = Velocity();
}

Ship::Ship(const double &weight, const Point &coord, const Velocity &vel) {
    this->coord = coord;
    this->weight = weight ;
    this->vel = vel;
}

double Ship::getWeight() {
    return weight;
}

Point Ship::getCoord() {
    return coord;
}

Velocity Ship::getVel() {
    return vel;
}
sf::CircleShape Ship::getShape() { 
    sf::CircleShape s(30);
    s.setPosition(coord.getX(), coord.getY());
    s.setFillColor(sf::Color(128, 128, 128));
    return s;
}

void Ship::setWeight(const double &weight) {
    this->weight = weight;
}

void Ship::setCoord(const Point &coord) {
    this->coord = coord;
}

void Ship::setVel(const Velocity &vel) {
    this->vel = vel;
} 

std::istream &operator>>(std::istream &in, Ship &s) {
    in >> s.weight >> s.coord >> s.vel;
    return in;
}

