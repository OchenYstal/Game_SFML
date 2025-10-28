#pragma once
#include "Tile.hpp"

#include <SFML/Graphics.hpp>

class Map
{
    private:
    sf::Texture tileSheetTexture;

    Tile* tiles;

    int totalTiles;
    int tileWidth = 16;
    int tileHeight = 16;

    int totalTilesX;
    int totalTilesY;

    int mapNumbers[6] = {
        1, 1, 1,
        5, 5, 5
    };

    sf::Sprite* mapSprites = nullptr;

    public:
    Map();
    ~Map();

    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};