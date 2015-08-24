#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

bool Event::IsActive()
{
	return trigger->HasTriggered();
}