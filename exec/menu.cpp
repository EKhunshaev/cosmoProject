#include "../headers/header.h"

void createText(sf::Text &text, const std::string &str, const sf::Font &font, const sf::Vector2f &position) {
    text.setFont(font);
    text.setString(str);
    text.setFillColor(sf::Color(0xe5, 0xb5, 0x25));
    text.setOutlineThickness(1);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2, bounds.height/2);
    text.setPosition(position.x, position.y);
}

bool mainMenu(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("textures/starjedi.ttf");

    sf::Text startGame;
    createText(startGame, "start game", font, window.mapPixelToCoords(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2 - 100)));
    sf::Text about;
    createText(about, "about", font, window.mapPixelToCoords(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2)));
    sf::Text aboutContent;
    createText(aboutContent, "The game is created by:\n"
                             "Michael vasiliev\n"
                             "valentine Timoshkin\n"
                             "Elveg Khunshaev", font, window.mapPixelToCoords(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2)));
    sf::Text exit;
    createText(exit, "exit", font, window.mapPixelToCoords(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2 + 100)));

    sf::Clock timer;
    float time = 0;
    menuType menu = MENU_MAIN;
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        int mItemId = 0;
        if (menu == MENU_MAIN) {
            startGame.setFillColor(sf::Color(0xe5, 0xb5, 0x25));
            startGame.setOutlineColor(sf::Color::Transparent);
            about.setFillColor(sf::Color(0xe5, 0xb5, 0x25));
            about.setOutlineColor(sf::Color::Transparent);
            exit.setFillColor(sf::Color(0xe5, 0xb5, 0x25));
            exit.setOutlineColor(sf::Color::Transparent);

            if (sf::IntRect(startGame.getGlobalBounds()).contains(sf::Vector2i(window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView())))) {
                startGame.setFillColor(sf::Color::Transparent);
                startGame.setOutlineColor(sf::Color(0xe5, 0xb5, 0x25));
                mItemId = 1;
            } else if (sf::IntRect(about.getGlobalBounds()).contains(sf::Vector2i(window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView())))) {
                about.setFillColor(sf::Color::Transparent);
                about.setOutlineColor(sf::Color(0xe5, 0xb5, 0x25));
                mItemId = 2;
            } else if (sf::IntRect(exit.getGlobalBounds()).contains(sf::Vector2i(window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView())))) {
                exit.setFillColor(sf::Color::Transparent);
                exit.setOutlineColor(sf::Color(0xe5, 0xb5, 0x25));
                mItemId = 3;
            } else {
                mItemId = 0;
            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                switch (mItemId) {
                    case 1:
                        return false;
                    case 2:
                        menu = MENU_ABOUT;
                        break;
                    case 3:
                        window.close();
                        return false;
                }
            }
            //Отрисовка
            window.draw(startGame);
            window.draw(about);
            window.draw(exit);

            //window.draw(aboutContent);
        } else if (menu == MENU_ABOUT) {
            exit.setFillColor(sf::Color(0xe5, 0xb5, 0x25));
            exit.setOutlineColor(sf::Color::Transparent);
            exit.setPosition(window.mapPixelToCoords(sf::Vector2i(window.getSize().x / 2, window.getSize().y - 100)));

            if (sf::IntRect(exit.getGlobalBounds()).contains(sf::Vector2i(window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView())))) {
                exit.setOutlineColor(sf::Color(0xe5, 0xb5, 0x25));
                exit.setFillColor(sf::Color::Transparent);
                mItemId = 1;
            } else {
                mItemId = 0;
            }

            window.draw(aboutContent);
            window.draw(exit);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mItemId == 1) {
                menu = MENU_MAIN;
                exit.setPosition(window.mapPixelToCoords(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2 + 100)));
            }
        }
        window.display();

        //Таймер
        time = 1000 / 60 - timer.getElapsedTime().asMilliseconds();
        if (time > 0) {
            sf::sleep(sf::milliseconds(time));
        }
        timer.restart();
    }


    return true;
}