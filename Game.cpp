#include "Game.h"

Game* globalGame;

float Game::scale(float x)
{
	return x * scaling_variable;
}

float Game::average(float x, float y)
{
    return (x - y) / 2.f;
}

Game::Game()
{
    sf::VideoMode videoMode;
    videoMode.getFullscreenModes();
    window.create(sf::VideoMode::getDesktopMode(), "Gra", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    setScale_Variable();
    globalGame = this;
    clock.restart();

    State = new Volleyball;
}

void Game::setScale_Variable()
{
	if(window.getSize().x / 1920.f <= window.getSize().y / 1080.f)
        scaling_variable = window.getSize().x / 1920.f;
    else
        scaling_variable = window.getSize().y / 1080.f;
}

Game::~Game()
{
    //dtor
}

void Game::Run()
{
    while(window.isOpen())
    {
        do{
            delta = clock.getElapsedTime().asSeconds();
        }while(delta < 0.018f);
        if(delta > 0.018f)
            delta = 0.018f;
        clock.restart();
        State->draw();
        while(window.pollEvent(event))
            State->checkEvent(event);
        State->checkActions();
    }
}
