#pragma once
#include "Mtx44.h"

/****************************************************************************/
/*!
Struct Rotation:
\brief
Used to handle and keep rotation values
*/
/****************************************************************************/
class Rotation
{
public:
	Rotation(const float& yaw = 0, const float& pitch = 0, const float& roll = 0);
	~Rotation();

	void Set(const float& yaw, const float& pitch, const float& roll);
	void capValues();

	Mtx44 MatrixX() const;
	Mtx44 MatrixY() const;
	Mtx44 MatrixZ() const;

	Rotation& operator=(const Rotation& rotate);
	Rotation& operator+=(const Rotation& rotate);
	Rotation operator+(const Rotation& rotate);
	Rotation operator-(const Rotation& rotate);

	float yaw;
	float pitch;
	float roll;
};