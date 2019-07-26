#include "Board.hpp"

Screen::Board::Board()
{

}

void Screen::Board::checkLogic()
{

}

// JUST WORKS
void Screen::Board::draw(sf::RenderWindow& win, iCoord screensize)
{
    {
        sf::Vertex line1[] =
        {
            sf::Vertex(sf::Vector2f(screensize.x / 3, 0)),
            sf::Vertex(sf::Vector2f(screensize.x / 3, screensize.y))
        };

        win.draw(line1, 2, sf::Lines);

        sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f((screensize.x / 3) * 2, 0)),
            sf::Vertex(sf::Vector2f((screensize.x / 3) * 2, screensize.y))
        };

        win.draw(line2, 2, sf::Lines);
    }

    sf::Vertex line1[] =
    {
        sf::Vertex(sf::Vector2f(0, screensize.y / 3)),
        sf::Vertex(sf::Vector2f(screensize.x, screensize.y / 3))
    };

    win.draw(line1, 2, sf::Lines);

    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f(0, (screensize.y / 3) * 2)),
        sf::Vertex(sf::Vector2f(screensize.x, (screensize.y / 3) * 2))
    };

    win.draw(line2, 2, sf::Lines);
}

void Screen::Board::update(sf::RenderWindow& win, iCoord mouseCoords)
{

}