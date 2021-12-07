#pragma once
#include "CANIMAL.h"

#define MAX_B_X 3
#define MAX_B_Y 14

extern char BattleField[MAX_X][MAX_Y];
extern char Bird[MAX_B_X][MAX_B_Y];

class CBIRD : public CANIMAL
{
public:
	void Move();
	void Tell();
};
