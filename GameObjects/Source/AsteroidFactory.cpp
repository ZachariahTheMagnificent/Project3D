#include "AsteroidFactory.h"

AsteroidFactory::AsteroidFactory(void)
	:
begin(NULL),
end(NULL),
sizeIncrease(100)
{
}


AsteroidFactory::~AsteroidFactory(void)
{
	if(begin)
	{
		delete [] begin;
		begin = NULL;
		end = NULL;
	}
}

void AsteroidFactory::UpdateAllObjects(const double& deltaTime)
{
	for(Asteroid2D* asteroid = begin; asteroid != end; ++asteroid)
	{
		if(!asteroid->active)
		{
			asteroid->Update(deltaTime);
		}
	}
}

Object2D* AsteroidFactory::GetObject()
{
	for(Asteroid2D* asteroid = begin; asteroid != end; ++asteroid)
	{
		if(!asteroid->active)
		{
			return asteroid;
		}
	}

	IncreaseSize();
	
	return begin + GetCapacity();
}

void AsteroidFactory::IncreaseSize()
{
	const unsigned oldCapacity = GetCapacity();
	const unsigned newCapacity = oldCapacity + sizeIncrease;

	Asteroid2D* buffer = new Asteroid2D[newCapacity];

	if(begin)
	{
		//transfer the previous asteroid data to the new memory
		memcpy(buffer, begin, oldCapacity);

		delete [] begin;
		begin = NULL;
		end = NULL;
	}

	begin = buffer;
	end = buffer + newCapacity;
}

unsigned AsteroidFactory::GetCapacity()
{
	return end - begin;
}