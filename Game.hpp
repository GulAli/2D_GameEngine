#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL_image.h"

class Game
{
    public:
        Game();
        ~Game();

        void init(const char* title, int width, int height, bool fullscreen);
        
        void handleEvents();
        void update();
        bool running() { return isRunning; }
        void render();
        void clean();

        static SDL_Renderer *renderer;
    private:
        bool isRunning = false;
        int cnt = 0;
        SDL_Window *window;
};

#endif /* Game_hpp */