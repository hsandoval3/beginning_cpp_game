/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

#include "game.hpp"
#include <iostream>
using namespace std;

int main( int argc, char* args[] )
{
	Game game;

    string image{"05_optimized_surface_loading_and_soft_stretching/stretch.bmp"};
	
	//Start up SDL and create window
	if( !game.init() )
	{
		cout << "Failed to initialize!\n";
	}
	else
	{
		//Load media
		if( !game.loadMedia(image) )
		{
			cout << "Failed to load media!\n";
		}
		else
		{
			game.event();
		}
	}

	//Free resources and close SDL
	game.close();

	return 0;
}