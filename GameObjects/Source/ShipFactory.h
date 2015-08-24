#pragma once
#include "Object2DFactory.h"
#include "EnemyShip2D.h"

class ShipFactory : public Object2DFactory
{
public:
	ShipFactory();
	virtual ~ShipFactory();
	
	virtual Object2D* GetObject();
	virtual void IncreaseSize();
	virtual void UpdateAllObjects(const double& deltaTime);
	virtual unsigned GetCapacity();

private:
	const unsigned sizeIncrease;
	EnemyShip2D* begin;
	EnemyShip2D* end;
};