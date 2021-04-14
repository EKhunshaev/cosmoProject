#ifndef PLANET_H
#define PLANET_H

#include "header.h"

class Planet {
protected:
    double weight;
    double radius;
    Vector2D coord;
    Vector2D speed;
    Vector2D accel;
public:
    Planet(double weight, double radius);
    Planet(double weight, double radius, Vector2D coord, Vector2D speed, Vector2D accel); 

    double get_weight();
    double get_radius();
    Vector2D get_coord();
    Vector2D get_speed();
    Vector2D get_accel();

	void set_weight(double weight);
    void set_radius(double radius);
	void set_coord(Vector2D coord);
	void set_speed(Vector2D speed);
	void set_accel(Vector2D accel);

	friend std::ostream &operator << (std::ostream &out, Planet &S);
	friend Planet &operator >> (std::istream &in, Planet &S);
};

#endif
