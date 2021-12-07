#pragma once
#include "CANIMAL.h"

#define MAX_D_X 3
#define MAX_D_Y 9


extern char BattleField[MAX_X][MAX_Y];
extern char Dino[MAX_D_X][MAX_D_Y];

class CDINOSAUR : public CANIMAL
{
public:
	void Move();
	void Tell();
};

