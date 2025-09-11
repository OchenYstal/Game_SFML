#include <SFML/Graphics.hpp>
#include <math.h>

#include "Player.hpp"
#include "Enemy.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!", sf::Style::Titlebar);

    int XIndex = 1;
    int YIndex = 0;
    //enemy index
    int xIndex = 1;
    int yIndex = 2;
    
    Player player;
    Enemy enemy;
   
    enemy.sprite.setPosition(sf::Vector2f({200, 300}));
    player.Initialize();

    player.Load();
    player.sprite.setScale({2.f, 2.f});
    player.sprite.scale({0.8f, 0.8f});
    player.sprite.setTextureRect(sf::IntRect({XIndex * 64, YIndex * 64}, {64, 64}));
    enemy.Load();
    enemy.sprite.setScale({2.f, 2.f});
    enemy.sprite.scale({0.8f, 0.8f});
    enemy.sprite.setTextureRect(sf::IntRect({xIndex * 50, yIndex * 64}, {50, 64}));


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