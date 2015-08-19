#pragma once

/****************************************************************************/
/*!
Class Vector2:
\brief
Stores UV coordinates
*/
/****************************************************************************/
class Vector2
{
public:
	Vector2(const float& x = 0, const float& y = 0);
	~Vector2();
	void Set(const float& x, const float& y);

	Vector2 operator-(const Vector2& vec) const;

	float x, y;
};