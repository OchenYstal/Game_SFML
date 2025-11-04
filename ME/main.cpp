#include <SFML/Graphics.hpp>
#include "Grid.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Map Editor", sf::Style::Titlebar);
    window.setFramerateLimit(1500);

    sf::Clock clock;

    Grid grid(sf::Vector2i(12, 9), sf::Vector2f(15, 13), sf::Vector2i(16, 16), sf::Vector2i(4, 4), 1);

    grid.Initialize();

    grid.Load();

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
    grid.Update(DeltaTime);
    //-------------- UPDATE ------------
//-------------- DRAW ------------
        window.clear(); 
        grid.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}
