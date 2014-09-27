#include "Ball.h"

Ball::Ball()
{
    //ctor
}

Ball::~Ball()
{
    //dtor
}

void Ball::setTexture(sf::Texture &texture)
{
    sprite.setTexture(texture);
}
