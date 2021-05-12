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

        for (int i = 0; i < pCount; ++i) {
            //Читаю из файла
            file >> planets[i];
        }
        file >> ship;
        bool isViewMove = false;
        bool viewFlag = true;
        sf::Vector2f mousePos;

        float wantFps = 60;

        sf::Clock loopTimer;
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
                } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) {
                    viewFlag = !viewFlag;
                }      
            }

            //двигатели
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

            //Упраление камерой
            if (isViewMove) {
                windowView.move(mousePos - window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView));
                mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
            }

            if (viewFlag) {
                windowView.setCenter(ship.getCoord().getX(), ship.getCoord().getY());
            }
            //Отрисовка окна
            window.clear(sf::Color(0x0e, 0x0e, 0x57));

            for (int i = 0; i < pCount; ++i) {
                window.draw(planets[i].getCircle());
            }
            window.draw(ship.getShape());

            window.setView(windowView);
            window.display();

            //Измеение положений тел
            for (int i = 0; i < pCount; ++i) {
                for (int j = i + 1; j < pCount; ++j) {
                    changeVelocity(planets[i], planets[j]);
                    changeVelocity(planets[i], ship);
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
