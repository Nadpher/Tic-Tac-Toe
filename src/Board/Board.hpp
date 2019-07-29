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
        void update(sf::RenderWindow& win, fCoord cell);
        fCoord setCellSize(iCoord windowSize);
        bool gameOver();
        bool empty(fCoord index);

        static constexpr int size = 3;

        private:

        bool bGameisOver = false;
        fCoord cellsize;

        enum Tile
        {
            FREE = 0,
            PLAYER1,
            PLAYER2
        };

        Tile player;

        // represents the screen using ints
        std::vector<int> logic;

        bool equals3(int num1, int num2, int num3);
        void nextTurn();
        void place(fCoord index);
        int checkLogic();
    };
}