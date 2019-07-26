#include <vector>

#include <SFML/Graphics.hpp>

namespace Screen
{
    class Board : public sf::Drawable
    {
        public:

        Board();
        ~Board() = default;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

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


    };
}