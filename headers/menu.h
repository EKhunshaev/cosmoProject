#ifndef MENU_H
#define MENU_H

#define MENU_MAIN 0
#define MENU_ABOUT 1
typedef int menuType;

void createText(sf::Text &text, const std::string &str, const sf::Font &font);

bool mainMenu(sf::RenderWindow &window);



#endif //MENU_H
