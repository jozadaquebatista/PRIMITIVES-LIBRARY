#include "Utilities/Util.hpp"
#include "PRIMITIVES/Circle.hpp"
#include "PRIMITIVES/Rect.hpp"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

bool Running = true;

using namespace PRIMITIVES2D;

int main( int argc, char **argv )
{
	SDL_Init(SDL_INIT_VIDEO);

		Circle *littleCircle = new Circle;
		Rect   *littleRect = new Rect;

		SDL_Window *window_r = SDL_CreateWindow( "Circle Test Of Use",
												 SDL_WINDOWPOS_UNDEFINED,
												 SDL_WINDOWPOS_UNDEFINED,
												 WINDOW_WIDTH,
												 WINDOW_HEIGHT,
												 SDL_WINDOW_SHOWN);

		SDL_Renderer *renderer = SDL_CreateRenderer(window_r, 0, SDL_RENDERER_ACCELERATED);

		SDL_Event *event = new SDL_Event;

		while(Running)
		{
			SDL_RenderClear(renderer);

			while(SDL_PollEvent( event ))
			{
				switch(event->type)
				{
					case SDL_QUIT:
						Running = false;
						break;

					case SDL_KEYDOWN:
						switch(event->key.keysym.sym)
						{
							case SDLK_ESCAPE:
								Running = false;
								break;
						}
						break;
				}
			}

			littleCircle->update( renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 );
			littleRect->update( renderer, 40, 40, 150, 100 );

			SDL_SetRenderDrawColor( renderer, 0x11, 0x11, 0x11, 0x00 );
			SDL_RenderPresent( renderer );
		}

	delete event;
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window_r );
	delete littleCircle;
	return EXIT_SUCCESS;
	SDL_Quit();
}