#pragma once
/****************************************************************************/
/*!
\file Material.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that contains material values
*/
/****************************************************************************/
#include "Texture.h"
#include "D3DColor.h"
/****************************************************************************/
/*!
Class Material:
\brief
contains material values
*/
/****************************************************************************/
class Material
{
public:
	Material(const Color& kAmbient = Color(), const Color& kDiffuse = Color(), const Color& kSpecular = Color(), const float& kShininess = 1, const Texture* texture = NULL);
	~Material();
	void SetTo(const Color& kAmbient, const Color& kDiffuse, const Color& kSpecular, const float kShininess, const Texture* texture);

	Color kAmbient;
	Color kDiffuse;
	Color kSpecular;
	float kShininess;
	Texture const* texture;
};