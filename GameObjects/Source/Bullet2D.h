#pragma once
#include "Object2D.h"
#include "Damagers2D.h"

class Bullet2D : public Damagers, public Object2D
{
public:
	Bullet2D();
	~Bullet2D();

private:
	virtual void Update(const double& deltaTime);
	virtual void DoCollisionWith(Object2D* obj);
};