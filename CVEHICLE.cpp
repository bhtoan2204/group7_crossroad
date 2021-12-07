#include "CVEHICLE.h"

CVEHICLE::CVEHICLE(const Point& p, int _height, int _width)
{
	this->_p = p;
	this->_height = _height;
	this->_width = _width;
	this->_isOutMap = false;
}

CVEHICLE::CVEHICLE(const CVEHICLE& vehicle)
{
	this->_p = vehicle._p;
	this->_height = vehicle._height;
	this->_width = vehicle._width;
	this->_isOutMap = vehicle._isOutMap;
}

CVEHICLE& CVEHICLE::operator=(const CVEHICLE& vehicle)
{
	if (this != &vehicle)
	{
		this->_p = vehicle._p;
		this->_height = vehicle._height;
		this->_width = vehicle._width;
		this->_isOutMap = vehicle._isOutMap;
	}

	return *this;
}

bool CVEHICLE::isOutMap()
{
	return this->_isOutMap;
}

void CVEHICLE::outMap()
{
	this->_isOutMap = true;
}

int CVEHICLE::getHeight()
{
	return this->_height;
}

int CVEHICLE::getWidth()
{
	return this->_width;
}

Point CVEHICLE::getPosition()
{
	return this->_p;
}

void CVEHICLE::setX(int x)
{
	this->_p.setX(x);
}
void CVEHICLE::setY(int y)
{
	this->_p.setY(y);
}