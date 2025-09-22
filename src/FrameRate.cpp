#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "FrameRate.hpp"


FrameRate::~FrameRate()
{
    
}
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
    timer += DeltaTime;

    if(timer > 100.0f)
    {
    float fps = 1000.0 / DeltaTime;
    FrameRateText.setString("FPS: "  + std::to_string((int)fps) + " FrameTime: " + std::to_string((int)DeltaTime));
    timer = 0;
    }
    
}
void FrameRate::Draw(sf::RenderWindow& window)
{
  window.draw(FrameRateText);
}