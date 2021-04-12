#include "../headers/header.h"

int main() {
    Vector2D V1(1,1);
    Vector2D V2(1,1);
    Vector2D V3(1,1);
    Vector2D V4(31, 31);
    Vector2D V5;

    Ship S2(50);
    Ship S3(50, V1, V2, V3); 
    std::cout <<"S2 is " <<S2 <<"\n"; 
    std::cout <<"S3 is " <<S3 <<"\n";
    S2.set_weight(31);
    S2.set_coord(V4);
    std::cout <<"S2 new is " <<S2 <<"\n";    

    double x1 = S3.get_weight();
    V5 = S2.get_coord();
    std::cout <<x1 <<" " <<V5 <<"\n";
    return 0;
}
