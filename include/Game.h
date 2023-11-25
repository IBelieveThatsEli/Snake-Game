#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "Player.h"
#include "Food.h"

class Game
{
private:
    int m_rows     = {};
    int m_columns  = {};
    void processPlayerInput(Player::Direction &dir);
    void handlePlayerCollision(Player &player, Food &food);
    void drawGrid(sf::RenderWindow &window, Player &player, Food &food);
public:
    Game(const int rows, const int columns);
    ~Game();
    void updateLogic(Player::Direction &dir, Player &player, Food &food);
    void updateGraphics(sf::RenderWindow &window, Player &player, Food &food);
};

#endif
