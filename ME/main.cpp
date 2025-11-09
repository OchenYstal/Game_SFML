#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "MouseTile.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Map Editor", sf::Style::Titlebar);
    window.setFramerateLimit(1500);

    sf::Clock clock;

    Grid grid(sf::Vector2i(12, 9), sf::Vector2f(0, 0), sf::Vector2i(16, 16), sf::Vector2i(5, 5), 1);
    MouseTile mouseT(sf::Vector2i(16, 16), sf::Vector2i(5, 5) );

    grid.Initialize();
    mouseT.Initialize();
    grid.Load();
    mouseT.Load();
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

    grid.Update(DeltaTime);
    mouseT.Update(DeltaTime, MousePosition);
    //-------------- UPDATE ------------
//-------------- DRAW ------------
        window.clear(); 
        grid.Draw(window);
        mouseT.Draw(window);
        window.display();
//-------------- DRAW -------------
    }
}
