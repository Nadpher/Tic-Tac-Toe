#include "Game.hpp"
#include <iostream>

Application::Game::Game(iCoord pScreenSize, const char* windowName)
{
    window.create(sf::VideoMode(pScreenSize.x, pScreenSize.y), windowName, sf::Style::Titlebar | sf::Style::Close);
    cellsize = board.setCellSize(pScreenSize);
}

fCoord Application::Game::selectCell(iCoord cursorPosition)
{
    for (size_t i = 0; i < Screen::Board::size; ++i)
    {
        for (size_t j = 0; j < Screen::Board::size; ++j)
        {
            fCoord cellPosition = {j * cellsize.x, i * cellsize.y};

            // AABB Collision detection 
            // Size isn't added to mouse coordinates since the tip of the cursor doesn't have a rectangle
            if (cursorPosition.x < cellPosition.x + cellsize.x &&
                cursorPosition.x > cellPosition.x              &&
                cursorPosition.y < cellPosition.y + cellsize.y &&
                cursorPosition.y > cellPosition.y)
            {
                return {static_cast<float>(j), static_cast<float>(i)};
            }
        }
    }

    return {0, 0};
}

void Application::Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            window.close();
            break;

            case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                fCoord cell = selectCell({event.mouseButton.x, event.mouseButton.y});
                if (board.empty(cell))
                {
                    result = board.update(window, cell);
                }
            }
            break;
        }
    }
}

void Application::Game::end()
{
    window.clear(sf::Color::Black);

    sf::Text txt;
    txt.setString(result);

    window.draw(txt);
}

void Application::Game::run()
{
    board.draw(window);

    while (window.isOpen())
    {
        handleEvents();
        window.display();

        if (board.gameOver())
        {
            end();
            break;
        }
    }
}