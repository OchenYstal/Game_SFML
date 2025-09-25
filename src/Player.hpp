#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Enemy.hpp"

class Player
{
    private:
    sf::Texture texture;
    sf::RectangleShape boundRectangle;
    sf::Vector2i size;
    sf::Vector2i globalMousePosition;
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed;
    float PlayerSpeed;
    float maxFireRate; 
    float fireRateTimer;
    public:
    sf::Sprite sprite;
   

    public:
    Player() : sprite(texture), bulletSpeed(0.2f), PlayerSpeed(2.0f), maxFireRate(500), fireRateTimer(0) {};

    void Initialize(); //<-- Вызывается один раз за запуск приложения
    void Load();    //<-- called once per App start
    void Update(float DeltaTime, Enemy& enemy, sf::RenderWindow& window);      //<-- Once per frame
    void Draw(sf::RenderWindow& window);    //<-- Once per frame
};
