#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
	this->extreme = true;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	this->extreme = true;
}

Point::~Point()
{
}

void Point::setExtreme(bool extreme)
{
	this->extreme = extreme;
}

bool Point::getExtreme()
{
	return this->extreme;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

double Point::getX()
{
	return this->x;
}

double Point::getY()
{
	return this->y;
}