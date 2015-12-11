#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#define newtype typedef struct

namespace PRIMITIVES
{

newtype MouseState
{
private:
public:
	int mx, my;

	MouseState()
	{
		std::clog << "MouseState Constructor Started ... " << std::endl;
		std::clog << "PI: " << M_PI << std::endl;
	}
	void update()
	{
		SDL_GetMouseState(&mx, &my);
	}
}MouseState;

newtype Circle : public MouseState
{
private:
	float i, j;
public:
	Circle() : MouseState()
	{
		
	}

	~Circle(){ std::clog << "Circle deleted." << std::endl; }

	void update(SDL_Renderer *renderer)
	{

		for(i=100; i>=0; i-=.5)
			for (j=0; j<2*M_PI; j+=0.01)
			{
		   		int x = mx + i*cos(j);
		    	int y = my + i*sin(j);
		    	SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 0x00);
				SDL_RenderDrawPoint(renderer, x, y);
		  	}
		for(i=100; i>=99; i-=.5)
			for (j=0; j<2*M_PI; j+=0.01)
			{
		   		int x = mx + i*cos(j);
		    	int y = my + i*sin(j);
		    	SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0x00);
				SDL_RenderDrawPoint(renderer, x, y);
		  	}

		  	SDL_RenderDrawPoint( renderer, 30, 10 );
		  	SDL_RenderDrawPoint( renderer, 10, 30 );
		  	SDL_RenderDrawPoint( renderer, 30, 30 );

		MouseState::update();

	}
}Circle;

newtype Rect : public MouseState
{
private:
	float x, y;
public:
	Rect() : MouseState()
	{
		
	}

	~Rect(){ std::clog << "Rect deleted." << std::endl; }

	void update(SDL_Renderer *renderer)
	{

		for (y=my; y<my+50; y++)
			for (x=mx; x<mx+50; x++)
			{
			   	SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0x00);
				SDL_RenderDrawPoint(renderer, x, y);
			}

		MouseState::update();

	}
}Rect;

} // END OF NAMESPACE

bool Running = true;
int c_X = 10,
	c_Y = 10;
int mx, my;

int main( int argc, char **argv )
{

	SDL_Init(SDL_INIT_VIDEO);

		SDL_Window *window = SDL_CreateWindow( "Trigonometric World ^-^*",
											   SDL_WINDOWPOS_UNDEFINED,
											   SDL_WINDOWPOS_UNDEFINED,
											   800*2, 648*2,
											   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_Event event;

		PRIMITIVES::Circle *circle = new PRIMITIVES::Circle;
		PRIMITIVES::Rect   *rect   = new PRIMITIVES::Rect;

		while(Running)
		{
			SDL_RenderClear(renderer);

			while(SDL_PollEvent( &event ))
			{
				switch( event.type )
				{
					case SDL_QUIT:
						Running = false;
						break;

					case SDL_KEYDOWN:
						switch( event.key.keysym.sym )
						{
							case SDLK_ESCAPE:
								Running = false;
								break;

							case SDLK_UP:
								c_Y -= 10;
								break;

							case SDLK_DOWN:
								c_Y += 10;
								break;

							case SDLK_LEFT:
								c_X -= 10;
								break;

							case SDLK_RIGHT:
								c_X += 10;
								break;

						}
						break;
				}
			}


			circle->update(renderer);
			rect->update(renderer);

		  	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0x00);
			SDL_RenderPresent(renderer);
		}

	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	delete circle;
		circle = nullptr;
	delete rect;
		rect = nullptr;
	SDL_Quit();
}
