#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.hpp"

void Enemy::Initialize()
{

}
void Enemy::Load()
{
    if (!texture.loadFromFile("assets/Enemy/Textures/enemySpriteSheet.png"))
    {
        std::cout << "Enemy Image Loaded!" << std::endl;
        int xIndex = 1;
        int yIndex = 2;
    
        sprite.setScale({2.f, 2.f});
        sprite.scale({0.8f, 0.8f});
        sprite.setTextureRect(sf::IntRect({xIndex * 50, yIndex * 64}, {50, 64}));
    } 
   
    sf::Sprite enemySprite(texture);
}
void Enemy::Update()
{

}
void Enemy::Draw(sf::RenderWindow& window)
{
   window.draw(sprite);
}