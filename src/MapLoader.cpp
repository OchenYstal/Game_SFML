#include "MapLoader.hpp"
#include <fstream>
#include <string>

void MapLoader::Load(std::string filename, MapDate& mapData) 
{
    std::string line;
    std::ifstream file(filename);
    
    bool mapValid = false;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            if(!mapValid)
            {
            if(line == "[Map]")
            {
                mapValid = true;
                continue;
            }
            else
            {
                std::cout << "rmap Break " << std::endl;
                break;
            } 
            }
            
            if(mapValid)
            {
                try
                {
                 int count = line.find("=");
                 if (count == std::string::npos)
                 continue;
                
                 std::string varaible = line.substr(0, count);
                 std::string value = line.substr(count + 1, line.length() - count);
                
                 if(varaible == "version")
                 {
                 mapData.version = std::stoi(value);
                 }
                 if(varaible == "tilesheet")
                 {
                 mapData.tilesheet = value;
                 }
                 else if(varaible == "name")
                 {
                 mapData.name = value;
                 }
                 else if(varaible == "tileWidth")
                 {
                 mapData.tileWidth = std::stoi(value);
                 }
                 else if(varaible == "tileHeight")
                 {
                 mapData.tileHeight = std::stoi(value);
                 }
                 else if(varaible == "scaleX")
                 {
                 mapData.scaleX = std::stoi(value);
                 }
                 else if(varaible == "scaleY")
                 {
                 mapData.scaleY = std::stoi(value);
                 }
                 else if(varaible == "dataLenght")
                 {
                 mapData.dataLenght = std::stoi(value);
                 }
                 else if(varaible == "data")
                 {
                 mapData.data = new int[mapData.dataLenght];

                 int offset = 0;
                 int i = 0;
                 while(offset < value.size())
                 {
                    int count = value.find(',', offset);
                    if (count == std::string::npos)
                    count = value.size();

                    std::string mapIndex = value.substr(offset, count - offset);                  
                    if(mapIndex == ";" || mapIndex.empty())
                    break;
                
                    mapData.data[i] = std::stoi(mapIndex);

                    offset = count + 1;
                    i++;
                 } 
                 }  
                }          
                catch (const std::exception&)
                {
                   std::cout << "!!!Maybe Problem from " << filename << std::endl;
                }           
            }

        }       
        file.close();
    }
    else
    {
        std::cout << "Unable to open " << std::endl;
    }
}