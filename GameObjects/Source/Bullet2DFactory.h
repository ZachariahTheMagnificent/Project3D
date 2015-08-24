#pragma once
#include "Object2DFactory.h"
#include "Bullet2D.h"

class Bullet2DFactory : public Object2DFactory
{
public:
	Bullet2DFactory();
	virtual ~Bullet2DFactory();
	
	virtual Object2D* GetObject();
	virtual void IncreaseSize();
	virtual void UpdateAllObjects(const double& deltaTime);
	virtual unsigned GetCapacity();

private:
	const unsigned sizeIncrease;
	Bullet2D* begin;
	Bullet2D* end;
};