#include "game.hpp"
#include <iostream>
using namespace std;

bool Game::init()
{
	//Initialization flag
	auto success{true};

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if(gWindow == nullptr)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool Game::loadMedia(string press, string up, string down, string left, string right)
{
	//Loading success flag
	auto success{true};

	//Load default surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface(press.c_str());
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == nullptr )
	{
		cout << "Unable to load image " << press << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	
	//Load up surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface(up.c_str());
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == nullptr )
	{
		cout << "Unable to load image " << up << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	
	//Load down surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface(down.c_str());
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == nullptr )
	{
		cout << "Unable to load image " << down << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	
	//Load left surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface(left.c_str());
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == nullptr )
	{
		cout << "Unable to load image " << left << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface(right.c_str());
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == nullptr )
	{
		cout << "Unable to load image " << right << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}

	return success;
}

SDL_Surface* Game::loadSurface(string path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );

	if( loadedSurface == nullptr )
	{
		cout << "Unable to load image " << path.c_str() <<"! SDL Error: " << path.c_str() << endl;
	}

	return loadedSurface;
}

void Game::close()
{
	//Deallocate surface
	SDL_FreeSurface( gCurrentSurface );
	gCurrentSurface = nullptr;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::event()
{
	//Main loop flag
	auto quit{false};

	//Event handler
	SDL_Event e;

	//Set default current surface
	gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

	//While application is running
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			//User presses a key
			else if( e.type == SDL_KEYDOWN )
			{
				//Select surfaces based on key press
				switch( e.key.keysym.sym )
				{
					case SDLK_UP:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
					break;

					case SDLK_DOWN:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
					break;

					case SDLK_LEFT:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
					break;

					case SDLK_RIGHT:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
					break;

					default:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
					break;
				}
			}
		}
		draw();
	}	
}

void Game::draw()
{
    //Apply the image
    SDL_BlitSurface(gCurrentSurface, nullptr, gScreenSurface, nullptr);
    
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );
}
