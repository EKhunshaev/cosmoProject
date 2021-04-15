#include <iostream>
#include <cmath>
#include "../headers/header.h"


Ship::Ship(double weight)
{
	this->weight = weight;
	this->coord = 0;
	this->speed = 0;
	this->accel = 0;
}
Ship::Ship(double weight, Vector2D coord, Vector2D speed, Vector2D accel)
{
	this->weight = weight;
	this->coord = coord;
	this->speed = speed;
	this->accel = accel;
}


void Ship::set_weight(double weight)
{
	this->weight = weight;
}
void Ship::set_coord(Vector2D coord)
{       
    this->coord = coord;
}
void Ship::set_speed(Vector2D speed)
{       
    this->speed = speed;
}
void Ship::set_accel(Vector2D accel)
{       
   this->accel = accel;
}


double Ship::get_weight()
{
    return weight;
}
Vector2D Ship::get_coord()
{
    return coord;
}

Vector2D Ship::get_speed()
{
    return speed;
}

Vector2D Ship::get_accel()
{
    return accel;
}

std::ostream &operator << (std::ostream &out, Ship &S)
{
    out <<S.weight <<"; " <<S.coord <<" " <<S.speed <<" " <<S.accel;
	return out;
}
Ship &operator >> (std::istream &in, Ship &S)
{
    double C1, C2, S1, S2, A1, A2;
    in >>S.weight >>C1 >>C2 >>S1 >>S2 >>A1 >>A2;
    Vector2D coord (C1, C2);
    Vector2D speed (S1, S2);
    Vector2D accel (A1, A2);
    S.set_coord(coord);
    S.set_speed(speed);
    S.set_accel(accel);
    return S;
}
