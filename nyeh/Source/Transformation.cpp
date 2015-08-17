#include "Transformation.h"

Transformation::Transformation()
{
	scale.Set(1,1,1);
}

Transformation::~Transformation()
{
}

Mtx44 Transformation::TranslationMatrix() const
{
	Mtx44 translation;
	translation.SetToTranslation(translate);

	return translation;
}

Mtx44 Transformation::RotationMatrix() const
{
	Mtx44 rotation, reorientate;
	reorientate.SetToTranslation(pivot);
	rotation = reorientate.GetInverse() * rotate.MatrixX() * rotate.MatrixY() * rotate.MatrixZ() * reorientate;

	return rotation;
}

Mtx44 Transformation::ScalationMatrix() const
{
	Mtx44 scalation;
	scalation.SetToScale(scale.x,scale.y,scale.z);

	return scalation;
}

Mtx44 Transformation::Matrix() const
{
	Mtx44 translation, rotation, scalation, reorientate;
	translation.SetToTranslation(translate);
	reorientate.SetToTranslation(pivot);
	scalation.SetToScale(scale.x,scale.y,scale.z);
	rotation = reorientate.GetInverse() * rotate.MatrixX() * rotate.MatrixY() * rotate.MatrixZ() * reorientate;

	return TranslationMatrix() * RotationMatrix() * ScalationMatrix();
}