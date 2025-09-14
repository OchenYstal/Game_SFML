#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Math
{
    public:
    static sf::Vector2f Normolize(sf::Vector2f vector);
    static bool DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2);
};