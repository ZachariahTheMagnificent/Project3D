#include "Bullet2DFactory.h"
#include "Bullet2D.h"

Bullet2DFactory::Bullet2DFactory()
	:
begin(NULL),
end(NULL),
sizeIncrease(100)
{
}

Bullet2DFactory::~Bullet2DFactory()
{
	if(begin)
	{
		delete [] begin;
		begin = NULL;
		end = NULL;
	}
}

void Bullet2DFactory::UpdateAllObjects(const double& deltaTime)
{
	for(Bullet2D* bullet = begin; bullet != end; ++bullet)
	{
		if(!bullet->active)
		{
			bullet->Update(deltaTime);
		}
	}
}

Object2D* Bullet2DFactory::GetObject()
{
	for(Bullet2D* bullet = begin; bullet != end; ++bullet)
	{
		if(!bullet->active)
		{
			return bullet;
		}
	}

	IncreaseSize();
	
	return begin + GetCapacity();
}

void Bullet2DFactory::IncreaseSize()
{
	const unsigned oldCapacity = GetCapacity();
	const unsigned newCapacity = oldCapacity + sizeIncrease;

	Bullet2D* buffer = new Bullet2D[newCapacity];

	if(begin)
	{
		//transfer the previous bullet data to the new memory
		memcpy(buffer, begin, oldCapacity);

		delete [] begin;
		begin = NULL;
		end = NULL;
	}

	begin = buffer;
	end = buffer + newCapacity;
}

unsigned Bullet2DFactory::GetCapacity()
{
	return end - begin;
}