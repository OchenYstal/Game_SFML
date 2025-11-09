#include "MouseTile.hpp"
#include <SFML/Graphics.hpp>

MouseTile::MouseTile(const sf::Vector2i& tileSize, const sf::Vector2i& tileScale) : Tile(Tilesheet), tileSize(tileSize), tileScale(tileScale)  {}



void MouseTile::Initialize()
{

}

void MouseTile::Load()
{
    if (Tilesheet.loadFromFile("assets/map/MapSpritesheet.png"))
    Tile.setTexture(Tilesheet);
    Tile.setTextureRect(sf::IntRect(sf::Vector2i(16, 0), sf::Vector2i(tileSize.x, tileSize.y)));
    Tile.setScale(sf::Vector2f(tileScale.x, tileScale.y));
}

void MouseTile::Update(float DeltaTime, sf::Vector2f MousePosition)
{
    int IntX = MousePosition.x / (tileSize.x * Tile.getScale().x);
    int x = IntX * (tileSize.x * Tile.getScale().x);
    
    int IntY = MousePosition.y / (tileSize.y * Tile.getScale().y);
    int y = IntY * (tileSize.y * Tile.getScale().y);

    Tile.setPosition(sf::Vector2f(x, y));
}

void MouseTile::Draw(sf::RenderWindow& window)
{
    window.draw(Tile);
}