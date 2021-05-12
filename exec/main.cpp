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
        Ship ship;
        Velocity shipV;
        Point shipP;

        for (int i = 0; i < pCount; ++i) {
            //Читаю из файла
            file >> planets[i];
        }
        file >> ship;
        bool isViewMove = false;
        sf::Vector2f mousePos;

        float wantFps = 600;

        sf::Clock loopTimer;

        //Индикаторы посадки dockInd = 0 - свободный полёт, 1 - посадка
        int dockInd = 0;
        int dockPlanet = -1;
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                shipV.setX(ship.getVel().getX() - 0.1);
                shipV.setY(ship.getVel().getY());
                ship.setVel(shipV);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shipV.setX(ship.getVel().getX() + 0.1);
                shipV.setY(ship.getVel().getY());
                ship.setVel(shipV);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                shipV.setX(ship.getVel().getX());
                shipV.setY(ship.getVel().getY() - 0.1);
                ship.setVel(shipV);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                shipV.setX(ship.getVel().getX());
                shipV.setY(ship.getVel().getY() + 0.1);
                ship.setVel(shipV);
            }
            if (dockInd == 1) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
          //          shipV = ship.getVel() + 1 * radVelocity(planets[dockPlanet], ship);
          //          ship.setVel(shipV);
                    shipP = ship.getCoord() + 3 * radVelocity(planets[dockPlanet], ship);
                    ship.setCoord(shipP);
                    dockInd = 0;
                    dockPlanet = -1;
                }
            }

            if (isViewMove) {
                windowView.move(mousePos - window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView));
                mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
            }
            //Отрисовка окна
            window.clear(sf::Color(0x0e, 0x0e, 0x57));

            for (int i = 0; i < pCount; ++i) {
                window.draw(planets[i].getCircle());
            }
            window.draw(ship.getShape());

            window.setView(windowView);
            window.display();
            //Обработка столкновений

            for (int i = 0; i < pCount; ++i) {
                if (high(planets[i], ship) <= 5 && relVelocity(planets[i], ship).mod() > 50) {
                    window.close();
                }
                if (high(planets[i], ship) <= 5 && relVelocity(planets[i], ship).mod() <= 50) {
                    dockInd = 1;
                    dockPlanet = i;
                    ship.setVel(planets[i].getVel());
                    ship.setCoord(dockPoint(planets[i], ship));
                }
            }
            //Измеение положений тел
            for (int i = 0; i < pCount; ++i) {
                for (int j = i + 1; j < pCount; ++j) {
                    changeVelocity(planets[i], planets[j]);
                    if (dockInd == 0) {
                        changeVelocity(planets[i], ship);
                    } else {
                        ship.setVel(planets[dockPlanet].getVel());
                    }
                }
            }

            ship.setCoord({ship.getCoord().getX() + ship.getVel().getX() * DT, ship.getCoord().getY() + ship.getVel().getY() * DT});
            for (int i = 0; i < pCount; ++i) {
                planets[i].setCoord({planets[i].getCoord().getX() + planets[i].getVel().getX() * DT,
                                     planets[i].getCoord().getY() + planets[i].getVel().getY() * DT});
            }

            sf::Int32 frameDuration = loopTimer.getElapsedTime().asMilliseconds();
            sf::Int32 timeToSleep = int(1000.f/wantFps) - frameDuration;
            if (timeToSleep > 0) {
                sf::sleep(sf::milliseconds(timeToSleep));
            }
            loopTimer.restart();
        }
    }
    return 0;
}
