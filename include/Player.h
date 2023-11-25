#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player
{
private:
    int m_rows{1};
    const int m_columns{2};
    std::vector<std::vector<int>> m_position;
    void resizeArray();
public:
    enum Direction{
        UP, DOWN, LEFT, RIGHT
    };
    Player();
    ~Player();
    std::vector<std::vector<int>> getPosition();
    void Eat();
    void updatePosition(const Direction &dir);
    void resetPosition();
};

#endif
