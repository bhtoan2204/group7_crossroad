#pragma once
#ifndef CTruck_h
#define CTruck_h
#include"CVEHICLE.h"
#include<iostream>
//#include <mmsystem.h>
using namespace std;

class CTruck : public CVEHICLE
{
	//private:
	//	// cai nay moi object car deu co 
	//	static const int height = 3;
	//	static const int width = 9;
private:
	int _type;
	char** _truck;
	void createTruck(int i);
public:

	CTruck(const Point& p, int _type, int _height, int _width);
	CTruck(const CTruck& truck);
	CTruck& operator=(const CTruck& truck);

	// tra ve mot doi tuong de ve
	char** shapeHevicle(/**/);

	// Ham am thanh
	void soundHorn();

	// Ham di chuyen
	void move();

	// ve con xe
	//void drawHevicle();

	~CTruck();
};
#endif // !CTruck_h


