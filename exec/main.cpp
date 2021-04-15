#include "../headers/header.h"

int main() {
    //window - объект главного окна приложения типа RenderWindow
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    Planet p1;
    Planet p2;
    std::cin >> p1 >> p2;
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
