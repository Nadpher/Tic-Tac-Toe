#include "Board.hpp"

Screen::Board::Board()
{
    logic = 
    {
        FREE, FREE, FREE,
        FREE, FREE, FREE,
        FREE, FREE, FREE
    };
}

bool Screen::Board::gameOver() {return bGameisOver;}
bool Screen::Board::equals3(int num1, int num2, int num3)
{
    if (num1 == num2 && num1 == num3 && num2 == num3 && num1 != FREE)
    {
        return true;
    }
    return false;
}

void Screen::Board::setCellSize(iCoord windowSize)
{
    cellsize.x = windowSize.x / size;
    cellsize.y = windowSize.y / size;
}

int Screen::Board::checkLogic()
{
    // Vertical
    for(int i = 0; i < size; ++i)
    {
        if (equals3(logic[i * size + 0], logic[i * size + 1], logic[i * size + 2]))
        {
            return logic[i * size + 0];
        }
    }

    // Horizontal
    for(int i = 0; i < size; ++i)
    {
        if (equals3(logic[0 * size + i], logic[1 * size + i], logic[2 * size + i]))
        {
            return logic[0 * size + i];
        }
    }
}

// Is only called once, manually setting the lines is just easier
void Screen::Board::draw(sf::RenderWindow& win)
{
    sf::Vertex grid[] =
    {
        // Horizontal lines
        sf::Vertex(sf::Vector2f(0, cellsize.y)),
        sf::Vertex(sf::Vector2f(cellsize.x * size, cellsize.y)),

        sf::Vertex(sf::Vector2f(0, cellsize.y * 2)),
        sf::Vertex(sf::Vector2f(cellsize.x * size, cellsize.y * 2)),

        // Vertical Lines
        sf::Vertex(sf::Vector2f(cellsize.x, 0)),
        sf::Vertex(sf::Vector2f(cellsize.x, cellsize.y * size)),

        sf::Vertex(sf::Vector2f(cellsize.x * 2, 0)),
        sf::Vertex(sf::Vector2f(cellsize.x * 2, cellsize.y * size))
    };

    // Draws the vertex array, 8 is the number of vertex
    win.draw(grid, 8, sf::Lines);
}

bool Screen::Board::empty()
{
    
}

void Screen::Board::update(sf::RenderWindow& win, iCoord mouseCoords)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            iCoord cellPosition = {j * cellsize.x, i * cellsize.y};

            // AABB Collision detection 
            // Size isn't added to mouse coordinates since the cursor doesn't have a rectangle
            if (mouseCoords.x < cellPosition.x + cellsize.x &&
                mouseCoords.x > cellPosition.x              &&
                mouseCoords.y < cellPosition.y + cellsize.y &&
                mouseCoords.y > cellPosition.y)
            {
                place({j, i});
                nextTurn();
            }
        }
    }

    checkLogic();
}