#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
    private:
    sf::RectangleShape rectangleshape;
    sf::Vector2f direction;
    float speed;

    public:
    //float firaRate;

    public:
    Bullet() : speed(0) {};

    void Initialize(const sf::Vector2f& position, sf::Vector2f& target, float speed); 
    void Load();    
    void Update(float DeltaTime);      
    void Draw(sf::RenderWindow& window);  
    
    inline sf::FloatRect getGlobalBounds() const { return rectangleshape.getGlobalBounds(); }
};