#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

/*
 * init function to initialised window and renderer.
 */
void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if( fullscreen )
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
    {
        std::cout << "INFO : Subsystem Initialised!" << std::endl;

        window = SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags );
        if( window )
        {
            std::cout << "INFO : Window has been created!" << std::endl;
        }

        renderer = SDL_CreateRenderer( window, -1, 0 );
        if( renderer )
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "INFO : Renderer has been created!" << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = new GameObject("F:/GameDevelopment/(3) 2D_GameEngine - Tilemaps/assets/player.png", 0, 0);
    enemy = new GameObject("F:/GameDevelopment/(3) 2D_GameEngine - Tilemaps/assets/enemy.png", 50, 50);
    map = new Map();
}

/*
 * handleEvents function to handle all the events by game.
 */
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    player->Update();
    enemy->Update();
}

/*
 * Render function to render all changes made by game. 
 */
void Game::render()
{
    SDL_RenderClear(renderer);
    // Add textures to be rendered
    map->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game has been cleaned!" << std::endl;
}
