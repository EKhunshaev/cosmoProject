#ifndef SHIP_H
#define SHIP_H

#include "header.h"

class Ship
{
protected:
    double weight;
    Point coord;
    Velocity vel;
    sf::CircleShape ship;
public:
    Ship();
    Ship(const double &m, const Point &X, const Velocity &V);

    double getWeight();
    Point getCoord();
    Velocity getVel(); 
    sf::CircleShape getShape();
    
    void setWeight(const double &m);
    void setCoord(const Point &X);
    void setVel(const Velocity &V);
    
    friend std::istream &operator>>(std::istream &in, Ship &p);
};

#endif //SHIP_H

