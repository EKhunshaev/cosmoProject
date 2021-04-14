#include <iostream>
#include <cmath>
#include "../headers/header.h"


Planet::Planet(double weight, double radius)
{
	this->weight = weight;
    this->radius = radius;
	this->coord = 0;
	this->speed = 0;
	this->accel = 0;
}
Planet::Planet(double weight, double radius, Vector2D coord, Vector2D speed, Vector2D accel)
{
	this->weight = weight;
    this->radius = radius;
	this->coord = coord;
	this->speed = speed;
	this->accel = accel;
}


void Planet::set_weight(double weight)
{
	this->weight = weight;
}
void Planet::set_radius(double radius)
{
	this->radius = radius;
}
void Planet::set_coord(Vector2D coord)
{       
    this->coord = coord;
}
void Planet::set_speed(Vector2D speed)
{       
    this->speed = speed;
}
void Planet::set_accel(Vector2D accel)
{       
   this->accel = accel;
}


double Planet::get_weight()
{
    return weight;
}
double Planet::get_radius()
{
    return radius;
}
Vector2D Planet::get_coord()
{
    return coord;
}

Vector2D Planet::get_speed()
{
    return speed;
}

Vector2D Planet::get_accel()
{
    return accel;
}


std::ostream &operator << (std::ostream &out, Planet &S)
{
    out <<S.weight <<"; " <<S.radius <<"; " <<S.coord <<" " <<S.speed <<" " <<S.accel;
	return out;
}
Planet &operator >> (std::istream &in, Planet &S)
{
    double C1, C2, S1, S2, A1, A2;
    in >>S.weight >>S.radius >>C1 >>C2 >>S1 >>S2 >>A1 >>A2;
    Vector2D coord (C1, C2);
    Vector2D speed (S1, S2);
    Vector2D accel (A1, A2);
    S.set_coord(coord);
    S.set_speed(speed);
    S.set_accel(accel);
    return S;
}

