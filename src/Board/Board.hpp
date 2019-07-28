#include <vector>
#include "../Util/Coord.hpp"

#include <SFML/Graphics.hpp>

namespace Screen
{
    class Board
    {
        public:

        Board();
        ~Board() = default;

        void draw(sf::RenderWindow& win);
        void update(sf::RenderWindow& win, iCoord mouseCoords);
        void setCellSize(iCoord windowSize);

        static constexpr int size = 3;

        private:

        iCoord cellsize;

        enum Tile
        {
            FREE = 0,
            PLAYER1,
            PLAYER2
        };

        // represents the screen using ints
        std::vector<int> logic
        {
            FREE, FREE, FREE,
            FREE, FREE, FREE,
            FREE, FREE, FREE
        };

        void checkLogic();
    };
}