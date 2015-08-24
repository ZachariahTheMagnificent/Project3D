#pragma once

class Killable
{
public:
	Killable();
	virtual ~Killable();

	virtual float GetHealth() = 0;
	virtual void GetDamaged(const float& damage) = 0;
	virtual bool IsDead() = 0;
	virtual void UponDeath() = 0;
};

