#include "Game.hpp"

Application::Game::Game(iCoord pScreenSize, const char* windowName)
{
    window.create(sf::VideoMode(pScreenSize.x, pScreenSize.y), windowName, sf::Style::Titlebar | sf::Style::Close);
    board.setCellSize(pScreenSize);
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
    board.draw(window);

    while (window.isOpen())
    {
        handleEvents();
        window.display();
    }
}