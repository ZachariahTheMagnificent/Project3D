#pragma once
#include <vector>
#include "Transformation.h"
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
	bool enableLight;
	Mesh* geometry;
	Material* material;
	Transformation transform;
	//this transformation will only apply to the parent and not it's children
	Transformation selfTransform;

private:
	std::vector<DrawOrder*> children;
};