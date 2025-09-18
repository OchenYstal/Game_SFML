#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{

private:
    sf::Text FrameRateText;
    sf::Font font;
public:
    FrameRate() : FrameRateText(font) {};

 public:
    void Initialize(); //<-- Вызывается один раз за запуск приложения
    void Load();    //<-- called once per App start
    void Update(float DeltaTime);      //<-- Once per frame
    void Draw(sf::RenderWindow& window);    //<-- Once per frame
};