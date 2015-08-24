#pragma once
#include "Factory.h"
#include "GameObject.h"

class SpawnsObjects
{
public:
	SpawnsObjects();
	virtual ~SpawnsObjects();

	virtual void SetFactory(Factory* factory) = 0;
	virtual void SpawnObject() = 0;
	virtual void SpawnObjects(const unsigned& quantity) = 0;
};