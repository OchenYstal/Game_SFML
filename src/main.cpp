#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <string>

#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!", sf::Style::Titlebar);
    window.setFramerateLimit(60);

    Player player;
    Enemy enemy;
   
    enemy.Initialize();
    player.Initialize();

    player.Load();
    enemy.Load();

    sf::Font font;
    if(!font.openFromFile("assets/Fonts/Font1FPS.ttf"))
    {
        std::cout << "Fail" << std::endl;   
    }
    sf::Text FrameRateText(font);
    FrameRateText.setCharacterSize(18);
    sf::Clock clock;

    while (window.isOpen())
    {
    sf::Time DeltaTimeTimer = clock.restart(); 
    float DeltaTime = DeltaTimeTimer.asMilliseconds(); 
    float Result = 1000 / DeltaTime;

    std::string frameRateText = "FPS: "  + std::to_string((int)Result) + " FrameTime: " + std::to_string((int)DeltaTime);
    FrameRateText.setString(frameRateText);

        //-------------- UPDATE ------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
    }
    
    enemy.Update(DeltaTime);   
    player.Update(DeltaTime,enemy);

//-------------- UPDATE ------------
//-------------- DRAW ------------
        window.clear(); 
        window.draw(FrameRateText);
        player.Draw(window);
        enemy.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}