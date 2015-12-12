#pragma once
#ifndef __CIRCLE__
#define __CIRCLE__
#include "../Utilities/Util.hpp"

namespace PRIMITIVES2D
{

class Circle
{
private:
	float i, j;
public:
	Circle();
	~Circle();
	void update(SDL_Renderer *, float, float);
};

}



#endif