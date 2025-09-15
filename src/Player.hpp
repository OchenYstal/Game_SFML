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

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.2f;
    float PlayerSpeed = 2.0f;
    public:
    sf::Sprite sprite;
    Player() : sprite(texture) {};

    public:
    void Initialize(); //<-- Вызывается один раз за запуск приложения
    void Load();    //<-- called once per App start
    void Update(float DeltaTime, Enemy& enemy);      //<-- Once per frame
    void Draw(sf::RenderWindow& window);    //<-- Once per frame
};
