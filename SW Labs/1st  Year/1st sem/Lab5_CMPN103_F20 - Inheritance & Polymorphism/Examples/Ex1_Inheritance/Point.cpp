#include "Point.h"

#include <iostream>
using namespace std;

Point::Point(double X, double Y)
{
	x = X;
	y = Y;
	cout<<"\n ||| Point ("<<X<<", "<<Y<<") constructor is executed |||";
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

Point::~Point()
{
	cout<<"\n ~~~ Point ("<<x<<", "<<y<<") destructor is executed ~~~";
}
