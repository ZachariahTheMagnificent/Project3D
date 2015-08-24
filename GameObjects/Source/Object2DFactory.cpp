#pragma once
#include "Object2DFactory.h"

Object2DFactory::Object2DFactory()
	:
bulletProduction(100),
asteroidProduction(100),
playerShipProduction(10),
enemyShipProduction(10),
gunProduction(10)
{
}

Object2DFactory::~Object2DFactory()
{
}

Object2D* Object2DFactory::GetInstance(unsigned type)
{
	switch(type)
	{
	case BULLET:
		return bulletProduction.GetInstance();
		break;

	case ASTEROID:
		return asteroidProduction.GetInstance();
		break;

	case PLAYERSHIP:
		return playerShipProduction.GetInstance();
		break;

	case ENEMYSHIP:
		return enemyShipProduction.GetInstance();
		break;

	case GUN:
		return gunProduction.GetInstance();
		break;

	default:
		return NULL;
	}
}

void Object2DFactory::UpdateAllObjects(const double& deltaTime)
{
	for(Bullet2D* bullet = bulletProduction.GetBegin(); bullet != bulletProduction.GetEnd(); ++bullet)
	{
		if(!bullet->active)
		{
			bullet->Update(deltaTime);
		}
	}

	for(Asteroid2D* asteroid = asteroidProduction.GetBegin(); asteroid != asteroidProduction.GetEnd(); ++asteroid)
	{
		if(!asteroid->active)
		{
			asteroid->Update(deltaTime);
		}
	}

	for(PlayerShip2D* playerShip = playerShipProduction.GetBegin(); playerShip != playerShipProduction.GetEnd(); ++playerShip)
	{
		if(!playerShip->active)
		{
			playerShip->Update(deltaTime);
		}
	}

	for(EnemyShip2D* enemyShip = enemyShipProduction.GetBegin(); enemyShip != enemyShipProduction.GetEnd(); ++enemyShip)
	{
		if(!enemyShip->active)
		{
			enemyShip->Update(deltaTime);
		}
	}

	for(Gun2D* gun = gunProduction.GetBegin(); gun != gunProduction.GetEnd(); ++gun)
	{
		if(!gun->active)
		{
			gun->Update(deltaTime);
		}
	}
}