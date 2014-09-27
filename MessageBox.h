#pragma once
#include <iostream>
#include <string>
#include "SFML\Graphics.hpp"

class MessageBox
{
protected:
	sf::RectangleShape square;
	sf::Text ok, *message;
	sf::Event event;
	int lines;
	std::string line;
	sf::Font font;
	void checkEvent(sf::Event event);
	sf::RenderWindow &mwindow;

public:
	MessageBox(std::string str, sf::RenderWindow &window);
	~MessageBox(void);
	void draw();
	bool isOpen;
};

