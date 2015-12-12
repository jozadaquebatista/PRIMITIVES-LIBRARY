#include "../PRIMITIVES/Rect.hpp"

PRIMITIVES2D::Rect::Rect(){}
PRIMITIVES2D::Rect::~Rect(){ std::clog << "Rect deleted." << std::endl; }

void PRIMITIVES2D::Rect::update(SDL_Renderer *renderer, float xPos, float yPos, uint8_t w, uint8_t h)
{

	for (y=yPos; y<yPos+h; y++)
		for (x=xPos; x<xPos+w; x++)
		{
		   	SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, x, y);
		}

}