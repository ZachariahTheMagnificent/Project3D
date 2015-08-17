#pragma once
#include "Light.h"

Light::Light(const Vector3& position, const Color& color, const float& power, const float& kC, const float& kL, const float& kQ)
	:
position(position),
color(color),
power(power),
kC(kC),
kL(kL),
kQ(kQ)
{
}

Light::~Light()
{
}

void Light::Set(const Vector3& position, const Color& color, const float& power, const float& kC, const float& kL, const float& kQ)
{
	this->position = position;
	this->color = color;
	this->power = power;
	this->kC = kC;
	this->kL = kL;
	this->kQ = kQ;
}