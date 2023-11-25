#include "Food.h"

Food::Food()
{
    m_position[0][0] = 9;
    m_position[0][1] = 8;
}

Food::~Food()
{
    
}

std::array<std::array<int, 2>, 1> Food::getPosition()
{
    return m_position;
}

int Food::randomizeLocation(const int &min, const int &max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max - 1);
    return dist(gen);
}

void Food::spawnInNewLocation(const int &min, const int &max, Player &player)
{
    int x{}
    ,   y{};
    do
    {
        x = randomizeLocation(min, max);
        y = randomizeLocation(min, max);
    } while (x == player.getPosition()[0][0] && y == player.getPosition()[0][1]);

    m_position[0][0] = x;
    m_position[0][1] = y;
}
