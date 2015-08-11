#include "D3DColor.h"

Color::Color(float r, float g, float b)
	:
r(r),
g(g),
b(b)
{
}

Color::~Color()
{
}

void Color::Set(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}