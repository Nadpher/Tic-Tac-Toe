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

        void draw(sf::RenderWindow& win, iCoord screensize);
        void update(sf::RenderWindow& win, iCoord mouseCoords);

        static constexpr int size = 3;

        private:

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