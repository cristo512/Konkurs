#include "Player.h"

Player::Player()
{
    velocity.x = 20;
}

Player::~Player()
{
    //dtor
}

void Player::setTexture(sf::Texture &texture)
{
    sprite.setTexture(texture);
}

void Player::move(int x, int y)
{
    sprite.move(velocity.x * x * globalGame->delta, velocity.y * y * globalGame->delta);
    if ( sprite.getPosition().x < 0)
        sprite.setPosition(0, sprite.getPosition().y);
    if ( sprite.getPosition().x > globalGame->window.getSize().x)
        sprite.setPosition(globalGame->window.getSize().x, sprite.getPosition().y);
}

