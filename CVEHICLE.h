#pragma once
#ifndef CHEVICLE_H
#define CHEVICLE_H

#include<iostream>
#include"Point.h"
using namespace std;

#define HEIGTH_HEVICLE 3
#define WIDTH_HEVICLE 9 // 8 + 1 cho mot ket thuc chuoi


class CVEHICLE
{
protected:
	int _height;
	int _width;
	bool _isOutMap; // kiem tra no ra khoi map chua
	Point _p;
public:

	CVEHICLE() = default;
	CVEHICLE(const Point& p, int _height, int _width);
	CVEHICLE(const CVEHICLE& vehicle);
	CVEHICLE& operator=(const CVEHICLE& vehicle);

	// kiem tra co ra khoi duong dua chua ??
	bool isOutMap();
	void outMap();

	// lay do dai va do rong cua mot car
	int getHeight();
	int getWidth();
	
	// get position
	Point getPosition();

	// thiet lap lai toa do
	void setX(int x);
	void setY(int y);

	// tra ve mot doi tuong de ve
	virtual char** shapeHevicle(/**/) = 0;

	// ham ve 
	//virtual void drawHevicle(const Point& p) = 0;

	// Ham am thanh
	virtual void soundHorn() = 0;

	// Ham di chuyen
	virtual void move() = 0;

	virtual ~CVEHICLE() = default;
};

#endif // !CHEVICLE_H

