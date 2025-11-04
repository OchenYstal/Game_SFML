#pragma once
#include "Tile.hpp"
#include "MapLoader.hpp"
#include "MapDate.hpp"
#include <SFML/Graphics.hpp>

class Map
{
    private:
    sf::Texture tileSheetTexture;

    Tile* tiles;

    MapLoader mapLoader;
    MapDate md;

    int totalTiles;

    int totalTilesX;
    int totalTilesY;
    
    sf::Sprite* mapSprites = nullptr;

    public:
    Map();
    ~Map();

    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};