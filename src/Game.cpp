#include "Game.h"

Game::Game(const int rows, const int columns)
{
    m_rows = rows;
    m_columns = columns;
}

Game::~Game()
{

}

void Game::updateLogic(Player::Direction &dir, Player &player, Food &food)
{
    processPlayerInput(dir);
    player.updatePosition(dir);
    handlePlayerCollision(player, food);
}

void Game::updateGraphics(sf::RenderWindow &window, Player &player, Food &food)
{
    drawGrid(window, player, food);
}

void Game::processPlayerInput(Player::Direction &dir)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        dir = Player::UP;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        dir = Player::DOWN;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        dir = Player::LEFT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        dir = Player::RIGHT;
    }
}

void Game::handlePlayerCollision(Player &player, Food &food)
{
    if (player.getPosition()[0][0] == food.getPosition()[0][0]
        && player.getPosition()[0][1] == food.getPosition()[0][1])
    {
        player.Eat();
        food.spawnInNewLocation(1, m_rows, player);
    }   
}

void Game::drawGrid(sf::RenderWindow &window, Player &player, Food &food)
{    
    constexpr int squareSize = 50, gapSize = 5;
    bool hasSnake{};

    for (int row{}; row < m_rows; ++row)
    {
        for (int col{}; col < m_columns; ++col)
        {
            hasSnake = false;
            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
            square.setPosition(row * (squareSize + gapSize), col * (squareSize + gapSize));
            if (player.getPosition()[0][0] == row && player.getPosition()[0][1] == col)
            {            
                square.setFillColor(sf::Color::Green);
            }
            else
            {
                if (food.getPosition()[0][0] == row && food.getPosition()[0][1] == col)
                    square.setFillColor(sf::Color::Yellow);
                else
                {
                    for (std::size_t index{}; index < std::size(player.getPosition()); ++index)
                    {
                        if (player.getPosition()[index][0] == row && player.getPosition()[index][1] == col)
                        {
                            hasSnake = true;
                        }
                    }
                    if (!hasSnake)
                        square.setFillColor(sf::Color(5, 59, 80));
                }
            }
            window.draw(square);
        }
    }
}

