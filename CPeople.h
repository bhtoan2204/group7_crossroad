#pragma once
#include <iostream>
#include <vector>
//#include "CANIMAL.h"
//#include "CVEHICLE.h"

short MAX_Y = 81;
short MAX_X = 25;

short MAX_People_Y = 5;
short MAX_People_X = 3;

short step = 4;

extern char BattleField[25][81];
extern char People[4][3];

using namespace std;

class CPEOPLE {
private:
	int x, y;
	bool checkValidPos(int x, int y);
	bool state;
public:
	CPEOPLE();
	int getX();
	int getY();
	void drawPeople();
	void setX(int x);
	void setY(int y);
	void setState(bool isDead);
	void Up();
	void Right();
	void Left();
	void Down();
	//bool isImpactAnimal(vector<CANIMAL*>& cAni);
	//bool isImpactVehicle(vector<CVEHICLE*>& CVehi);
	bool isFinish();
	bool isDead();
	~CPEOPLE() = default;
};



