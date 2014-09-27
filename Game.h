#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "gameState.h"
#include "Menu.h"
#include "Volleyball.h"

class Game
{
public:
    Game();
    ~Game();
	void Run();
	sf::Event event;
    sf::RenderWindow window;
	float scaling_variable;
	float scale(float x);
	float average(float x, float y);
	gameState *State;
	float delta;
	sf::Clock clock;
protected:
    void setScale_Variable();
};

extern Game* globalGame;

#endif // GAME_H
