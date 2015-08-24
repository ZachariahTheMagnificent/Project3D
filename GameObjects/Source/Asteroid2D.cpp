#include "Asteroid2D.h"

Asteroid2D::Asteroid2D()
	:
health(100),
damage(20)
{
	velocity.Set(1, 0);
}

Asteroid2D::~Asteroid2D()
{
}

void Asteroid2D::Update(const double& deltaTime)
{
	UpdatePosition(deltaTime);
}

void Asteroid2D::DoCollisionWith(Object2D* obj)
{
	Killable* killable = dynamic_cast<Killable*>(obj);
	if(killable)
	{
		DoDamageTo(killable);
		if(killable->IsDead())
		{
			killable->UponDeath();
		}
	}
}

void Asteroid2D::DoDamageTo(Killable* theKill)
{
	theKill->GetDamaged(damage);
}

float Asteroid2D::GetHealth()
{
	return health;
}

void Asteroid2D::GetDamaged(const float& damage)
{
	health -= damage;
}

bool Asteroid2D::IsDead()
{
	return health <= 0;
}

void Asteroid2D::UponDeath()
{
	active = false;
}