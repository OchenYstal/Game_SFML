#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML works!", sf::Style::Titlebar);
    sf::Texture playerTexture;

    if (playerTexture.loadFromFile("assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player Image Loaded!" << std::endl;
        
    }
    else 
    {
       std::cout << "Player image failed to loaded!" << std::endl;
    }
    
    sf::Sprite playerSprite(playerTexture);
    // X, Y, Width, Height
    int XIndex = 3;
    int YIndex = 0;

    playerSprite.setTextureRect(sf::IntRect({XIndex * 64, YIndex * 64}, {64, 64}));
    playerSprite.scale(sf::Vector2f(3, 3));
    while (window.isOpen())
    {
        //-------------- UPDATE ------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

          
    }
        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        playerSprite.setPosition(position + sf::Vector2f(1, 0));
    
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        playerSprite.setPosition(position + sf::Vector2f(-1, 0));

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        playerSprite.setPosition(position + sf::Vector2f(0, 1));   
         
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        playerSprite.setPosition(position + sf::Vector2f(0, -1));
        
//-------------- UPDATE ------------

        //-------------- DRAW ------------
        window.clear();
        window.draw(playerSprite);
        window.display();
        //-------------- DRAW -------------
    }
    
}