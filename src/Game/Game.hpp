#pragma once

#include "../Board/Board.hpp"

namespace Application
{
    class Game
    {
        public:

        Game(iCoord pScreenSize, const char* windowName);
        ~Game() = default;

        void run();

        private:

        sf::RenderWindow window;
        Screen::Board board;
        fCoord cellsize;

        void handleEvents();
        fCoord selectCell(iCoord cursorPosition);
    };
}