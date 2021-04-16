#include "../headers/header.h"

int main() {
    Point P1(30, 30);
    Point P2 (300, 300);
    Point P3 (400, 400);

    Velocity V1(10, 10);
    Velocity V2(100, 100);
    Velocity V3(0, 0);

    Ship S(50, P1, V1);
    Planet Pl1(50, P2, 100, V2);
    Planet Pl2(50, P3, 100, V3);

    Force F = forceP(Pl1, Pl2);
    std::cout <<F <<"\n";

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape s1 = draw(S);
    sf::CircleShape p1 = draw(Pl1);
    //Главный цикл приложения который выпоняется пока открыто окно
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color(0x0e, 0x0e, 0x57));
        window.draw(s1);
        window.draw(p1);
        window.display();
//        changeVelocity(p1, p2);
//        planet1.move(p1.getVel().getX() * DT, p1.getVel().getY() * DT);
//        p1.setCoord({p1.getCoord().getX() + p1.getVel().getX() * DT, p1.getCoord().getY() + p1.getVel().getY() * DT});
//        planet2.move(p2.getVel().getX() * DT, p2.getVel().getY() * DT);
//        p2.setCoord({p2.getCoord().getX() + p2.getVel().getX() * DT, p2.getCoord().getY() + p2.getVel().getY() * DT});
    }


    return 0;
}

