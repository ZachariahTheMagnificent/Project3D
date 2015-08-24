#pragma once
#include "Object2d.h"
#include "Killable.h"
#include "Gun2D.h"

class Ship2D : public Object2D, public Killable
{
public:
	Ship2D();
	virtual ~Ship2D();

	virtual void Update(const double& deltaTime);
	virtual void DoCollisionWith(Object2D* obj);
	virtual float GetHealth();
	virtual void GetDamaged(const float& damage);
	virtual bool IsDead();
	virtual void UponDeath();

	Gun2D* guns;
	float health;
};