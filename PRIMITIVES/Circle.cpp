#include "../PRIMITIVES/Circle.hpp"

PRIMITIVES2D::Circle::Circle(){}
PRIMITIVES2D::Circle::~Circle(){ std::clog << "Circle deleted." << std::endl; }

void PRIMITIVES2D::Circle::update(SDL_Renderer *renderer, float xPos, float yPos)
{

	for(i=100; i>=0; i-=.5)
		for (j=0; j<2*M_PI; j+=0.01)
		{
	   		int x = xPos + i*cos(j);
	    	int y = yPos + i*sin(j);
	    	SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, x, y);
	  	}

	for(i=100; i>=99; i-=.5)
		for (j=0; j<2*M_PI; j+=0.01)
		{
	   		int x = xPos + i*cos(j);
	    	int y = yPos + i*sin(j);
	    	SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, x, y);
	  	}

	  	// SDL_RenderDrawPoint( renderer, 30, 10 );
	  	// SDL_RenderDrawPoint( renderer, 10, 30 );
	  	// SDL_RenderDrawPoint( renderer, 30, 30 );
	  	
}