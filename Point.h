#pragma once
#ifndef Point_h
#define Point_h
#include<iostream>
using namespace std;

class Point
{
private:
	int _mX;
	int _mY;
public:
	Point();
	Point(int _mX, int _mY);
	Point& operator=(const Point& p);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);	
	~Point();

};
#endif // !Point_h


