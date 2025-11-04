#include <SFML/Graphics.hpp>
#include <math.h>

#include "FrameRate.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Map.hpp"

#include "MapLoader.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML works!", sf::Style::Titlebar);
    window.setFramerateLimit(1500);

    FrameRate framerate;
    Player player;
    Enemy enemy;
    Map nmap;
    
    
    
    framerate.Initialize();
    enemy.Initialize();
    player.Initialize();

    framerate.Load();
    player.Load();
    nmap.Load();
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
    sf::Vector2f MousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    framerate.Update(DeltaTime);
    enemy.Update(DeltaTime);   
    player.Update(DeltaTime,enemy, MousePosition);

//-------------- UPDATE ------------
//-------------- DRAW ------------
        window.clear(); 
        nmap.Draw(window);
        player.Draw(window);
        enemy.Draw(window);
        framerate.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}
