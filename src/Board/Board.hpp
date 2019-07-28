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
        bool gameOver();

        static constexpr int size = 3;

        private:

        bool bGameisOver = false;
        iCoord cellsize;

        enum Tile
        {
            FREE = 0,
            PLAYER1,
            PLAYER2
        };

        // represents the screen using ints
        std::vector<int> logic;

        bool equals3(int num1, int num2, int num3);
        int checkLogic();
    };
}