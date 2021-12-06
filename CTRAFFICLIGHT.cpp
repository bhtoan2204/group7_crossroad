#include "CTRAFFICLIGHT.h"

CTRAFFICLIGHT::CTRAFFICLIGHT() :light(true) {}

bool CTRAFFICLIGHT::getLight() { return light; }

void CTRAFFICLIGHT::turnLight() { light = !light; }