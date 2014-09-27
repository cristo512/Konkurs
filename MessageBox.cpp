#include "MessageBox.h"


MessageBox::MessageBox(std::string str, sf::RenderWindow &window):
	mwindow(window)
{
	if(!font.loadFromFile("C:\\Windows\\Fonts\\MTCORSVA.ttf"))
		std::cout<<"problem";
	lines=1;
	for(unsigned int i=0;i<str.length();i++)
	{
		if(str[i]=='\n')
			lines++;
	}
	message = new sf::Text [lines];
	line.clear();

	for(unsigned int i=0,j=0;i<str.length();i++)
	{
		
		if( (str[i]=='\n') || (i==str.length()-1 && message[j].getString().isEmpty()))
		{
			if(i==str.length()-1)
				line += str[i];
			message[j].setString(line);
			message[j].setFont(font);
			j++;
			line.clear();
			continue;
		}
		line += str[i];

	}
	float przesuniecie_poziome = 0;
	std::cout<<mwindow.getView().getCenter().x <<"   x   "<<mwindow.getView().getCenter().y<<std::endl;
	float theWidest = message[0].getGlobalBounds().width;
	for(int i=0;i<lines;i++)
	{
		if(message[i].getGlobalBounds().width > theWidest)
			theWidest = message[i].getGlobalBounds().width;
	}

	float scale;
	if(mwindow.getSize().x / 1920.f <= mwindow.getSize().y / 1080.f)
		scale = mwindow.getSize().x / 1920.f ;
	else 
		scale = mwindow.getSize().y / 1080.f ;
	square.setSize(sf::Vector2f(theWidest + 40,(lines*message[0].getGlobalBounds().height) + (lines * 10) + 40));
	float text_y = (mwindow.getSize().y - square.getGlobalBounds().height) / 2;
	square.setPosition( (mwindow.getSize().x - square.getGlobalBounds().width) / 2, (mwindow.getSize().y - square.getGlobalBounds().height) / 2);
	for(int i=0;i<lines;i++)
    {
		message[i].setPosition((mwindow.getSize().x-message[i].getGlobalBounds().width)/2, text_y + 20 + i * (message[0].getGlobalBounds().height+10));
    }
	square.setFillColor(sf::Color::Blue);
}

void MessageBox::checkEvent(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
    {
		if(event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
        {
			isOpen = !isOpen;
        }
	}

}

void MessageBox::draw()
{
	mwindow.draw(square);
	while(mwindow.pollEvent(event))
	{
		checkEvent(event);
	}
	for(int i=0;i<lines;i++)
		mwindow.draw(message[i]);
}



MessageBox::~MessageBox(void)
{
}
