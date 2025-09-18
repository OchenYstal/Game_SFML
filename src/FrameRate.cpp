#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.hpp"

void FrameRate::Initialize()
{

}
void FrameRate::Load()
{
    if(!font.openFromFile("assets/Fonts/Font1FPS.ttf"))
    {
        std::cout << "Failed to Load Font1FPS" << std::endl;   
    }
    
}
void FrameRate::Update(float DeltaTime)
{
    float fps = 1000 / DeltaTime;

    std::string frameRateText = "FPS: "  + std::to_string((int)fps) + " FrameTime: " + std::to_string((int)DeltaTime);
    FrameRateText.setString(frameRateText);
}
void FrameRate::Draw(sf::RenderWindow& window)
{
  window.draw(FrameRateText);
}