//#ifndef PLANET_H
//#define PLANET_H
#pragma once

#include "header.h"

struct Point
{
    double x;
    double y;
};

double destSquare(const Point &p1, const Point &p2);

struct Velocity
{
    double Vx;
    double Vy;
};

struct Force
{
    double Fx;
    double Fy;
};

class Planet
{
protected:
    double m;
    Point X;
    double r; //radius
    Velocity V;
public:
    Planet();
    Planet(const double &m, const Point &X, const double &r, const Velocity &V);

    double getM();
    Point getX();
    double getR();
    Velocity getV();

    void setM(const double &m);
    void setX(const Point &X);
    void setR(const double &r);
    void setV(const Velocity &V);

    friend void changeVelocity(Planet &p1, Planet &p2);
    friend std::istream &operator>>(std::istream &in, Planet &p);
};

//#endif //PLANET_H
