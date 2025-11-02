#pragma once
#include <iostream>
#include "MapDate.hpp"
class MapLoader
{
    public:
    void Load(std::string filename, MapDate& mapData);
};