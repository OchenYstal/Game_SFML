#include "Math.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>

sf::Vector2f Math::Normolize(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normolizeVector;

    normolizeVector.x = vector.x / m;
    normolizeVector.y = vector.y / m;
    
    return normolizeVector;
}