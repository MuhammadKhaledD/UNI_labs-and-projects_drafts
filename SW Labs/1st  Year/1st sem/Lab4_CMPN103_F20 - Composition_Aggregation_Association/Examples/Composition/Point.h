#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	double x,y;
public:
	//Q1:After first run, comment the default constructor (in both Point.h and Point.cpp)
	//What happened? How to fix it?
	Point();
	Point(double a, double b);
	~Point();

	//Class setters and getters
	void setX(double a);
	double getX() const;
	void setY(double b);
	double getY() const;

	bool isOrigin() const; // true if the point is at (0,0), flase otherwise.
};

#endif