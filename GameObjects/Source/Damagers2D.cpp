#include "Damagers2D.h"
#include "Killable.h"

Damagers::Damagers()
{
}

Damagers::~Damagers()
{
}

void Damagers::DoDamageTo(Killable* theKill)
{
	theKill->GetDamaged(damage);
}