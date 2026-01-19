#ifndef _POINT_H
#define _POINT_H

class Point	//2D Point
{
private:
	double x,y;
public:
	Point(double a, double b);
	Point(const Point&);
	~Point();

	//Class setters and getters
	void setX(double a);
	double getX();
	void setY(double b);
	double getY();
	void print();
};

#endif