#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <string_view>
#include <string>
#include <array>

class Menu
{
private:
    std::array<std::string_view, 5> m_menuOptions {"play", "something", "Some....thing", "....", "close"};
    int m_currentSelection{};
    bool m_isOpen{};
    void drawMenuOptions(sf::RenderWindow &window);
public:
    void display(sf::RenderWindow &window);
    void processInput(sf::RenderWindow &window);
    void setMenuStatus(bool status);
    bool isOpen();
};

#endif
