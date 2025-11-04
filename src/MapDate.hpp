#pragma once
#include <string>

struct MapDate
{
    int version = 0;
    
    std::string tilesheet = "";
    std::string name = "";
    
    int mapWidth = 0;
    int mapHeight = 0;

    int tileWidth = 0;
    int tileHeight = 0;

    int scaleX = 0;
    int scaleY = 0;

    int dataLenght = 0;
    int* data = nullptr;
};