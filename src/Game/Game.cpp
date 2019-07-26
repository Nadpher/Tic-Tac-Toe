#include "Game.hpp"

Application::Game::Game(iCoord pScreenSize, const char* windowName)
: screenSize{pScreenSize}
{
    window.create(sf::VideoMode(screenSize.x, screenSize.y), windowName);
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
                board.update(window, {event.mouseButton.x, event.mouseButton.y});                
            }
            break;
        }
    }
}

void Application::Game::run()
{
    board.draw(window, screenSize);

    while (window.isOpen())
    {
        handleEvents();
        window.display();
    }
}