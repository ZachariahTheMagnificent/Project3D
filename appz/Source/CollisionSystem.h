#pragma once
#include "CollisionBody.h"
#include "MyContainer.h"

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();
	void Respond(CollisionBody* body1, CollisionBody* body2, Polygonn& poly1, Polygonn& poly2);
	void UpdateTo(const double& deltaTime, CollisionBody*const begin, CollisionBody*const end);
private:
	MyContainer<Contact> contactBuffer;

	unsigned contactBufferSize;
};