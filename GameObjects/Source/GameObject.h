#pragma once
#include "Vector3.h"
#include "DrawOrder.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	float rotationalVelocity;
	float rotationalAcceleration;
	
	bool active;

	DrawOrder* image;
protected:
	void UpdatePosition(const double& deltaTime);
	void UpdateVelocity(const double& deltaTime);
};