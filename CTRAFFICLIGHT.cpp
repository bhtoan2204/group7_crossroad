#include "CTRAFFICLIGHT.h"

bool CTRAFFICLIGHT::getLight()
{
	return value;
}

void CTRAFFICLIGHT::turnLight()
{
	value = !value;
}