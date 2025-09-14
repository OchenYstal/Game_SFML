#include "Math.hpp"
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f Math::Normolize(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normolizeVector;

    normolizeVector.x = vector.x / m;
    normolizeVector.y = vector.y / m;
    
    return normolizeVector;
}
bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if(rect1.findIntersection(rect2))
    {
     return true;    
    }
    return false;
}