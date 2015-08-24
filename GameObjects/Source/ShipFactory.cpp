#include "ShipFactory.h"

ShipFactory::ShipFactory(void)
	:
begin(NULL),
end(NULL),
sizeIncrease(100)
{
}


ShipFactory::~ShipFactory(void)
{
	if(begin)
	{
		delete [] begin;
		begin = NULL;
		end = NULL;
	}
}

void ShipFactory::UpdateAllObjects(const double& deltaTime)
{
	for(EnemyShip2D* enemyShip = begin; enemyShip != end; ++enemyShip)
	{
		if(!enemyShip->active)
		{
			enemyShip->Update(deltaTime);
		}
	}
}

Object2D* ShipFactory::GetObject()
{
	for(EnemyShip2D* enemyShip = begin; enemyShip != end; ++enemyShip)
	{
		if(!enemyShip->active)
		{
			return enemyShip;
		}
	}

	IncreaseSize();
	
	return begin + GetCapacity();
}

void ShipFactory::IncreaseSize()
{
	const unsigned oldCapacity = GetCapacity();
	const unsigned newCapacity = oldCapacity + sizeIncrease;

	EnemyShip2D* buffer = new EnemyShip2D[newCapacity];

	if(begin)
	{
		//transfer the previous ship data to the new memory
		memcpy(buffer, begin, oldCapacity);

		delete [] begin;
		begin = NULL;
		end = NULL;
	}

	begin = buffer;
	end = buffer + newCapacity;
}

unsigned ShipFactory::GetCapacity()
{
	return end - begin;
}