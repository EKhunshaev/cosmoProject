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


            if (isViewMove) {
                windowView.move(mousePos - window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView));
                mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
            }
            //Отрисовка окна
            window.clear(sf::Color(0x0e, 0x0e, 0x57));

            //отрисовка текстуры
//            sf::Texture texture;
//            texture.loadFromFile("/home/mikle/miki3/project/cosmoProject/texture/Sun.png");
//            sf::Sprite sprite(texture);
//            sprite.setPosition(ship.getCoord().getX(), ship.getCoord().getY());
//            window.draw(sprite);

            sf::CircleShape shape(planets[0].getRad());
            sf::Texture texture;
            texture.loadFromFile("/home/mikle/miki3/project/cosmoProject/texture/Sun(1).png");
            shape.setTexture(&texture, false);
            shape.setTextureRect(sf::IntRect(1280, 720, 720, 720));    
            shape.setPosition(planets[0].getCoord().getX() - planets[0].getRad(), planets[0].getCoord().getY() - planets[0].getRad());
            window.draw(shape);

            sf::CircleShape shape1(planets[1].getRad());
            sf::Texture texture1;
            texture1.loadFromFile("/home/mikle/miki3/project/cosmoProject/texture/Sun.png");
            shape1.setTexture(&texture1, false);
            shape1.setTextureRect(sf::IntRect(50, 50, 100, 100));    
            shape1.setPosition(planets[1].getCoord().getX() - planets[1].getRad(), planets[1].getCoord().getY() - planets[1].getRad());
            window.draw(shape1);
            //end of it

//            for (int i = 0; i < pCount; ++i) {
//                window.draw(planets[i].getCircle());
//            }
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
        }
    }
    return 0;
}
