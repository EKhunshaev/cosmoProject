#ifndef SHIP_H
#define SHIP_H

#include "header.h"

class Ship
{
protected:
    double weight;
    Point coord;
    Velocity vel;
public:
    Ship();
    Ship(const double &m, const Point &X, const Velocity &V);

    double getWeight();
    Point getCoord();
    Velocity getVel();

    void setWeight(const double &m);
    void setCoord(const Point &X);
    void setVel(const Velocity &V);
    
    friend sf::CircleShape draw(Ship &S);
    friend void changeVelocity(Ship &p1, Planet &p2);
    friend std::istream &operator>>(std::istream &in, Ship &p);
};

#endif //SHIP_H

