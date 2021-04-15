#include "../headers/header.h"

Vector2D dist(Ship S, Planet P)
{
    Vector2D D = P.get_coord() - S.get_coord();
    return (D);
}

Vector2D force(Ship S, Planet P)
{
    Vector2D D = dist(S, P);
    double L = mod(D);
    return( G * S.get_weight() * P.get_weight() / ( L * L * L) * D);
}       
