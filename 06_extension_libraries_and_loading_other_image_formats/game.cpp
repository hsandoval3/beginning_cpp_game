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
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
	}

	return success;
}

bool Game::loadMedia(string filename)
{
	//Loading success flag
	auto success{true};

	//Load stretching surface
	gCurrentSurface = loadSurface( filename.c_str() );
	if( gCurrentSurface == nullptr )
	{
		cout << "Unable to load image " << filename << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}

	return success;
}

SDL_Surface* Game::loadSurface(string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface{nullptr};

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == nullptr )
	{
		cout << "Unable to load image " << path.c_str() << "! SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == nullptr )
		{
			cout << "Unable to optimize image " << path.c_str() << "! SDL Error: " << SDL_GetError() << endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
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
	IMG_Quit();
	SDL_Quit();
}

void Game::event()
{
	//Main loop flag
	auto quit{false};

	//Event handler
	SDL_Event e;

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
		}
		
		draw();
	}
		
}

void Game::draw()
{
	//Apply the PNG image
	SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
    
	//Update the surface
	SDL_UpdateWindowSurface( gWindow );
}
