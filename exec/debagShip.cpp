#include "../headers/header.h"

int main() {
    int dx = 0;
    int dy = 0;
    Force Fx (50, 0);
    Force Fy (0, 50);

    Point P1(600, 600);
    Point P2 (400, 300);
    Point P3 (400, 400);

    Velocity V1(0, -5);
    Velocity V2(5, 0);
    Velocity V3(-5, 0);

    Ship S(1, P1, V1);
    Planet Pl1(100, P2, 30, V2);
    Planet Pl2(500, P3, 30, V3);

    Force F = force(Pl1, Pl2);
    Force FS = force(Pl1, S);
    std::cout <<F <<"\n";
    std::cout <<FS <<"\n";

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    //Главный цикл приложения который выпоняется пока открыто окно
    while (window.isOpen()) {
        dx = 0;
        dy = 0;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            
            if (event.key.code == sf::Keyboard::Left) {
                dx = -1;
            }
            if (event.key.code == sf::Keyboard::Right) { 
                dx = 1;
            } 
            if (event.key.code == sf::Keyboard::Down) { 
                dy = -1;
            }
            if (event.key.code == sf::Keyboard::Up) { 
                dy = 1;
            }
        }

        Fx = Fx * dx;
        Fy = Fy * dy;

        window.clear(sf::Color(0x0e, 0x0e, 0x57));
        window.draw(S.getShape());
        window.draw(Pl1.getShape());
        window.draw(Pl2.getShape());
        window.display();

        changeVelocity(Pl1, Pl2);
        changeVelocity(Pl1, S);       
        changeVelocity(Pl2, S); 
        changeVelocity(Fx, S);        
        changeVelocity(Fy, S);        

        Pl1.getShape().move(Pl1.getVel().getX() * DT, Pl1.getVel().getY() * DT);
        Pl1.setCoord({Pl1.getCoord().getX() + Pl1.getVel().getX() * DT, Pl1.getCoord().getY() + Pl1.getVel().getY() * DT});
        Pl2.getShape().move(Pl2.getVel().getX() * DT, Pl2.getVel().getY() * DT);
        Pl2.setCoord({Pl2.getCoord().getX() + Pl2.getVel().getX() * DT, Pl2.getCoord().getY() + Pl2.getVel().getY() * DT});
        S.getShape().move(S.getVel().getX() * DT, S.getVel().getY() * DT);
        S.setCoord({S.getCoord().getX() + S.getVel().getX() * DT, S.getCoord().getY() + S.getVel().getY() * DT});
    }


    return 0;
}

