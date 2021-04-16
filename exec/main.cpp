#include "../headers/header.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    Point V1 (100, 100);
    Point V3 (300, 300);
    Velocity V2 (50, 50);
    Velocity V4 (50, 50);
    Planet p1(50, V1, 50, V2);
    Planet p2(50, V3, 50, V4);
    sf::CircleShape planet1(p1.getRad());
    planet1.setPosition(p1.getCoord().getX(), p1.getCoord().getY());

    sf::CircleShape planet2(p2.getRad());
    planet2.setPosition(p2.getCoord().getX(), p2.getCoord().getY());

    planet1.setFillColor(sf::Color::Cyan);
    planet2.setFillColor(sf::Color::Red);

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
        window.draw(planet1);
        window.draw(planet2);
        window.display();
        changeVelocity(p1, p2);
        planet1.move(p1.getVel().getX() * DT, p1.getVel().getY() * DT);
        p1.setCoord({p1.getCoord().getX() + p1.getVel().getX() * DT, p1.getCoord().getY() + p1.getVel().getY() * DT});
        planet2.move(p2.getVel().getX() * DT, p2.getVel().getY() * DT);
        p2.setCoord({p2.getCoord().getX() + p2.getVel().getX() * DT, p2.getCoord().getY() + p2.getVel().getY() * DT});
    }

    return 0;
}
