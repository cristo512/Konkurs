#include "Volleyball.h"

void Volleyball::addPlayers()
{
    playersAmount = 2;
    player = new Player [playersAmount];
    for (int i = 0; i < playersAmount ; i++)
    {
        player[i].velocity = sf::Vector2f(500.f, 20.f);
        player[i].setTexture(playerStay);
    }
    player[0].sprite.setPosition(globalGame->window.getSize().x / 5, globalGame->window.getSize().y - player[0].sprite.getGlobalBounds().height);
    player[1].sprite.setScale(-1, 1);
    player[1].sprite.setPosition((4 * globalGame->window.getSize().x) / 5, globalGame->window.getSize().y - player[1].sprite.getGlobalBounds().height);
}
void Volleyball::addBalls()
{
    ballsAmount = 1;
    ball = new Ball [ballsAmount];

    for (int i = 0; i < playersAmount ; i++)
    {
        ball[i].setTexture(ballTexture);
    }
    ball[0].sprite.setPosition(globalGame->average(globalGame->window.getSize().x,
                                ball[0].sprite.getGlobalBounds().width),globalGame->window.getSize().y / 10);
}

Volleyball::Volleyball()
{
    playerStay.loadFromFile("./data/Player.png");
    ballTexture.loadFromFile("./data/Ball.png");
    bgTexture.loadFromFile("./data/Background.png");
    netTexture.loadFromFile("./data/Net.png");
    Net.setTexture(netTexture);
    background.setTexture(bgTexture);
    Net.setPosition(globalGame->average(globalGame->window.getSize().x, Net.getGlobalBounds().width),
                    globalGame->window.getSize().y - Net.getGlobalBounds().height);
    addPlayers();
    addBalls();

}

Volleyball::~Volleyball()
{
    //dtor
}

void Volleyball::checkEvent(sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            delete globalGame->State;
            globalGame->State = new Menu;
        }
        if(event.key.code == sf::Keyboard::F)
            globalGame->window.setFramerateLimit(20);
        if(event.key.code == sf::Keyboard::X)
            std::cout<<globalGame->delta<<std::endl;
    }
}
void Volleyball::draw()
{
    globalGame->window.clear();
    globalGame->window.draw(background.sprite);
    globalGame->window.draw(player[0].sprite);
    globalGame->window.draw(player[1].sprite);
    globalGame->window.draw(ball[0].sprite);
    globalGame->window.draw(Net);
    globalGame->window.display();
}
void Volleyball::checkActions()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player[0].move(-1, 0);
        if(onCollision(player[0].sprite, Net))
            player[0].move(1, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player[0].move(1, 0);
        if(onCollision(player[0].sprite, Net))
            player[0].move(-1, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player[1].move(-1, 0);
        if(onCollision(player[1].sprite, Net))
            player[1].sprite.setPosition(Net.getPosition().x + Net.getGlobalBounds().width + player[1].sprite.getGlobalBounds().width, player[1].sprite.getPosition().y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player[1].move(1, 0);
        if(onCollision(player[1].sprite, Net))
            player[1].move(-1, 0);
    }
}
