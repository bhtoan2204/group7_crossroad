#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#define MAX_X 25
#define MAX_Y 81


class CANIMAL
{
	int mX, mY;
public:
	virtual void Move(int, int);
	virtual void Tell();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

