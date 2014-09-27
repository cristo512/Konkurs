#include "gameState.h"

gameState::gameState()
{

}

gameState::~gameState()
{
    //dtor
}

bool gameState::onMouseOver(sf::Sprite &sprite)
{
    sf::FloatRect rect = sprite.getGlobalBounds();
    return rect.contains(mouse.getPosition().x,mouse.getPosition().y);
}

bool gameState::onMouseOver(sf::Text &text)
{
    sf::FloatRect rect = text.getGlobalBounds();
    return rect.contains(mouse.getPosition().x,mouse.getPosition().y);
}

bool gameState::onCollision(sf::Sprite &sprite1, sf::Sprite &sprite2)
{
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();
    return rect1.intersects(rect2);
}
