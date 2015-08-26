#pragma once
#include "UIDisplays.h"
#include "Mesh.h"

class UIMesh : public UIDisplays
{
public:
	UIMesh();
	virtual ~UIMesh();

	virtual UIBox GetBoundingBox() const;
	virtual void Render(const Mtx44& projection) const;

	Mesh* mesh;
};