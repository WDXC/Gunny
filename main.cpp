#include <string>

#include <SDL.h>

#include <Game.h>

int main(int /*argc*/, char** /*argv[]*/)
{
    // init game
    Gunny::Game game(std::string("bomberman"), 800, 600);
    // run game loop
    game.run();

    return 0;
}
