#ifndef PLANET_H
#define PLANET_H

#include "header.h"

class Planet
{
protected:
    double weight;
    double rad;
    Point coord;
    Velocity vel;
    sf::CircleShape circle;
public:
    Planet();
    Planet(const double &m, const Point &X, const double &r, const Velocity &V);

    double getWeight();
    double getRad();
    Point getCoord();
    Velocity getVel();
    sf::CircleShape getCircle();

    void setWeight(const double &m);
    void setRad(const double &r);
    void setCoord(const Point &X);
    void setColor(const sf::Color &c);
    void setVel(const Velocity &V);

    friend Force force(Planet &p1, Planet &p2);
    friend void changeVelocity(Planet &p1, Planet &p2);

    friend std::istream &operator>>(std::istream &in, Planet &p);
};

#endif //PLANET_H
