#include "../headers/header.h"

int main() {
    std::ifstream file("systems/twoPlanetSystem.txt");
    if (file.is_open()) {
        //window - объект главного окна приложения типа RenderWindow
        sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
        int pCount = 0;
        file >> pCount;
        std::vector<Planet> planets(pCount);
        std::vector<sf::CircleShape> planetPics(pCount);
        for (int i = 0; i < pCount; ++i) {
            //Читаю из файла
            file >> planets[i];

            planetPics[i].setRadius(planets[i].getRad());
            planetPics[i].setFillColor(sf::Color(200, 50, 50));
            planetPics[i].setPosition(planets[i].getCoord().getX(), planets[i].getCoord().getY());
            planetPics[i].setOrigin(planets[i].getRad(), planets[i].getRad());
        }


        //Главный цикл приложения который выпоняется пока открыто окно
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            //Отрисовка окна
            window.clear(sf::Color(0x0e, 0x0e, 0x57));

            for (int i = 0; i < pCount; ++i) {
                window.draw(planetPics[i]);
            }

            window.display();

            //Измеение положений тел
            for (int i = 0; i < pCount; ++i) {
                for (int j = i + 1; j < pCount; ++j) {
                    changeVelocity(planets[i], planets[j]);
                }
            }

            for (int i = 0; i < pCount; ++i) {
                planets[i].setCoord({planets[i].getCoord().getX() + planets[i].getVel().getX() * DT,
                                     planets[i].getCoord().getY() + planets[i].getVel().getY() * DT});
                planetPics[i].move(planets[i].getVel().getX() * DT, planets[i].getVel().getY() * DT);
            }
        }
    }
    return 0;
}
