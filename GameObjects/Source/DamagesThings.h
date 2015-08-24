#pragma once
#include "Killable.h"

class DamagesThings
{
public:
	DamagesThings();
	virtual ~DamagesThings();

	virtual void DoDamageTo(Killable* theKill) = 0;
};

