#include "Menu.h"
#include "Game.h"
Menu::Menu()
{
    viewPosition.x = 0;
    viewPosition.y = 0;

    textAmount = 2;
    text = new sf::Text [textAmount];
    text[0].setString("Rozpocznij");
    text[1].setString("Exit");
    font.loadFromFile("C:\\Windows\\Fonts\\MTCORSVA.ttf");
    for(int i = 0; i < textAmount; i++)
    {
        text[i].setFont(font);
        text[i].setColor(sf::Color::White);
        text[i].setCharacterSize(120);
        text[i].setScale(globalGame->scale(1.f), globalGame->scale(1.f));
    }

    textSpace = globalGame->scale(100.f);
    textHeight = textAmount * text[0].getGlobalBounds().height + (textAmount - 1) * textSpace;
    textY = globalGame->average(globalGame->window.getSize().y, textHeight);

    for(int i = 0; i < textAmount; i++)
    {
        text[i].setPosition(globalGame->average(globalGame->window.getSize().x, text[i].getGlobalBounds().width),
                            textY + i * (text[0].getGlobalBounds().height + textSpace));
    }
}

Menu::~Menu()
{
    //dtor
}

void Menu::checkEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        globalGame->window.close();
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
            globalGame->window.close();
    }
}

void Menu::draw()
{
    globalGame->window.clear();
    for(int i = 0; i < textAmount ; i++)
        globalGame->window.draw(text[i]);
    globalGame->window.display();
}

void Menu::checkActions()
{
    for(int i = 0; i < textAmount; i++)
    {
        if(onMouseOver(text[i]))
        {
            text[i].setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(i == 0)
                {
                    delete globalGame->State;
                    globalGame->State = new Volleyball;
                }
                else if(i == 1)
                    globalGame->window.close();
            }
        }
        else
            text[i].setColor(sf::Color::White);

    }
}
