#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
    private:
    sf::Texture texture;

    public:  
    sf::Sprite sprite;
    Enemy() : sprite(texture) {};
    
    public:
    void Initialize(); //<-- Вызывается один раз за запуск приложения
    void Load();    //<-- called once per App start
    void Update();      //<-- Once per frame
    void Draw(sf::RenderWindow& window);    //<-- Once per frame
};