#include "Point.h"
Point::Point()
{
	this->_mX = 0;
	this->_mY = 0;
}

Point::Point(int _mX, int _mY)
{
	this->_mX = _mX;
	this->_mY = _mY;
}

Point& Point::operator=(const Point& p)
{

	if (this != &p)
	{
		this->_mX = p._mX;
		this->_mY = p._mY;
	}
	return *this;
}

int Point::getX()
{
	return this->_mX;
}

int Point::getY()
{
	return this->_mY;
}

void Point::setX(int x)
{
	this->_mX = x;
}

void Point::setY(int y)
{
	this->_mY = y;
}

Point::~Point()
{}