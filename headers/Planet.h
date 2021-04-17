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
public:
    Planet();
    Planet(const double &m, const Point &X, const double &r, const Velocity &V);

    double getWeight();
    double getRad();
    Point getCoord();
    Velocity getVel();
    sf::CircleShape getShape();

    void setWeight(const double &m);
    void setRad(const double &r);
    void setCoord(const Point &X);
    void setVel(const Velocity &V);
 
    friend std::istream &operator>>(std::istream &in, Planet &p);
};

#endif //PLANET_H
