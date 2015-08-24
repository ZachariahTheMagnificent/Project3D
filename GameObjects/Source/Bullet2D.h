#pragma once
#include "Object2D.h"
#include "DamagesThings.h"

class Bullet2D : public Object2D, public DamagesThings
{
public:
	Bullet2D();
	virtual ~Bullet2D();

	virtual void Update(const double& deltaTime);
	virtual void DoCollisionWith(Object2D* obj);
	virtual void DoDamageTo(Killable* theKill);

private:
	float damage;
};