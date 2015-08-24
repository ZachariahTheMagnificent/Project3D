#pragma once
#include "Object2DFactory.h"
#include "Asteroid2D.h"

class AsteroidFactory : public Object2DFactory
{
public:
	AsteroidFactory();
	virtual ~AsteroidFactory();
	
	virtual Object2D* GetObject();
	virtual void IncreaseSize();
	virtual void UpdateAllObjects(const double& deltaTime);
	virtual unsigned GetCapacity();

	const unsigned sizeIncrease;
	Asteroid2D* begin;
	Asteroid2D* end;
};