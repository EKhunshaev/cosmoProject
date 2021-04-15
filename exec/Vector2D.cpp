#include "../headers/header.h"

Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(const double &x) {
    this->x = x;
    this->y = x;
}

Vector2D::Vector2D(const double &x, const double &y) {
    this->x = x;
    this->y = y;
}

double Vector2D::get_x() {
    return x;
}

double Vector2D::get_y() {
    return y;
}

void Vector2D::set_x(const double &x) {
    this->x = x;
}

void Vector2D::set_y(const double &y) {
    this->y = y;
}

Vector2D *Vector2D::plus(Vector2D *A) {
    return new Vector2D(x + A->get_x(), y + A->get_y());
}

Vector2D *Vector2D::minus(Vector2D *A) {
    return new Vector2D(x - A->get_x(), y - A->get_y());
}

double Vector2D::mod() {
    return sqrt(x * x + y * y);
}

double mod(const Vector2D &A) {
    return sqrt(A.x * A.x + A.y * A.y);
}

Vector2D operator+(const Vector2D &A, const Vector2D &B) {
    return Vector2D(A.x + B.x, A.y + B.y);
}

Vector2D operator-(const Vector2D &A, const Vector2D &B) {
    return Vector2D(A.x - B.x, A.y - B.y);
}

double operator*(const Vector2D &A, const Vector2D &B) {
    return A.x * B.x + A.y * B.y;
}

Vector2D operator*(const double &n, const Vector2D &B) {
    return Vector2D(n * B.x, n * B.y);
}

Vector2D operator*(const Vector2D &A, const double &n) {
    return Vector2D(A.x * n, A.y * n);
}

Vector2D operator++(Vector2D &A, int x) {
    A.x += 1;
    A.y += 1;
    return A;
}

Vector2D operator--(Vector2D &A, int x) {
    A.x -= 1;
    A.y -= 1;
    return A;
}
Vector2D operator++(Vector2D &A) {
    A.x += 1;
    A.y += 1;
    return A;
}

Vector2D operator--(Vector2D &A) {
    A.x -= 1;
    A.y -= 1;
    return A;
}
Vector2D operator+(Vector2D &A) {
    return A;
}

Vector2D operator-(Vector2D &A) {
    A.x = -A.x;
    A.y = -A.y;
    return A;
}

bool operator==(const Vector2D &A, const Vector2D &B) {
    return (A.x == B.x && A.y == B.y);
}

bool operator!=(const Vector2D &A, const Vector2D &B) {
    return !(A == B);
}

bool operator>(const Vector2D &A, const Vector2D &B) {
    return (mod(A) > mod(B));
}

bool operator<(const Vector2D &A, const Vector2D &B) {
    return (mod(A) < mod(B));
}

bool operator>=(const Vector2D &A, const Vector2D &B) {
    return (mod(A) >= mod(B));
}

bool operator<=(const Vector2D &A, const Vector2D &B) {
    return (mod(A) <= mod(B));
}

std::ostream &operator<< (std::ostream &out, const Vector2D &B) {
    out << B.x << " " << B.y << "; ";
    return out;
}

Vector2D &operator>> (std::istream &in, Vector2D &B) {
    in >> B.x >> B.y;
    return B;
}

