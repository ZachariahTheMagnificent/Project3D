#pragma once
#include "Object2D.h"
#include "Bullet2D.h"

class Gun2D : public Object2D
{
public:
	Gun2D();
	virtual ~Gun2D();

	virtual void Update(const double& deltaTime);
	virtual void DoCollisionWith(Object2D* obj);

	void Fire();
	void Reload();

private:
};

