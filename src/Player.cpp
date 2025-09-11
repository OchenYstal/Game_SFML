#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Math.hpp"

void Player::Initialize()
{
     
}
void Player::Load()
{

 if (!texture.loadFromFile("assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player image failed to loaded!" << std::endl;
        
    }
   
    sf::Sprite sprite(texture);
    
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
}
void Player::Draw(sf::RenderWindow& window)
{
   window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
}