#include "UIMesh.h"

UIMesh::UIMesh()
	:
mesh(NULL)
{
}

UIMesh::~UIMesh()
{
}

UIBox UIMesh::GetBoundingBox() const
{
	return UIBox();
}

void UIMesh::Render(const Mtx44& projection) const
{
	if(active)
	{
		Mtx44 view;
		view.SetToIdentity();

		Material material;

		//mesh->Render(projection, view, transform.Matrix(), &material, false);
	}
}