#include "Vector2.h"

Vector2::Vector2(const float& x, const float& y)
	:
x(x),
y(y)
{
}

Vector2::~Vector2()
{
}

void Vector2::Set(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}