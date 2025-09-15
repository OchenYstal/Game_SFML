#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!", sf::Style::Titlebar);
    window.setFramerateLimit(240);

    Player player;
    Enemy enemy;
   
    enemy.Initialize();
    player.Initialize();

    player.Load();
    enemy.Load();

    sf::Clock clock;

    while (window.isOpen())
    {
    sf::Time DeltaTimeTimer = clock.restart(); 
    float DeltaTime = DeltaTimeTimer.asMilliseconds(); 
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
        player.Draw(window);
        enemy.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}