#include "../headers/header.h"

int main() {
// Задание координат точек
    Point P1(600, 600);
    Point P2 (400, 300);
    Point P3 (400, 400);
//Задание скоростей точек
    Velocity V1(0, 0);
    Velocity V2(5, 0);
    Velocity V3(-5, 0);
    Velocity V4(0, 0);
//Задание тел
    Ship S(1, P1, V1);
    Planet Pl1(100, P2, 30, V2);
    Planet Pl2(500, P3, 30, V3);
//чисто дебаг сил
    Force F = force(Pl1, Pl2);
    Force FS = force(Pl1, S);
    std::cout <<F <<"\n";
    std::cout <<FS <<"\n";

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    //Главный цикл приложения который выпоняется пока открыто окно
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
//Кусок кода для будущего
//        if (event.type == sf::Event::KeyPressed) {           
//            if (event.key.code == sf::Keyboard::Left) {
//                dx = -1;
//            }
//            if (event.key.code == sf::Keyboard::Right) { 
//                dx = 1;
//            } 
//            if (event.key.code == sf::Keyboard::Down) { 
//                dy = -1;
//            }
//            if (event.key.code == sf::Keyboard::Up) { 
//                dy = 1;
//            }
//        }

//управление кораблём
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
            V4.setX(S.getVel().getX() - 0.1);
            V4.setY(S.getVel().getY());
            S.setVel(V4);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
            V4.setX(S.getVel().getX() + 0.1);
            V4.setY(S.getVel().getY());
            S.setVel(V4);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
            V4.setX(S.getVel().getX());
            V4.setY(S.getVel().getY() - 0.1);
            S.setVel(V4);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            V4.setX(S.getVel().getX());
            V4.setY(S.getVel().getY() + 0.1);
            S.setVel(V4);
        }

        window.clear(sf::Color(0x0e, 0x0e, 0x57));
        window.draw(S.getShape());
        window.draw(Pl1.getShape());
        window.draw(Pl2.getShape());
        window.display();
//Задание взаимодействий
        changeVelocity(Pl1, Pl2);
        changeVelocity(Pl1, S);       
        changeVelocity(Pl2, S);  

        Pl1.getShape().move(Pl1.getVel().getX() * DT, Pl1.getVel().getY() * DT);
        Pl1.setCoord({Pl1.getCoord().getX() + Pl1.getVel().getX() * DT, Pl1.getCoord().getY() + Pl1.getVel().getY() * DT});
        Pl2.getShape().move(Pl2.getVel().getX() * DT, Pl2.getVel().getY() * DT);
        Pl2.setCoord({Pl2.getCoord().getX() + Pl2.getVel().getX() * DT, Pl2.getCoord().getY() + Pl2.getVel().getY() * DT});
        S.getShape().move(S.getVel().getX() * DT, S.getVel().getY() * DT);
        S.setCoord({S.getCoord().getX() + S.getVel().getX() * DT, S.getCoord().getY() + S.getVel().getY() * DT});
    }


    return 0;
}

