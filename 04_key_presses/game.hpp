#ifndef GAME_HPP
#define GAME_HPP

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <memory>

class Game {

private:  
    const int SCREEN_WIDTH{640};
    const int SCREEN_HEIGHT{480};

    //Key press surfaces constants
    enum KeyPressSurfaces
    {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };

    //The window we'll be rendering to
    SDL_Window* gWindow{nullptr};
        
    //The surface contained by the window
    SDL_Surface* gScreenSurface{nullptr};

    //The images that correspond to a keypress
    SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

    //The image we will load and show on the screen
    SDL_Surface* gCurrentSurface{nullptr};

public:
    //Starts up SDL and creates window
    bool init();

    bool loadMedia(std::string,std::string,std::string,std::string,std::string);
 
    SDL_Surface* loadSurface(std::string);

    //Frees media and shuts down SDL
    void close();

    void event();

    void draw ();
};

#endif