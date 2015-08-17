#include "Rotation.h"

Rotation::Rotation(const float& yaw, const float& pitch, const float& roll)
{
	Set(yaw, pitch, roll);
}

Rotation::~Rotation()
{
}

void Rotation::capValues()
{
	yaw = fmod(yaw,360.0f);
	pitch = fmod(pitch,360.0f);
	roll = fmod(roll,360.0f);
}

void Rotation::Set(const float& yaw, const float& pitch, const float& roll)
{
	this->yaw = yaw;
	this->pitch = pitch;
	this->roll = roll;
}

Mtx44 Rotation::MatrixX() const
{
	Mtx44 matrixYaw;

	matrixYaw.SetToRotation(yaw,0.0f,1.0f,0.0f);

	return matrixYaw;
}

Mtx44 Rotation::MatrixY() const
{
	Mtx44 matrixPitch;

	matrixPitch.SetToRotation(pitch,1.0f,0.0f,0.0f);

	return matrixPitch;
}

Mtx44 Rotation::MatrixZ() const
{
	Mtx44 matrixRoll;

	matrixRoll.SetToRotation(roll,0.0f,0.0f,1.0f);

	return matrixRoll;
}

Rotation& Rotation::operator=(const Rotation& rotate)
{
	yaw = rotate.yaw;
	pitch = rotate.pitch;
	roll = rotate.roll;

	return *this;
}

Rotation& Rotation::operator+=(const Rotation& rotate)
{
	*this = *this + rotate;
	return *this;
}

Rotation Rotation::operator+(const Rotation& rotate)
{
	return Rotation(yaw + rotate.yaw, pitch + rotate.pitch, roll + rotate.roll);
}