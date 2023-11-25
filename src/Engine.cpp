#include "Engine.h"

Engine::Engine(const int width, const int height, std::string_view windowName)
{
    m_width = width;
    m_height = height;
    m_windowName = windowName;
}

Engine::~Engine()
{
    
}

void Engine::Run()
{
    sf::RenderWindow window(sf::VideoMode(m_width, m_height), m_windowName);
    
    sf::Time timePerFrame { sf::seconds(5.0f / 60.0f) };
    
    sf::Clock clock;
    sf::Time timeSinceLastUpdate { sf::Time::Zero };
    
    Game game(17, 17);
    Menu menu;
    Player player;
    Food food;

    // by default player moving right
    Player::Direction player_dir{player.RIGHT};

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Time elapsedTime { clock.restart() };
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate >= timePerFrame)
        {
            // if menu is open then the game should pause
            if(menu.isOpen())
            {
                menu.processInput(window);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    menu.setMenuStatus(false);
            }
            else
            {
                game.updateLogic(player_dir, player, food);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    menu.setMenuStatus(true);
            }
            timeSinceLastUpdate -= timePerFrame;
        }

        window.clear();
        // display the menu if it is open
        if(menu.isOpen())
            menu.display(window);
        else
            game.updateGraphics(window, player, food);
        window.display();
    }
}

