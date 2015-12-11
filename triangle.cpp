#include <iostream>
#include <ostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "triangle.hpp"

void PRIMITIVES2D::Triangle::draw_at(char c='#')
{
	for( register unsigned int offset=position*escaleFactorX; offset>0; offset-- )
	{
		std::cout << c;
	}
}

void PRIMITIVES2D::Triangle::draw(char c1='\\', char c2='_')
{
	for( register unsigned int _y=0; _y<y; _y++ )
	{	
		draw_at(c1);
	
		for( register unsigned int _x=( _y*(escaleFactorX+escaleFactorX) ); _x<( x*(escaleFactorX+escaleFactorX) ); _x-- )
		{
			std::cout << '.';
		}

		draw_at(c2);

		this->position--;
		std::cout << std::endl;
	}
	// Triangle();
}

PRIMITIVES2D::Triangle::Triangle()
{
	this->x = this->y = this->position = 15;
	this->escaleFactorX = (this->position/5)-1;
}

PRIMITIVES2D::Triangle::Triangle( int pos )
{
	this->x = this->y = 15;
	this->position = pos;
	this->escaleFactorX = (this->position/5)-1;
}

PRIMITIVES2D::Triangle::~Triangle(){}

void PRIMITIVES2D::Triangle::update(char c1='\\', char c2='_')
{
	draw(c1, c2);
}
