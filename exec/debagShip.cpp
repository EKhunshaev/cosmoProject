#include "../headers/header.h"

int main() {
    double m = 50;
    Point P(30, 30);
    Velocity V(10, 10);
    Ship S(m, P, V);
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape s1 = draw(S);
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
        window.display();
//        changeVelocity(p1, p2);
//        planet1.move(p1.getVel().getX() * DT, p1.getVel().getY() * DT);
//        p1.setCoord({p1.getCoord().getX() + p1.getVel().getX() * DT, p1.getCoord().getY() + p1.getVel().getY() * DT});
//        planet2.move(p2.getVel().getX() * DT, p2.getVel().getY() * DT);
//        p2.setCoord({p2.getCoord().getX() + p2.getVel().getX() * DT, p2.getCoord().getY() + p2.getVel().getY() * DT});
    }


    return 0;
}

