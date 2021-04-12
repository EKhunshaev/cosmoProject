#include "../headers/header.h"

double destSquare(const Point &p1, const Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Planet::Planet() {
    m = r = 0;
    X = {0, 0};
    V = {0, 0};
}
Planet::Planet(const double &m, const Point &X, const double &r, const Velocity &V) {
    this->X = X;
    this->r = r;
    this->m = m;
    this->V = V;
}

double Planet::getM() {
    return m;
}

Point Planet::getX() {
    return X;
}

double Planet::getR() {
    return r;
}
Velocity Planet::getV() {
    return V;
}

void Planet::setM(const double &m) {
    this->m = m;
}

void Planet::setX(const Point &X) {
    this->X = X;
}

void Planet::setR(const double &r) {
    this->r = r;
}

void Planet::setV(const Velocity &V) {
    this->V = V;
}

void changeVelocity(Planet &p1, Planet &p2) {
    double coeff = 10 * p1.m * p2.m / pow(destSquare(p1.X, p2.X), 3/2);
    Force F12 = {coeff * (p2.X.x - p1.X.x), coeff * (p2.X.y - p1.X.y)};
    p1.V.Vx += F12.Fx * DT;
    p1.V.Vy += F12.Fy * DT;
    p2.V.Vx -= F12.Fx * DT;
    p2.V.Vy -= F12.Fy * DT;
}

std::istream &operator>>(std::istream &in, Planet &p) {
    in >> p.m >> p.r >> p.X.x >> p.X.y >> p.V.Vx >> p.V.Vy;
    return in;
}