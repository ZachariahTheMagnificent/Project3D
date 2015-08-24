#pragma once
#include "Vector2.h"
#include "Texture.h"

class Object2D
{
public:
	Object2D();
	virtual ~Object2D();
	virtual void Update(const double& deltaTime) = 0;
	virtual void DoCollisionWith(Object2D* obj) = 0;

	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float rotationalVelocity;
	float rotationalAcceleration;

	bool active;
	bool isUsed;

	Texture* image;
protected:
	void UpdatePosition(const double& deltaTime);
	void UpdateVelocity(const double& deltaTime);
};

