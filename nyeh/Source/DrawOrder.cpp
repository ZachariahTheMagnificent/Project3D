#include "DrawOrder.h"
#include "Mesh.h"
/****************************************************************************/
/*!
\file DrawOrder.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
Contains DrawOrder which is a class used to help render objects in a scene in a hierarchical fashion
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Constructor for DrawOrder
\param name
		sets the name of the draw
\param geometry
		sets the geomery of the draw
\param material
		sets the material of the DrawOrder
\param parent
		sets the parent of the DrawOrder
\param enableLight
		bool that decides if the DrawOrder will have lighting
*/
/****************************************************************************/
DrawOrder::DrawOrder(Mesh* geometry, Material* material, DrawOrder* parent, bool enableLight)
	:
geometry(geometry),
material(material),
enableLight(enableLight),
parent(NULL)
{
	SetParentAs(parent);
}


void DrawOrder::SetTo(Mesh* geometry, Material* material, DrawOrder* parent, bool enableLight)
{
	this->geometry = geometry;
	this->material = material;
	this->enableLight = enableLight;
	SetParentAs(parent);
}

/****************************************************************************/
/*!
\brief
Default destructor. If it has a parent, it will remove itself from it's parent's children vector
*/
/****************************************************************************/
DrawOrder::~DrawOrder()
{
	if(parent)
	{
		for(std::vector<DrawOrder*>::iterator child = parent->children.begin(); child != parent->children.end(); ++child)
		{
			if(*child == this)
			{
				parent->children.erase(child);
				break;
			}
		}
	}
}
/****************************************************************************/
/*!
\brief
Returns the global position of the DrawOrder
*/
/****************************************************************************/
Vector3 DrawOrder::GetGlobalPosition() const
{
	return GetMatrix() * Vector3(0,0,0);
}
/****************************************************************************/
/*!
\brief
Sets the DrawOrder's parent and the new parent's children
\param parent
		the DrawOrder's new parent
*/
/****************************************************************************/
void DrawOrder::SetParentAs(DrawOrder* parent)
{
	if(parent)
	{
		for(std::vector<DrawOrder*>::iterator child = parent->children.begin(); child != parent->children.end(); ++child)
		{
			if(*child == this)
			{
				parent->children.erase(child);
				break;
			}
		}
	}
	this->parent = parent;
	if(parent)
	{
		parent->children.push_back(this);
	}
}
/****************************************************************************/
/*!
\brief
Returns the DrawOrder's(incomplete) modelTransform
*/
/****************************************************************************/
Mtx44 DrawOrder::GetModelTransform() const
{
	if(parent)
	{
		return parent->GetModelTransform() * transform.TranslationMatrix() * transform.RotationMatrix() * transform.ScalationMatrix();
	}
	return transform.TranslationMatrix() * transform.RotationMatrix() * transform.ScalationMatrix();
}
/****************************************************************************/
/*!
\brief
Returns the DrawOrder's complete modelTransform
*/
/****************************************************************************/
Mtx44 DrawOrder::GetMatrix() const
{
	Mtx44 modelTransform;
	if(parent)
	{
		modelTransform = parent->GetModelTransform();
	}
	else
	{
		modelTransform.SetToIdentity();
	}
	return modelTransform * transform.TranslationMatrix() * selfTransform.TranslationMatrix() * transform.RotationMatrix() * selfTransform.RotationMatrix() * transform.ScalationMatrix() * selfTransform.ScalationMatrix();
}
/****************************************************************************/
/*!
\brief
Returns the DrawOrder's parent
*/
/****************************************************************************/
DrawOrder* DrawOrder::GetParent() const
{
	return parent;
}
/****************************************************************************/
/*!
\brief
Returns the transformation of the DrawOrder as a translation matrix
*/
/****************************************************************************/
Mtx44 DrawOrder::GetTranslationMatrix() const
{
	Mtx44 translationMatrix;
	translationMatrix.SetToTranslation(GetGlobalPosition());
	return translationMatrix;
}
/****************************************************************************/
/*!
\brief
Returns the DrawOrder's rotationMatrix
*/
/****************************************************************************/
Mtx44 DrawOrder::GetRotationMatrix() const
{
	return transform.rotate.MatrixX() * transform.rotate.MatrixY() * transform.rotate.MatrixZ();
}
/****************************************************************************/
/*!
\brief
Returns the DrawOrder's scaleMatrix
*/
/****************************************************************************/
Mtx44 DrawOrder::GetScaleMatrix() const
{
	Mtx44 parentScale;
	if(parent)
	{
		parentScale = parent->GetScaleMatrix();
	}
	else
	{
		parentScale.SetToIdentity();
	}
	return transform.ScalationMatrix() * parentScale;
}

const std::vector<DrawOrder*>& DrawOrder::GetChildrenVector() const
{
	return children;
}