#ifndef _POINT_H
#define _POINT_H

class Point	//3D Point
{
private:
	double x, y, z;	
public:
	//Default constructor
	Point();	
	
	//Constructor with two arguments
	Point(double a, double b);		
	
	//Constructor with three arguments
	Point(double a, double b, double c);

	//Of course, you can add more functions here like:
	//setX, getX, setY, getY, setZ, ...etc.
	~Point();
};

#endif