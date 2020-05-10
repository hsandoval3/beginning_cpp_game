#ifndef GAME_HPP
#define GAME_HPP

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
    SDL_Surface* gCurrentSurface{nullptr};

public:
    //Starts up SDL and creates window
    bool init();

    bool loadMedia(std::string);
 
    SDL_Surface* loadSurface(std::string);

    //Frees media and shuts down SDL
    void close();

    void event();

    void draw ();
};

#endif