#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Enemy.hpp"

void Enemy::ChangeHealth(int hp)
{
    Health += hp;
    HealtText.setString(std::to_string(Health));

}
void Enemy::Initialize()
{
     boundRectangle.setFillColor(sf::Color::Transparent);
     boundRectangle.setOutlineColor(sf::Color::Red);
     boundRectangle.setOutlineThickness(1);

     size = sf::Vector2i(50, 64);
}
void Enemy::Load()
{
    if(!font.openFromFile("assets/Fonts/Font1FPS.ttf"))
    {
        std::cout << "Failed to Load Font1FPS" << std::endl;    
    }
    HealtText.setFont(font);
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
    if(Health > 0)
    {
    boundRectangle.setPosition(sprite.getPosition());

    HealtText.setPosition(sprite.getPosition());
    }
    

}
void Enemy::Draw(sf::RenderWindow& window)
{
    if(Health > 0)
    {
    window.draw(boundRectangle);
    window.draw(sprite);
    window.draw(HealtText);
    }
   
}