#include "../headers/header.h"

int main() {
    Vector2D V1(1,1);
    Vector2D V2(1,1);
    Vector2D V3(1,1);
    Vector2D V4(31, 31);
    Vector2D V5;
    Vector2D V6(2, 1);

    Planet P2(50, 13);
    Planet P3(50, 13, V1, V2, V3);

    Ship S1(50, V6, V2, V3);
 
    std::cout <<"P2 is " <<P2 <<"\n"; 
    std::cout <<"P3 is " <<P3 <<"\n";
    P2.set_weight(31);
    P2.set_radius(14);
    P2.set_coord(V4);
    std::cout <<"P2 new is " <<P2 <<"\n";    

    double x1 = P3.get_weight();
    V5 = P2.get_coord();
    std::cout <<x1 <<" " <<V5 <<"\n";
    double x2 = P2.get_coord().get_x();
    std::cout <<x2 <<"\n";

    Vector2D V7 = dist(&S1, &P3);
    return 0;
}

