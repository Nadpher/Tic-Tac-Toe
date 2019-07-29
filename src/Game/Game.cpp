#include "Game.hpp"

Application::Game::Game(iCoord pScreenSize, const char* windowName)
{
    window.create(sf::VideoMode(pScreenSize.x, pScreenSize.y), windowName, sf::Style::Titlebar | sf::Style::Close);
    board.setCellSize(pScreenSize);
}

iCoord Application::Game::selectCell(iCoord cursorPosition)
{
    for (size_t i = 0; i < Screen::Board::size; ++i)
    {
        for (size_t j = 0; j < Screen::Board::size; ++j)
        {
            iCoord cellPosition = {j * cellsize.x, i * cellsize.y};

            // AABB Collision detection 
            // Size isn't added to mouse coordinates since the cursor doesn't have a rectangle
            if (cursorPosition.x < cellPosition.x + cellsize.x &&
                cursorPosition.x > cellPosition.x              &&
                cursorPosition.y < cellPosition.y + cellsize.y &&
                cursorPosition.y > cellPosition.y)
            {
                return 
            }
        }
    }
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
                iCoord cell = selectCell({event.mouseButton.x, event.mouseButton.y});
                board.update(window, {event.mouseButton.x, event.mouseButton.y});
            }
            break;
        }
    }
}

void Application::Game::run()
{
    board.draw(window);

    while (window.isOpen())
    {
        handleEvents();
        window.display();
    }
}