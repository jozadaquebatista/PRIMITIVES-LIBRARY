#pragma once
#ifndef __RECT__
#define __RECT__
#include "../Utilities/Util.hpp"

namespace PRIMITIVES2D
{

class Rect
{
private:
	float x, y;
public:
	Rect();
	~Rect();

	void update(SDL_Renderer *, float, float, uint8_t, uint8_t);
};

}


#endif