#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{

private:
    sf::Text FrameRateText;
    sf::Font font;

    float timer;
public:
   FrameRate() : FrameRateText(font) {};

 public:
    
    
    void Initialize(); 
    void Load();     
    void Update(float DeltaTime);      
    void Draw(sf::RenderWindow& window);    
};