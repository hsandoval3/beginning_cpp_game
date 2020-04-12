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

bool Game::loadMedia()
{
    string filename{"02_getting_an_image_on_the_screen/hello_world.bmp"};
	//Loading success flag
	auto success{true};

	//Load splash image
	gHelloWorld = SDL_LoadBMP(filename.c_str());
	if(gHelloWorld == nullptr)
	{
		cout << "Unable to load image " << filename << "! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}

	return success;
}

void Game::close()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = nullptr;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::draw()
{
    //Apply the image
    SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
    
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );

    //Wait two seconds
	SDL_Delay( 2000 );
}