#pragma once
#include "Object2d.h"
#include "Killable.h"
#include "DamagesThings.h"

class Asteroid2D : public Object2D, public DamagesThings, public Killable
{
public:
	Asteroid2D();
	virtual ~Asteroid2D();

	virtual void Update(const double& deltaTime);
	virtual void DoCollisionWith(Object2D* obj);
	virtual void DoDamageTo(Killable* theKill);
	virtual float GetHealth();
	virtual void GetDamaged(const float& damage);
	virtual bool IsDead();
	virtual void UponDeath();

	float health;
	float damage;
};