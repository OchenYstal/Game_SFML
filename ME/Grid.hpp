#pragma once
#include <SFML/Graphics.hpp>


class Grid
{
    private:
   sf::RectangleShape* hLine;
   sf::RectangleShape* vLine;
    
   
   sf::Vector2f position;
   sf::Vector2i scale;
   sf::Vector2i totalCells;
   sf::Vector2i cellSize;  

   sf::Vector2i totalLines;
   int LineThikness;

    public:
    Grid(const sf::Vector2i& totalCells,
         const sf::Vector2f& position,
         const sf::Vector2i& cellSize,
         const sf::Vector2i& scale,
         const int& LineThikness
        );
    ~Grid();
    void Initialize(); 
    void Load();    
    void Update(float DeltaTime);      
    void Draw(sf::RenderWindow& window);    
};