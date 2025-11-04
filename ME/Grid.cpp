#include <SFML/Graphics.hpp>
#include "Grid.hpp"

Grid::Grid(const sf::Vector2i& totalCells,
           const sf::Vector2f& position,
           const sf::Vector2i& cellSize,
           const sf::Vector2i& scale,
           const int& LineThikness
           ) : 
scale(scale), totalCells(totalCells), cellSize(cellSize), LineThikness(LineThikness), position(position)  
{
   totalLines = sf::Vector2i({totalCells.x + 1, totalCells.y + 1});

   hLine = new sf::RectangleShape[totalLines.y];
   vLine = new sf::RectangleShape[totalLines.x];
}
Grid::~Grid()
{
   delete[] hLine;
   delete[] vLine;
}
void Grid::Initialize()
{
   int horizontalLineLenght = totalCells.x * cellSize.x * scale.x + LineThikness;

   for(size_t i = 0; i < totalLines.y; i++)
   {
      hLine[i].setSize(sf::Vector2f(horizontalLineLenght, LineThikness));
      hLine[i].setPosition(position + sf::Vector2f(0, i * cellSize.y * scale.y));
   }
   

   int verticalLineLenght = totalCells.y * cellSize.y * scale.y;

   for(size_t i = 0; i < totalLines.x; i++)
   {
      vLine[i].setSize(sf::Vector2f(LineThikness, verticalLineLenght));
      vLine[i].setPosition(position + sf::Vector2f(i * cellSize.x * scale.x, 0));
   }
   
}

void Grid::Load()
{
    
}
void Grid::Update(float DeltaTime)
{

}
void Grid::Draw(sf::RenderWindow& window)
{
   for(size_t i = 0; i < totalLines.y; i++)
   {
   window.draw(hLine[i]);
   }
   for(size_t i = 0; i < totalLines.x; i++)
   {
   window.draw(vLine[i]);
   }
}