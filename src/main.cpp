#include <SFML/Graphics.hpp>
#include <math.h>

#include "FrameRate.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!", sf::Style::Titlebar);
    window.setFramerateLimit(1500);

    FrameRate framerate;
    Player player;
    Enemy enemy;
    framerate.Initialize();
    enemy.Initialize();
    player.Initialize();

    framerate.Load();
    player.Load();
    enemy.Load();

   
    sf::Clock clock;

    while (window.isOpen())
    {
    sf::Time DeltaTimeTimer = clock.restart(); 
    float DeltaTime = DeltaTimeTimer.asMicroseconds() / 1000.0; 
    

        //-------------- UPDATE ------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
    }
    framerate.Update(DeltaTime);
    enemy.Update(DeltaTime);   
    player.Update(DeltaTime,enemy);

//-------------- UPDATE ------------
//-------------- DRAW ------------
        window.clear(); 
        player.Draw(window);
        enemy.Draw(window);
        framerate.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}