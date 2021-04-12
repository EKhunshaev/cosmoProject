#include "../headers/header.h"

int main() {
    //window - объект главного окна приложения типа RenderWindow
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    Planet p1;
    Planet p2;
    std::cin >> p1 >> p2;
    sf::CircleShape planet1(p1.getR());
    planet1.setPosition(p1.getX().x, p1.getX().y);

    sf::CircleShape planet2(p2.getR());
    planet2.setPosition(p2.getX().x, p2.getX().y);

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
        planet1.move(p1.getV().Vx * DT, p1.getV().Vy * DT);
        p1.setX({p1.getX().x + p1.getV().Vx * DT, p1.getX().y + p1.getV().Vy * DT});
        planet2.move(p2.getV().Vx * DT, p2.getV().Vy * DT);
        p2.setX({p2.getX().x + p2.getV().Vx * DT, p2.getX().y + p2.getV().Vy * DT});
    }

    return 0;
}


100 50 100 350 0 100
100 50 700 350 0 -100