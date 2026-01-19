#include "Point.h"
#include <iostream>
using namespace std;

//Class default constructor
Point::Point()
{
	setX(0);
	setY(0);
	cout<<endl<<"||| Point ("<<x<<","<<y<<") is being constructed |||";
}

//Non-default constructor
Point::Point(double a, double b)
{
	setX(a);
	setY(b);
	cout<<endl<<"||| Point ("<<x<<","<<y<<") is being constructed |||";
}

//Class Destructor
Point::~Point()
{
	cout<<endl<<"~ ~ ~ ~ Point ("<<x<<","<<y<<") is being destructed ~ ~ ~ ~\n";
}

//Class data members Setters and getter
void Point::setX(double a)
{
	x = a;
}

double Point::getX() const
{
	return x;
}

void Point::setY(double b)
{
	y = b;
}

double Point::getY() const
{
	return y;
}

bool Point::isOrigin() const
{
	return (x == 0 && y == 0);
}