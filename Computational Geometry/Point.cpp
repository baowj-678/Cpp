#ifndef _POINT_
#define _POINT_

/**
* @description: 点类
* @param x: 点的横坐标
* @param y: 点的纵坐标
* @param extrem: 是否是凸包
*/
class Point
{
public:
	Point();
	Point(double x, double y);
	~Point();
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	void setExtreme(bool extreme);
	bool getExtreme();


private:
	double x;
	double y;
	bool extreme;

};

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
#endif // !_POINT_
