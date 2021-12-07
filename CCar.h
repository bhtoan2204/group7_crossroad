#pragma once
#ifndef CCar_h
#define CCar_h
#include"CVEHICLE.h"
#include<iostream>
//#include <mmsystem.h>
using namespace std;

class CCar: public CVEHICLE
{
//private:
//	// cai nay moi object car deu co 
//	static const int height = 3;
//	static const int width = 9;
private:
	int _type;
	char** _car;
	void createCar(int i);
public:
	
	CCar(const Point& p, int _type, int _height, int _width);
	CCar(const CCar& car);
	CCar& operator=(const CCar& car);

	// tra ve mot doi tuong de ve
	char** shapeHevicle(/**/);

	// Ham am thanh
	void soundHorn();

	// Ham di chuyen
	void move();

	// ve con xe
	//void drawHevicle();

	~CCar();
};
#endif // !CCar_h


