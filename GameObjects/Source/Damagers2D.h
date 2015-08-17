#pragma once
#include "Killable.h"

class Damagers
{
public:
	Damagers();
	~Damagers();

	void DoDamageTo(Killable* theKill);

protected:
	float damage;
};

