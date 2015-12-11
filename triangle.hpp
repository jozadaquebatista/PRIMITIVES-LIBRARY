#include <iostream>
#include <ostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

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
