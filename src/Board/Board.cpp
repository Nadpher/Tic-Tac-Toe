#include "Board.hpp"

Screen::Board::Board()
{

}

// Dividing by 3 since the grid is 3x3
void Screen::Board::setCellSize(iCoord windowSize)
{
    cellsize.x = windowSize.x / 3;
    cellsize.y = windowSize.y / 3;
}

void Screen::Board::checkLogic()
{

}

// Is only called once, manually setting the lines is just easier
void Screen::Board::draw(sf::RenderWindow& win)
{
    sf::Vertex grid[] =
    {
        // Horizontal lines
        sf::Vertex(sf::Vector2f(0, cellsize.y)),
        sf::Vertex(sf::Vector2f(cellsize.x * 3, cellsize.y)),

        sf::Vertex(sf::Vector2f(0, cellsize.y * 2)),
        sf::Vertex(sf::Vector2f(cellsize.x * 3, cellsize.y * 2)),

        // Vertical Lines
        sf::Vertex(sf::Vector2f(cellsize.x, 0)),
        sf::Vertex(sf::Vector2f(cellsize.x, cellsize.y * 3)),

        sf::Vertex(sf::Vector2f(cellsize.x * 2, 0)),
        sf::Vertex(sf::Vector2f(cellsize.x * 2, cellsize.y * 3))
    };

    // Draws the vertex array, 8 is the number of vertex
    win.draw(grid, 8, sf::Lines);
}

void Screen::Board::update(sf::RenderWindow& win, iCoord mouseCoords)
{

}