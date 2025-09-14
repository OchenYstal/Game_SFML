#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Math.hpp"

void Player::Initialize()
{
     boundRectangle.setFillColor(sf::Color::Transparent);
     boundRectangle.setOutlineColor(sf::Color::Blue);
     boundRectangle.setOutlineThickness(1);

     size = sf::Vector2i(64, 64);
}

void Player::Load()
{

 if (!texture.loadFromFile("assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player image failed to loaded!" << std::endl;
         
    } 
    sprite.setScale({2.f, 2.f});
    sprite.scale({0.8f, 0.8f});
    int XIndex = 1;
    int YIndex = 0;

    sprite.setTextureRect(sf::IntRect({XIndex * size.x, YIndex * size.y}, {size.x, size.y}));  
    boundRectangle.setSize(sf::Vector2f (size.x * sprite.getScale().x, size.y * sprite.getScale().y));    
}
void Player::Update(Enemy& enemy)
{
sf::Vector2f position = sprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.setPosition(position + sf::Vector2f(0.5, 0));
    
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.setPosition(position + sf::Vector2f(-0.5, 0));

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.setPosition(position + sf::Vector2f(0, 0.5));   
         
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.setPosition(position + sf::Vector2f(0, -0.5));



         if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
         {
            bullets.push_back(sf::RectangleShape(sf::Vector2f({40.f, 20.f})));

            int i = bullets.size() - 1;
            bullets[i].setPosition(sprite.getPosition());   
         }
         for (size_t i = 0; i < bullets.size(); i++)
         {
            sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
            bulletDirection = Math::Normolize(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
         }
         boundRectangle.setPosition(sprite.getPosition());


         if(Math::DidRectCollide(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds()))
         {
            std::cout << "Collision" << std::endl;
         }
}
void Player::Draw(sf::RenderWindow& window)
{
   window.draw(boundRectangle);
   window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
}