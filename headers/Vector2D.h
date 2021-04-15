#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
    double x, y;
public:
    Vector2D();
    Vector2D(const double &x);
    Vector2D(const double &x, const double &y);

    double get_x();
    double get_y();

    void set_x(const double &x);
    void set_y(const double &y);

    Vector2D *plus(Vector2D *A);
    Vector2D *minus(Vector2D *A);

    double mod();

    friend double mod(const Vector2D &A);
    friend Vector2D operator+(const Vector2D &A, const Vector2D &B);
    friend Vector2D operator-(const Vector2D &A, const Vector2D &B);
    friend double operator*(const Vector2D &A, const Vector2D &B);
    friend Vector2D operator*(const Vector2D &A, const double &n);
    friend Vector2D operator*(const double &n, const Vector2D &A);

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
    friend Vector2D &operator>>(std::istream &in, Vector2D &B);

};

#endif
