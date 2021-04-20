#include "../headers/header.h"

int main() {
    std::ifstream file("systems/twoPlanetSystem.txt");
    if (file.is_open()) {
        //window - объект главного окна приложения типа RenderWindow
        sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
        sf::View windowView = window.getView();
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

        bool isViewMove = false;
        sf::Vector2f mousePos;
        //Главный цикл приложения который выпоняется пока открыто окно
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::MouseWheelScrolled) {
                    sf::Vector2f viewMove = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView) - windowView.getCenter();
                    viewMove.x *= 0.05 * event.mouseWheelScroll.delta;
                    viewMove.y *= 0.05 * event.mouseWheelScroll.delta;
                    windowView.zoom(event.mouseWheelScroll.delta > 0 ? 0.95 : 1 / 0.95);
                    windowView.move(viewMove);
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left && !isViewMove) {
                        mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
                        isViewMove = true;
                    }
                } else if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        isViewMove = false;
                    }

                }
            }

            if (isViewMove) {
                windowView.move(mousePos - window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView));
                mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
            }
            //Отрисовка окна
            window.clear(sf::Color(0x0e, 0x0e, 0x57));

            for (int i = 0; i < pCount; ++i) {
                window.draw(planetPics[i]);
            }

            window.setView(windowView);
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
