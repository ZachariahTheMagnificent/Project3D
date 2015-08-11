#pragma once
#include "AABBTree.h"
#include "CollisionBody.h"

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();
	void Respond(CollisionBody* body1, CollisionBody* body2, Polygonn& poly1, Polygonn& poly2);
	void UpdateTo(const double& deltaTime, CollisionBody*const begin, CollisionBody*const end);
	void IncreaseBufferTo(const unsigned& size);
private:
	Contact* contactBuffer;

	unsigned contactBufferSize;
};