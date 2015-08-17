#pragma once
/****************************************************************************/
/*!
\file Light.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that contains light values
*/
/****************************************************************************/
#include "D3DColor.h"
#include "Vector3.h"
/****************************************************************************/
/*!
Struct Light:
\brief
contains light values
*/
/****************************************************************************/
class Light
{
public:
	enum LIGHT_TYPE
	{
		LIGHT_POINT = 0,
		LIGHT_DIRECTIONAL,
		LIGHT_SPOT,
	};

	Light(const Vector3& position = Vector3(), const Color& color = Color(), const float& power = 1.0f, const float& kC = 1.0f, const float& kL = 0.01, const float& kQ = 0.001);
	~Light();
	void Set(const Vector3& position, const Color& color, const float& power, const float& kC, const float& kL, const float& kQ);

	Vector3 position;
	Color color;
	float power;
	float kC, kL, kQ;
	LIGHT_TYPE type;
	Vector3 spotDirection;
	float cosCutoff;
	float cosInner;
	float exponent;
};