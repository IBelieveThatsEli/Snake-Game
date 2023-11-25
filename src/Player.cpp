#include "Player.h"

Player::Player()
{
    resetPosition();
}

Player::~Player()
{

}

std::vector<std::vector<int>> Player::getPosition()
{
    return m_position;
}

void Player::Eat()
{
    ++m_rows;
    resizeArray();
    // make tail position equal to the position of the prevouis tail
    m_position[m_rows - 1][0] = m_position[m_rows - 2][0];
    m_position[m_rows - 1][1] = m_position[m_rows - 2][1];
}

void Player::updatePosition(const Direction &dir)
{
    if(m_rows > 1)
    {
        for (int r{m_rows - 1}; r > 0; --r)
        {
            if(r + 1 <= m_rows)
            {
                m_position[r][0] = m_position[r - 1][0];
                m_position[r][1] = m_position[r - 1][1];
            }
        }
    }

    switch (dir)
    {
        case DOWN:
            ++m_position[0][1];
        break;
        case UP:
            --m_position[0][1];
        break;
        case LEFT:
            --m_position[0][0];
        break;
        case RIGHT:
            ++m_position[0][0];
        break;
    }
}

void Player::resetPosition()
{
    m_rows = 1;
    resizeArray();
    m_position[m_rows - 1][0] = {3}; //represents x cords
    m_position[m_rows - 1][1] = {8}; //represents y cords
}

void Player::resizeArray()
{
    m_position.resize(m_rows, std::vector<int>(m_columns));
}


