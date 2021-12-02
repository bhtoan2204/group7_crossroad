#pragma once
#include <iostream>

short MAX_Width = 81;
short MAX_Height = 25;

short MAX_People_Width = 5;
short MAX_People_Height = 3;

short step = 3;

extern char BattleField[25][81];
extern char People[4][3];

class CPeople {
private:
	int x, y;
	bool checkValidPosition;
	bool state;
public:
	CPeople();
	int getX();
	int getY();
	bool checkValidPosition(int x, int y);
	void drawPeople();
	void setX(int x);
	void setY(int y);
	void setState(bool isDead);
	void Up();
	void Right();
	void Left();
	void Down();
	/*bool isImpactAnimal(CANIMAL cAni[]);
	bool isImpactVehicle(CVEHICLE CVehi[]);*/
	bool isFinish();
	bool isDead();
	~CPeople() = default;
};

