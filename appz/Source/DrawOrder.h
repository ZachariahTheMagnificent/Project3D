#pragma once
#include <vector>
#include "MatrixStack.h"
#include "Material.h"
#include "Mesh.h"
/****************************************************************************/
/*!
\file DrawOrder.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
Contains DrawOrder which is a class used to help render objects in a scene in a hierarchical fashion and struts like rotation to keep rotation values and transforms to keep all translate, rotate and scale values
*/
/****************************************************************************/

/****************************************************************************/
/*!
Struct Rotation:
\brief
Used to handle and keep rotation values
*/
/****************************************************************************/
struct Rotation
{
	float yaw;
	float pitch;
	float roll;
	void capValues()
	{
		yaw = fmod(yaw,360.0f);
		pitch = fmod(pitch,360.0f);
		roll = fmod(roll,360.0f);
	}
	void Set(const float yaw, const float pitch, const float roll)
	{
		this->yaw = yaw;
		this->pitch = pitch;
		this->roll = roll;
	}

	Mtx44 MatrixX() const
	{
		Mtx44 matrixYaw;

		matrixYaw.SetToRotation(yaw,0.0f,1.0f,0.0f);

		return matrixYaw;
	}

	Mtx44 MatrixY() const
	{
		Mtx44 matrixPitch;

		matrixPitch.SetToRotation(pitch,1.0f,0.0f,0.0f);

		return matrixPitch;
	}

	Mtx44 MatrixZ() const
	{
		Mtx44 matrixRoll;

		matrixRoll.SetToRotation(roll,0.0f,0.0f,1.0f);

		return matrixRoll;
	}

	Rotation(const float yaw = 0, const float pitch = 0, const float roll = 0)
	{
		Set(yaw, pitch, roll);
	}

	void operator=(Rotation rotate)
	{
		yaw = rotate.yaw;
		pitch = rotate.pitch;
		roll = rotate.roll;
	}

	void operator+=(Rotation rotate)
	{
		yaw += rotate.yaw;
		pitch += rotate.pitch;
		roll += rotate.roll;
	}

	void operator+(Rotation rotate)
	{
		Rotation newRotate;

		newRotate = *this;
		newRotate += rotate;
	}
};
/****************************************************************************/
/*!
Struct Transformation:
\brief
Used to handle and store the values of translate, rotate and scale for use in transformations
*/
/****************************************************************************/
struct Transformation
{
	Vector3 translate;
	Rotation rotate;
	Vector3 scale;
	Vector3 pivot;

	Transformation()
	{
		scale.Set(1,1,1);
	}
	Mtx44 TranslationMatrix() const
	{
		Mtx44 translation;
		translation.SetToTranslation(translate);

		return translation;
	}
	Mtx44 RotationMatrix() const
	{
		Mtx44 rotation, reorientate;
		reorientate.SetToTranslation(pivot);
		rotation = reorientate.GetInverse() * rotate.MatrixX() * rotate.MatrixY() * rotate.MatrixZ() * reorientate;

		return rotation;
	}
	Mtx44 ScalationMatrix() const
	{
		Mtx44 scalation;
		scalation.SetToScale(scale.x,scale.y,scale.z);

		return scalation;
	}
	Mtx44 Matrix() const
	{
		Mtx44 translation, rotation, scalation, reorientate;
		translation.SetToTranslation(translate);
		reorientate.SetToTranslation(pivot);
		scalation.SetToScale(scale.x,scale.y,scale.z);
		rotation = reorientate.GetInverse() * rotate.MatrixX() * rotate.MatrixY() * rotate.MatrixZ() * reorientate;

		return TranslationMatrix() * RotationMatrix() * ScalationMatrix();
	}
};
/****************************************************************************/
/*!
Class DrawOrder:
\brief
Used to help render objects in a scene in a hierarchical fashion
*/
/****************************************************************************/
class DrawOrder
{
public:
	DrawOrder(Mesh* geometry = NULL, Material* material = NULL, DrawOrder* parent = NULL, bool enableLight = false);
	~DrawOrder();
	void SetTo(Mesh* geometry = NULL, Material* material = NULL, DrawOrder* parent = NULL, bool enableLight = false);
	Mtx44 GetMatrix() const;
	Mtx44 GetTranslationMatrix() const;
	Mtx44 GetRotationMatrix() const;
	Mtx44 GetScaleMatrix() const;
	Vector3 GetGlobalPosition() const;
	DrawOrder* GetParent() const;
	void SetParentAs(DrawOrder* parent);
	Mtx44 GetModelTransform() const;
	const std::vector<DrawOrder*>& GetChildrenVector() const;

	DrawOrder* parent;
	unsigned drawMode;
	bool enableLight;
	Mesh* geometry;
	Material* material;
	Transformation transform;
	//this transformation will only apply to the parent and not it's children
	Transformation selfTransform;

private:
	std::vector<DrawOrder*> children;
};