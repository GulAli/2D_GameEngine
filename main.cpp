#include "Game.hpp"

Game *game = nullptr;

int main( int argc, char *argv[] )
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS; // Max time we have between frames

    Uint32 frameStart;
    int frameTime; 

    game = new Game();
    game->init("GameWindow", 800, 640, false);

    while( game->running() )
    {
        frameStart = SDL_GetTicks(); // Shows how many milliseconds we spend to initialize the game

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart; // How long it takes to handle our events, update our object and render it in milliseconds

        if( frameDelay > frameTime )
        {
            SDL_Delay( frameDelay - frameTime ); // By doing so, we have smoother view
        }
    }

    game->clean();

    return 0;
}