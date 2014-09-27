#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

class gameState
{
public:
    gameState();
    ~gameState();
	virtual void checkEvent(sf::Event event) = 0;
	virtual void draw() = 0;
	sf::Vector2f viewPosition;
	virtual bool onMouseOver(sf::Sprite &sprite);
	virtual bool onMouseOver(sf::Text &text);
	virtual bool onCollision(sf::Sprite &sprite1, sf::Sprite &sprite2);
    sf::Mouse mouse;
    virtual void checkActions() = 0;
};

#endif // GAMESTATE_H
