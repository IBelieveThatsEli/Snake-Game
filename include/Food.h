#ifndef FOOD_H
#define FOOD_H

#include <array>
#include <random>
#include "Player.h"

class Food
{
private:
    std::array<std::array<int, 2>, 1> m_position;
    int randomizeLocation(const int &min, const int &max);
public:
    Food();
    ~Food();
    std::array<std::array<int, 2>, 1> getPosition();
    void spawnInNewLocation(const int &min, const int &max, Player &player);
};

#endif
