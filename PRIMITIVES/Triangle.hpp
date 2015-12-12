#pragma once
#ifndef __TRIANGLE__
#define __TRIANGLE__
#include "../Utilities/Util.hpp"

namespace PRIMITIVES2D
{

class Triangle
{
private:
	int x, y, position, escaleFactorX;
	void draw_at(char);
	void draw(char, char);
public:
	Triangle();
	Triangle(int);
	~Triangle();
	void update(char, char);	
};

}




#endif