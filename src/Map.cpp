#include <SFML/Graphics.hpp>
#include "Map.hpp"

Map::Map() {}
Map::~Map() { delete[] tiles; }

void Map::Initialize()
{

}
void Map::Load()
{
    
    mapLoader.Load("assets/map/My_Map.rmap", md);
    if(tileSheetTexture.loadFromFile(md.tilesheet))
    {
    totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
    totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

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
        tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);
        }
    }
    for (size_t y = 0; y < mapHeight; y++)
    {
        for(size_t x = 0; x < mapWidth; x++)
        {
            int i = x + y * mapWidth;
            
            int index = md.data[i];

            mapSprites[i].setTexture(tileSheetTexture);

            mapSprites[i].setTextureRect(sf::IntRect(
            sf::Vector2i(tiles[index].position.x, tiles[index].position.y),
            sf::Vector2i(md.tileWidth, md.tileHeight)));
               mapSprites[i].setScale(sf::Vector2f(5, 5));
               mapSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * md.scaleX, 100 + y * md.tileHeight * md.scaleY));
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