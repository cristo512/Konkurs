/*#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

enum EnumGameState
{
    Zajazd=0,
    Bliska=1,
    Przystanek=2,
    Boisko=3,
    Kosciol=4,
    Staw=5,
    Gmina=6,
    Dino=7,
    Przedszkole=8,
    Podstawowka=9,
    Dom=10,
    Krzyzowka=11,
    Gok=12,
    Orlik=13,
    Bank=14,
    Quit=15,
    Game=16,
    Menu=17
};


bool isRoad(sf::Image& bg,sf::Sprite& BG,int x, int y)
{
    int punkt=(y*BG.getGlobalBounds().width)+x;
    return !(bg.getPixelsPtr()[4*punkt+0]==0 && bg.getPixelsPtr()[4*punkt+1]==170 && bg.getPixelsPtr()[4*punkt+2]==0);
}
bool colision(sf::Sprite& a,sf::Sprite& b, int width1, int hieght1, int width2, int hieght2)
{
    sf::FloatRect Rect1 = a.getGlobalBounds();
    sf::FloatRect Rect2 = b.getGlobalBounds();
    Rect1.width = width1;
    Rect1.height = hieght1;
    Rect2.width = width2;
    Rect2.height = hieght2;
    return Rect1.intersects(Rect2);
}

int main()
{
    sf::Event event;
    int GameState=Menu;
    sf::RenderWindow window(sf::VideoMode(800,600), L"Lututów", sf::Style::Titlebar|sf::Style::Close);
    sf::Texture player_staying, background_texture, player_walk1, player_walk2, aparat_texture, Error, obraz_texture[15], Arrows_texture, F_texture, line_texture, leave_texture;
    sf::Image bg;
    if(!player_staying.loadFromFile("./data/player_staying.png"))
        return -1;
    if(!player_walk1.loadFromFile("./data/player_walk1.png"))
        return -3;
    if(!player_walk2.loadFromFile("./data/player_walk2.png"))
        return -4;
    if(!background_texture.loadFromFile("./data/mapa.png"))
        return -2;
    if(!aparat_texture.loadFromFile("./data/aparat.png"))
        return -5;
    if(!Error.loadFromFile("./data/obraz1.png"))
        return -6;
    if(!bg.loadFromFile("./data/mapa.png"))
        return -7;
    if(!obraz_texture[0].loadFromFile("./data/Zajazd.png"))
        return -8;
    if(!obraz_texture[1].loadFromFile("./data/Bliska.png"))
        return -9;
    if(!obraz_texture[2].loadFromFile("./data/Przystanek.png"))
        return -10;
    if(!obraz_texture[3].loadFromFile("./data/Boisko.png"))
        return -11;
    if(!obraz_texture[4].loadFromFile("./data/Kosciol.png"))
        return -12;
    if(!obraz_texture[5].loadFromFile("./data/Staw.png"))
        return -13;
    if(!obraz_texture[6].loadFromFile("./data/Gmina.png"))
        return -14;
    if(!obraz_texture[7].loadFromFile("./data/Dino.png"))
        return -15;
    if(!obraz_texture[8].loadFromFile("./data/Przedszkole.png"))
        return -16;
    if(!obraz_texture[9].loadFromFile("./data/Podstawowka.png"))
        return -17;
    if(!obraz_texture[10].loadFromFile("./data/Dom.png"))
        return -18;
    if(!obraz_texture[11].loadFromFile("./data/Krzyzowka.png"))
        return -19;
    if(!obraz_texture[12].loadFromFile("./data/Gok.png"))
        return -20;
    if(!obraz_texture[13].loadFromFile("./data/Orlik.png"))
        return -21;
    if(!Arrows_texture.loadFromFile("./data/strzalki.png"))
        return -22;
    if(!F_texture.loadFromFile("./data/F.png"))
        return -23;
    if(!line_texture.loadFromFile("./data/line.png"))
        return -24;
    if(!leave_texture.loadFromFile("./data/leave2.png"))
        return -25;
    if(!obraz_texture[14].loadFromFile("./data/Bank.png"))
        return -26;
    sf::Sprite player, background, F, Arrows, line, leave;
    sf::Sprite obraz1, obraz[15];
    sf::Sprite aparat[15];


    sf::Font czcionka, candara;
    if(!czcionka.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
        std::cout<<"Error nie ma czionki\n";
    if(!candara.loadFromFile("C:\\Windows\\Fonts\\candara.ttf"))
        std::cout<<"Error nie ma czionki candara\n";
    sf::Text see_picture, miejsce[15], tak, nie,wyjsc,powrot, autor, Lututow, sterowanie, F_text, tobegin;
    see_picture.setFont(czcionka);
    powrot.setFont(czcionka);
    tak.setFont(czcionka);
    nie.setFont(czcionka);
    wyjsc.setFont(czcionka);
    autor.setFont(czcionka);
    Lututow.setFont(candara);
    sterowanie.setFont(czcionka);
    F_text.setFont(czcionka);
    tobegin.setFont(candara);

    Lututow.setColor(sf::Color::Cyan);
    Lututow.setScale(1.3,1);

    see_picture.setString(L"Wciśnij F aby zobaczyć obrazek");
    powrot.setString(L"Wciśnij Esc aby powrócić");
    tak.setString("Tak");
    nie.setString("Nie");
    wyjsc.setString(L"Czy na pewno chcesz wyjść?");
    autor.setString(L"Autor: Krystian Jabłoński");
    Lututow.setString(L"Lututów");
    tobegin.setString(L"Aby zacząć\nwciśnij ENTER");
    sterowanie.setString("sterowanie");
    F_text.setString(L"Przejście do obrazka");
    sf::Image image;

    see_picture.setColor(sf::Color::Black);

    autor.setColor(sf::Color::Yellow);
    F_text.setColor(sf::Color::Blue);
    sterowanie.setColor(sf::Color::Blue);

    for(int i=0;i<15;i++)
    {
        aparat[i].setTexture(aparat_texture);
        obraz[i].setTexture(obraz_texture[i]);
        miejsce[i].setFont(czcionka);
    }
    miejsce[0].setString("Zajazd Lutold");
    miejsce[1].setString("Stacja paliw - Bliska");
    miejsce[2].setString("Przystanek autobusowy");
    miejsce[3].setString("Boisko");
    miejsce[4].setString(L"Kościół pw. św. Piotra i Pawła");
    miejsce[5].setString("Staw");
    miejsce[6].setString(L"Urząd Gminy");
    miejsce[7].setString("Sklep Dino");
    miejsce[8].setString("Przedszkole Publiczne");
    miejsce[9].setString(L"Szkoła Podstawowa im. Powstańców 1863r.");
    miejsce[10].setString("Dom autora");
    miejsce[11].setString(L"Skrzyżowanie dróg");
    miejsce[12].setString(L"Gminny Ośrodek Kultury");
    miejsce[13].setString("Orlik");
    miejsce[14].setString(L"Rejonowy Bank Spółdzielczy");

    for(int i=0;i<15;i++)
    {
        miejsce[i].setColor(sf::Color::Blue);
    }

    Lututow.setCharacterSize(110);
    tobegin.setCharacterSize(40);
    tobegin.setColor(sf::Color::Blue);

    player.setTexture(player_staying);
    obraz1.setTexture(Error);
    Arrows.setTexture(Arrows_texture);
    line.setTexture(line_texture);
    leave.setTexture(leave_texture);
    F.setTexture(F_texture);
    background.setTexture(background_texture);
    player.setPosition(30,95);
    background.setPosition(0,0);
    aparat[0].setPosition(893,301);
    aparat[1].setPosition(635,246);
    aparat[2].setPosition(602,965);
    aparat[3].setPosition(1121,438);
    aparat[4].setPosition(186,1316);
    aparat[5].setPosition(1430,1460);
    aparat[6].setPosition(1172,1181);
    aparat[7].setPosition(1025,1158);
    aparat[8].setPosition(312,588);
    aparat[9].setPosition(330,450);
    aparat[10].setPosition(2006,965);
    aparat[11].setPosition(1544,1103);
    aparat[12].setPosition(312-80,588+250);
    aparat[13].setPosition(848,525);
    aparat[14].setPosition(1025-90,1233);
    Arrows.setPosition(600,280);
    line.setPosition(580-F.getGlobalBounds().width/2,240+F_text.getGlobalBounds().height);
    F.setPosition(580-F.getGlobalBounds().width,330);
    autor.setPosition(450,550);
    F_text.setPosition(420,230);
    Lututow.setPosition((800-Lututow.getGlobalBounds().width)/2,0);
    sterowanie.setPosition(600,380);
    tobegin.setPosition(100,280);


    float time, time2;
    sf::Clock clock, clock2;
    sf::View view;
    view = window.getView();
    float przesuniecie_poziome=0;
    float przesuniecie_pionowe=0;
    int v=250;
    bool droga=true;
    bool exitt=false;
    window.setFramerateLimit(60);
    int punkt;
    while (window.isOpen())
    {
        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        switch(GameState)
        {
            case Menu:
            {
                window.clear();
                if(event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape)
                    GameState=Game;

                window.draw(F);
                window.draw(Arrows);
                window.draw(F_text);
                window.draw(line);
                window.draw(Lututow);
                window.draw(tobegin);
                window.draw(sterowanie);
                window.draw(autor);
                window.display();

                break;
            }

            case Quit:
            {
                window.clear();
                tak.setPosition(przesuniecie_poziome+200,przesuniecie_pionowe+300);
                nie.setPosition(przesuniecie_poziome+550,przesuniecie_pionowe+300);
                wyjsc.setPosition(przesuniecie_poziome+200,przesuniecie_pionowe+100);
                leave.setPosition(przesuniecie_poziome,przesuniecie_pionowe+600-leave.getGlobalBounds().height);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    exitt=true;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    exitt=false;

                if(exitt)
                {
                    tak.setColor(sf::Color::Green);
                    nie.setColor(sf::Color::White);
                }
                else
                {
                    nie.setColor(sf::Color::Green);
                    tak.setColor(sf::Color::White);
                }
                if(exitt&&sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    window.close();

                if(!exitt&&sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    GameState=Game;

                window.draw(leave);
                window.draw(tak);
                window.draw(nie);
                window.draw(wyjsc);
                window.display();
                break;
            }
            case Game:
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    time2 = clock2.getElapsedTime().asSeconds();
                    if(time2>0.3f)
                    {
                        if(player.getTexture()== &player_staying)
                            player.setTexture(player_walk1);
                        clock2.restart();
                        if(player.getTexture()== &player_walk2)
                            player.setTexture(player_walk1);
                        else
                            player.setTexture(player_walk2);
                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        if(player.getScale().x == 1)
                        {
                            player.setScale(-1.f , 1.f);
                            player.move(player.getGlobalBounds().width,0);
                        }
                        if(player.getPosition().x>player.getGlobalBounds().width)
                        {
                            player.move(-v*time,0);
                            for(int i=12; i<=38;i++)
                            {
                                if(!isRoad(bg, background,player.getPosition().x+(i*player.getScale().x),player.getPosition().y+71))
                                {
                                    player.move(v*time,0);
                                    break;
                                }
                            }

                        }
                        if(player.getPosition().x<120+przesuniecie_poziome)
                        {
                            if(przesuniecie_poziome>1)
                            {
                                view.move((v*time)*-1,0);
                                przesuniecie_poziome = przesuniecie_poziome -v*time;
                                window.setView(view);
                            }

                        }
                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        if(player.getScale().x == -1)
                        {
                            player.setScale(1.f , 1.f);
                            player.move(player.getGlobalBounds().width*-1,0);
                        }
                        if(player.getPosition().x<background.getGlobalBounds().width-player.getGlobalBounds().width)
                        {
                            player.move(v*time,0);
                            if(player.getPosition().x>=background.getGlobalBounds().width-player.getGlobalBounds().width)
                                player.setPosition( background.getGlobalBounds().width-player.getGlobalBounds().width-1 , player.getPosition().y);
                            for(int i=12; i<=38;i++)
                            {
                                if(!isRoad(bg, background,player.getPosition().x+(i*player.getScale().x),player.getPosition().y+71))
                                {
                                    player.move(-v*time,0);
                                    break;
                                }
                            }
                        }
                        if(player.getPosition().x>731+przesuniecie_poziome && player.getPosition().x<background.getGlobalBounds().width-player.getGlobalBounds().width&&przesuniecie_poziome<background.getGlobalBounds().width-800)
                        {
                            view.move(v*time,0);
                            przesuniecie_poziome = przesuniecie_poziome + v*time;
                            window.setView(view);
                        }

                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        if(player.getPosition().y<background.getGlobalBounds().height-player.getGlobalBounds().height)
                        {
                            player.move(0,v*time);
                            if(player.getPosition().y>=background.getGlobalBounds().height-player.getGlobalBounds().height)
                                player.setPosition(player.getPosition().x , background.getGlobalBounds().height-player.getGlobalBounds().height-1 );
                            for(int i=12; i<=38;i++)
                            {
                                if(!isRoad(bg, background,player.getPosition().x+(i*player.getScale().x),player.getPosition().y+71))
                                {
                                    player.move(0,-v*time);
                                    break;
                                }
                            }

                        }
                        if(player.getPosition().y>450+przesuniecie_pionowe && player.getPosition().y<background.getGlobalBounds().height-player.getGlobalBounds().height-21&&przesuniecie_pionowe<background.getGlobalBounds().height-600)
                        {
                            view.move(0, v*time);
                            przesuniecie_pionowe += v*time;
                            window.setView(view);
                        }
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        if(player.getPosition().y>0)
                        {
                            player.move(0,-v*time);
                            if(player.getPosition().y<=0)
                                player.setPosition(player.getPosition().x , 1);
                            for(int i=12; i<=38;i++)
                            {
                                if(!isRoad(bg, background,player.getPosition().x+(i*player.getScale().x),player.getPosition().y+71))
                                {
                                    player.move(0,v*time);
                                    break;
                                }
                            }
                        }
                        if(player.getPosition().y<30+przesuniecie_pionowe && przesuniecie_pionowe>2)
                        {
                            view.move(0, -v*time);
                            przesuniecie_pionowe += -v*time;
                            window.setView(view);
                        }
                    }
                }
                else
                {
                    player.setTexture(player_staying);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    GameState=Quit;
                }
                window.clear();
                window.draw(background);
                for(int i=0;i<15;i++)
                {
                    window.draw(aparat[i]);
                }
                window.draw(player);
                for(int i=0;i<15;i++)
                {
                    if(colision(player, aparat[i], player.getGlobalBounds().width, player.getGlobalBounds().height, aparat[i].getGlobalBounds().width, aparat[i].getGlobalBounds().height))
                    {
                        see_picture.setPosition(przesuniecie_poziome+(800-see_picture.getGlobalBounds().width)/2, 20+przesuniecie_pionowe);
                        miejsce[i].setPosition(przesuniecie_poziome+(800-miejsce[i].getGlobalBounds().width)/2, 520+przesuniecie_pionowe);
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                        {
                            GameState=i;
                        }
                        window.draw(see_picture);
                        window.draw(miejsce[i]);
                    }
                }
                window.display();
                break;
            }

            case Zajazd:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[0].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[0]);
                break;
            }
            case Bliska:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[1].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[1]);
                break;
            }
            case Przystanek:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[2].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[2]);
                break;
            }
            case Boisko:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[3].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[3]);
                break;
            }
            case Kosciol:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[4].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[4]);
                break;
            }
            case Staw:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[5].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[5]);
                break;
            }
            case Gmina:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[6].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[6]);
                break;
            }
            case Dino:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[7].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[7]);
                break;
            }
            case Przedszkole:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[8].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[8]);
                break;
            }
            case Podstawowka:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[9].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[9]);
                break;
            }
            case Dom:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[10].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[10]);
                break;
            }
            case Krzyzowka:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[11].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[11]);
                break;
            }
            case Gok:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[12].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[12]);
                break;
            }
            case Orlik:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[13].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[13]);
                break;
            }
            case Bank:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    GameState=Game;
                obraz[14].setPosition(przesuniecie_poziome,przesuniecie_pionowe);
                window.draw(obraz[14]);
                break;
            }
        }
        if(GameState!=Game&&GameState!=Menu&&GameState!=Quit)
        {
            powrot.setPosition(przesuniecie_poziome+240,przesuniecie_pionowe+550);
            window.draw(powrot);
            window.display();
        }
    }


    return 0;
}

