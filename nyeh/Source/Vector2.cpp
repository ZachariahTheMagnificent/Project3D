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

Vector2 Vector2::operator+(const Vector2& vec) const
{
	return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
	return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator*(const float multiplier) const
{
	return Vector2(x * multiplier, y * multiplier);
}

Vector2 Vector2::operator/(const float divider) const
{
	return Vector2(x / divider, y / divider);
}

const Vector2& Vector2::operator+=(const Vector2& vec)
{
	x += vec.x;
	y += vec.y;

	return *this;
}

const Vector2& Vector2::operator-=(const Vector2& vec)
{
	x -= vec.x;
	y -= vec.y;

	return *this;
}