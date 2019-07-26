#include "Game/Game.hpp"

int main()
{
    Application::Game game({600, 600}, "Tic Tac Toe");
    game.run();
}