#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.hpp"

void Enemy::Initialize()
{
     boundRectangle.setFillColor(sf::Color::Transparent);
     boundRectangle.setOutlineColor(sf::Color::Red);
     boundRectangle.setOutlineThickness(1);

     size = sf::Vector2i(50, 64);
}
void Enemy::Load()
{
    if (!texture.loadFromFile("assets/Enemy/Textures/enemySpriteSheet.png"))
    {
        std::cout << "Enemy Image Loaded!" << std::endl;
        
    } 
    int xIndex = 1;
    int yIndex = 2;

    sprite.setScale({2.f, 2.f});
    sprite.scale({0.8f, 0.8f});
    sprite.setPosition(sf::Vector2f({200, 300}));
    sprite.setTextureRect(sf::IntRect({xIndex * size.x, yIndex * size.y}, {size.x, size.y}));
    boundRectangle.setSize(sf::Vector2f (size.x * sprite.getScale().x, size.y * sprite.getScale().y));  
}
void Enemy::Update(float DeltaTime)
{
    boundRectangle.setPosition(sprite.getPosition());

}
void Enemy::Draw(sf::RenderWindow& window)
{
   window.draw(boundRectangle);
   window.draw(sprite);
}