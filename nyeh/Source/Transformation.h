#pragma once
#include "Rotation.h"
/****************************************************************************/
/*!
Struct Transformation:
\brief
Used to handle and store the values of translate, rotate and scale for use in transformations
*/
/****************************************************************************/
class Transformation
{
public:
	Transformation();
	~Transformation();

	Mtx44 TranslationMatrix() const;
	Mtx44 RotationMatrix() const;
	Mtx44 ScalationMatrix() const;
	Mtx44 Matrix() const;

	Vector3 translate;
	Rotation rotate;
	Vector3 scale;
	Vector3 pivot;
};