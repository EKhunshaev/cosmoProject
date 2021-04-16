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

void Ship::setWeight(const double &weight) {
    this->weight = weight;
}

void Ship::setCoord(const Point &coord) {
    this->coord = coord;
}

void Ship::setVel(const Velocity &vel) {
    this->vel = vel;
}

sf::CircleShape draw(Ship &S) {
    sf::CircleShape s1(30);
    s1.setPosition(S.getCoord().getX(), S.getCoord().getY());
    s1.setFillColor(sf::Color(128, 128, 128));
    return s1;
  }  

void changeVelocity(Ship &p1, Planet &p2) {
    //Gravitational Force = Y m1 * m2 / r^3 * vect(r)
    double coeff = p1.weight * p2.getWeight() /
            pow(mod(p1.coord - p2.getCoord()) ,3);
    Force f12 = Force(coeff * (p2.getCoord().getX() - p1.coord.getX()),
                            coeff * (p2.getCoord().getY() - p1.coord.getY()));
    p1.vel += f12 * (DT / p1.weight);
}

std::istream &operator>>(std::istream &in, Ship &s) {
    in >> s.weight >> s.coord >> s.vel;
    return in;
}

