#include "Menu.h"

void Menu::display(sf::RenderWindow &window)
{
    drawMenuOptions(window);
}

void Menu::drawMenuOptions(sf::RenderWindow &window)
{
    sf::Text option;
    sf::Font lm_font;
    lm_font.loadFromFile("./lib/LemonMilk/LEMONMILK-Medium.otf");
    option.setFont(lm_font);
    for (std::size_t index{}; index < std::size(m_menuOptions); ++index)
    {
        option.setString(static_cast<std::string>(m_menuOptions[index]));
        if(static_cast<int>(index) == m_currentSelection)
        {
            option.setFillColor(sf::Color::Yellow);
            option.setCharacterSize(35);
        }
        else
        {
            option.setFillColor(sf::Color::White);
            option.setCharacterSize(30);
        }
        option.setPosition(50.0f, (index + 1) * 50.0f);
        window.draw(option);
    }
}

void Menu::processInput(sf::RenderWindow &window)
{
    if (m_currentSelection == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        m_isOpen = false;
    if (m_currentSelection == 4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        window.close();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        if(m_currentSelection != 0)
            --m_currentSelection;            
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        if(m_currentSelection != 4)
            ++m_currentSelection;
}

void Menu::setMenuStatus(bool status)
{
    m_isOpen = status;
}

bool Menu::isOpen()
{
    return m_isOpen;
}
