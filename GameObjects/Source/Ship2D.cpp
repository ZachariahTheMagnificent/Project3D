#include "Ship2D.h"

Ship2D::Ship2D()
	:
guns(NULL),
health(100)
{
}

Ship2D::~Ship2D()
{
}

void Ship2D::Update(const double& deltaTime)
{
	UpdateVelocity(deltaTime);
	UpdatePosition(deltaTime);
}

void Ship2D::DoCollisionWith(Object2D* obj)
{
}

float Ship2D::GetHealth()
{
	return health;
}

void Ship2D::GetDamaged(const float& damage)
{
	health -= damage;
}

bool Ship2D::IsDead()
{
	return health <= 0;
}

void Ship2D::UponDeath()
{
}