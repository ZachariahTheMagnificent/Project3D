#pragma once
#include "Factory.h"
#include "Bullet2D.h"
#include "Asteroid2D.h"
#include "EnemyShip2D.h"
#include "PlayerShip2D.h"
#include "Gun2D.h"
#include "ProductionLine.h"

class Object2DFactory : public Factory<Object2D>
{
public:
	enum OBJ_TYPE
	{
		BULLET,
		ASTEROID,
		PLAYERSHIP,
		ENEMYSHIP,
		GUN,
		TOTAL_TYPES
	};
	Object2DFactory();
	virtual ~Object2DFactory();
	
	virtual Object2D* GetInstance(unsigned type);
	virtual void UpdateAllObjects(const double& deltaTime);

protected:
	ProductionLine<Bullet2D> bulletProduction;
	ProductionLine<Asteroid2D> asteroidProduction;
	ProductionLine<PlayerShip2D> playerShipProduction;
	ProductionLine<EnemyShip2D> enemyShipProduction;
	ProductionLine<Gun2D> gunProduction;
};