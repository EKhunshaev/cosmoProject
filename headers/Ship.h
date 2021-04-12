#ifndef SHIP_H
#define SHIP_H

#include "header.h"

class Ship {
protected:
    double weight;
    Vector2D coord;
    Vector2D speed;
    Vector2D accel;
public:
    Ship(double weight);
    Ship(double weight, Vector2D coord, Vector2D speed, Vector2D accel); 

    double get_weight();
    Vector2D get_coord();
    Vector2D get_speed();
    Vector2D get_accel();

	void set_weight(double weight);
	void set_coord(Vector2D coord);
	void set_speed(Vector2D speed);
	void set_accel(Vector2D accel);

	friend std::ostream &operator << (std::ostream &out, Ship &S);
	friend Ship &operator >> (std::istream &in, Ship &S);
};

#endif
