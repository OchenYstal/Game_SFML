#include <SFML/Graphics.hpp>
#include <math.h>

#include "Player.hpp"
#include "Enemy.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!", sf::Style::Titlebar);

    Player player;
    Enemy enemy;
   
    enemy.sprite.setPosition(sf::Vector2f({200, 300}));
    enemy.Initialize();
    player.Initialize();

    player.Load();
    
   
    enemy.Load();
    

    while (window.isOpen())
    {
        //-------------- UPDATE ------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
    }
    enemy.Update();   
    player.Update(enemy);
                          
//-------------- UPDATE ------------
//-------------- DRAW ------------
        window.clear(); 
        player.Draw(window);
        enemy.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}