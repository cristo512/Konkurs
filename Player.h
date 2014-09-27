#ifndef PLAYER_H
#define PLAYER_H
class Player;

#include <SFML/Graphics.hpp>
#include "Game.h"

class Player
{
public:
    Player();
    virtual ~Player();
    void setTexture(sf::Texture &texture);
    sf::Vector2f velocity;
    sf::Sprite sprite;
    std::string name;
    void move(int x, int y);
};

#endif // PLAYER_H
