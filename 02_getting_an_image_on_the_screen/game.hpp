#ifndef GAME_HPP
#define GAME_HPP

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <memory>

class Game {

private:  
    const int SCREEN_WIDTH{640};
    const int SCREEN_HEIGHT{480};
    
    //The window we'll be rendering to
    SDL_Window* gWindow{nullptr};
        
    //The surface contained by the window
    SDL_Surface* gScreenSurface{nullptr};

    //The image we will load and show on the screen
    SDL_Surface* gHelloWorld{nullptr};

public:
    //Starts up SDL and creates window
    bool init();

    bool loadMedia();

    //Frees media and shuts down SDL
    void close();

    void draw ();
};

#endif