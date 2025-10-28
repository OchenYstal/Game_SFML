#include <SFML/Graphics.hpp>
#include "Map.hpp"


Map::Map() {}
Map::~Map() { delete[] tiles; }

void Map::Initialize()
{

}
void Map::Load()
{
    if(tileSheetTexture.loadFromFile("assets/Map/MapSpritesheet.png"))
    {
    totalTilesX = tileSheetTexture.getSize().x / tileWidth;
    totalTilesY = tileSheetTexture.getSize().y / tileHeight;

    totalTiles = totalTilesX * totalTilesY;

    mapSprites = new sf::Sprite[6]{
        sf::Sprite(tileSheetTexture),
        sf::Sprite(tileSheetTexture),
        sf::Sprite(tileSheetTexture),
        sf::Sprite(tileSheetTexture),
        sf::Sprite(tileSheetTexture),
        sf::Sprite(tileSheetTexture)
    };
    tiles = new Tile[totalTiles];

    for(size_t y = 0; y < totalTilesY; y++)
    {  
        for(size_t x = 0; x < totalTilesX; x++)
        {
            int i = x + y * totalTilesX;
            
        tiles[i].id = i;
        tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
        }
    }
    for (size_t y = 0; y < 2; y++)
    {
        for(size_t x = 0; x < 3; x++)
        {
            int i = x + y * 3;
            
            int index = mapNumbers[i];

            mapSprites[i].setTexture(tileSheetTexture);

   mapSprites[i].setTextureRect(sf::IntRect(
    sf::Vector2i(tiles[index].position.x, tiles[index].position.y),
    sf::Vector2i(tileWidth, tileHeight)));
            mapSprites[i].setScale(sf::Vector2f(4, 4));
            mapSprites[i].setPosition(sf::Vector2f(x * 16 * 5, 100 + y * 16 * 5));
        }
    }
    }
}
void Map::Update()
{

}
void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 6; i++)
    {
        window.draw(mapSprites[i]);
    }
}