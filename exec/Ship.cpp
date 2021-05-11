#include "../headers/header.h"

Ship::Ship() {
    weight =  0;
    coord = Point();
    vel = Velocity();
    ship.setFillColor(sf::Color::Green);
    ship.setPointCount(3);
}

Ship::Ship(const double &weight, const Point &coord, const Velocity &vel) {
    this->coord = coord;
    this->weight = weight ;
    this->vel = vel;
    ship.setPosition(this->coord.getX(), this->coord.getY());
    ship.setFillColor(sf::Color::Green);
    ship.setPointCount(3);
    ship.setRadius(5);
    ship.setOrigin(5, 5);
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
    return ship;
}

void Ship::setWeight(const double &weight) {
    this->weight = weight;
}

void Ship::setCoord(const Point &coord) {
    this->coord = coord;
    ship.setPosition(this->coord.getX(), this->coord.getY());
}

void Ship::setVel(const Velocity &vel) {
    this->vel = vel;
}

std::istream &operator>>(std::istream &in, Ship &s) {
    in >> s.weight >> s.coord >> s.vel;
    s.ship.setPosition(s.coord.getX(), s.coord.getY());
    s.ship.setFillColor(sf::Color::Green);
    s.ship.setPointCount(3);
    s.ship.setRadius(5);
    s.ship.setOrigin(5, 5);
    return in;
}

