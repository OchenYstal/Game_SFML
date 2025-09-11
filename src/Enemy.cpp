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
    }
     else 
    {
        std::cout << "texture load, size: " << texture.getSize().x << "x" << texture.getSize().y << std::endl;
        sprite.setTexture(texture);
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