#pragma once
#include <SFML/Graphics.hpp>

class MouseTile
{
    private:
    sf::Texture Tilesheet;
    sf::Sprite Tile;

    sf::Vector2i tileSize;
    sf::Vector2i tileScale;
    public:
    MouseTile(const sf::Vector2i& tileSize,
              const sf::Vector2i& tileScale
             );
    void Initialize(); 
    void Load();    
    void Update(float DeltaTime, sf::Vector2f MousePosition);      
    void Draw(sf::RenderWindow& window);   
};