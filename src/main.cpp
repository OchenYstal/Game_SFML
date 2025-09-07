#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f Normolize(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normolizeVector;

    normolizeVector.x = vector.x / m;
    normolizeVector.y = vector.y / m;
    
    return normolizeVector;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!", sf::Style::Titlebar);
    //------------------------Bullet ------------------------
    
    std::vector<sf::RectangleShape> bullets;

    //sf::RectangleShape bullet(sf::Vector2f({45, 22}));
    float bulletSpeed = 0.5f;

    //------------------------Bullet ------------------------

    //-------------- Enemy ------------

     sf::Texture enemyTexture;
    if (enemyTexture.loadFromFile("assets/Enemy/Textures/enemySpriteSheet.png"))
    {
        std::cout << "Enemy Image Loaded!" << std::endl;
        
    }
    else 
    {
       std::cout << "Enemy image failed to loaded!" << std::endl;
    }
    sf::Sprite enemySprite(enemyTexture);
    enemySprite.setPosition(sf::Vector2f(1600, 700));
    int xIndex = 1;
    int yIndex = 2;

    enemySprite.setTextureRect(sf::IntRect({xIndex * 50, yIndex * 64}, {50, 64}));
    enemySprite.scale(sf::Vector2f(3, 3));
    //-------------- Enemy ------------

    //-------------- Plyer ------------
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
    playerSprite.setPosition(sf::Vector2f({0, 0}));
        //-------------- Plyer ------------
    //------------ Calculate direction of the Bullet ---------------
    //bulletDirection = Normolize(bulletDirection);

    //------------ Calculate direction of the Bullet ---------------

    while (window.isOpen())
    {
        //-------------- UPDATE ------------
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

          
    }
    //bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        playerSprite.setPosition(position + sf::Vector2f(0.5, 0));
    
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        playerSprite.setPosition(position + sf::Vector2f(-0.5, 0));

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        playerSprite.setPosition(position + sf::Vector2f(0, 0.5));   
         
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        playerSprite.setPosition(position + sf::Vector2f(0, -0.5));
         if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
         {
            bullets.push_back(sf::RectangleShape(sf::Vector2f({40, 20})));

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
            
            
         }
         for (size_t i = 0; i < bullets.size(); i++)
         {
            sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = Normolize(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
         }
        
//-------------- UPDATE ------------

        //-------------- DRAW ------------
        window.clear();
        window.draw(enemySprite);
        window.draw(playerSprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        
        window.display();
        //-------------- DRAW -------------
    }
    
}