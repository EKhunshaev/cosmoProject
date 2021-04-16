#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
    double x, y;
public:
    Vector2D();
    Vector2D(const double &x);
    Vector2D(const double &x, const double &y);

    double getX();
    double getY();

    void setX(const double &x);
    void setY(const double &y);

    double mod();

    friend double mod(const Vector2D &A);
    friend Vector2D operator+(const Vector2D &A, const Vector2D &B);
    friend Vector2D operator-(const Vector2D &A, const Vector2D &B);
    friend double operator*(const Vector2D &A, const Vector2D &B);
    friend Vector2D operator*(const Vector2D &A, const double &n);
    friend Vector2D operator*(const double &n, const Vector2D &A);

    friend Vector2D &operator+=(Vector2D &V1, const Vector2D &V2);
    friend Vector2D &operator-=(Vector2D &V1, const Vector2D &V2);
    friend Vector2D &operator*=(Vector2D &V, const double &N);

    friend Vector2D operator++(Vector2D &A, int x);
    friend Vector2D operator--(Vector2D &A, int x);
    friend Vector2D operator++(Vector2D &A);
    friend Vector2D operator--(Vector2D &A);
    friend Vector2D operator+(Vector2D &A);
    friend Vector2D operator-(Vector2D &A);

    friend bool operator==(const Vector2D &A, const Vector2D &B);
    friend bool operator!=(const Vector2D &A, const Vector2D &B);
    friend bool operator>(const Vector2D &A, const Vector2D &B);
    friend bool operator<(const Vector2D &A, const Vector2D &B);
    friend bool operator>=(const Vector2D &A, const Vector2D &B);
    friend bool operator<=(const Vector2D &A, const Vector2D &B);

    friend std::ostream &operator<<(std::ostream &out, const Vector2D &B);
    friend std::istream &operator>>(std::istream &in, Vector2D &B);

};

//typedef for vector quantities in physics
typedef Vector2D Point;
typedef Vector2D Velocity;
typedef Vector2D Accel;
typedef Vector2D Force;

#endif
