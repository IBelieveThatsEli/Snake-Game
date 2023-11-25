#ifndef Engine_H
#define Engine_H

#include <string>
#include <string_view>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "Food.h"
#include "Menu.h"

class Engine
{
private:
    int m_width              = {}
    ,   m_height             = {};
    std::string m_windowName = {};
public:
    Engine(const int width, const int height, std::string_view windowName);
    ~Engine();
    void Run();
};

#endif
