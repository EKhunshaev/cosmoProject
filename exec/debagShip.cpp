#include "../headers/header.h"

int main() {
    Point P1(600, 600);
    Point P2 (300, 400);
    Point P3 (400, 400);

    Velocity V1(10, 10);
    Velocity V2(0, 7);
    Velocity V3(0, 0);

    Ship S(50, P1, V1);
    Planet Pl1(1, P2, 10, V2);
    Planet Pl2(5000, P3, 10, V3);

    Force F = forceP(Pl1, Pl2);
    std::cout <<F <<"\n";

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
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
        window.draw(S.getShape());
        window.draw(Pl1.getShape());
        window.draw(Pl2.getShape());
        window.display();
        changeVelocity(Pl1, Pl2);        

        Pl1.getShape().move(Pl1.getVel().getX() * DT, Pl1.getVel().getY() * DT);
        Pl1.setCoord({Pl1.getCoord().getX() + Pl1.getVel().getX() * DT, Pl1.getCoord().getY() + Pl1.getVel().getY() * DT});
        Pl2.getShape().move(Pl2.getVel().getX() * DT, Pl2.getVel().getY() * DT);
        Pl2.setCoord({Pl2.getCoord().getX() + Pl2.getVel().getX() * DT, Pl2.getCoord().getY() + Pl2.getVel().getY() * DT});
    }


    return 0;
}

