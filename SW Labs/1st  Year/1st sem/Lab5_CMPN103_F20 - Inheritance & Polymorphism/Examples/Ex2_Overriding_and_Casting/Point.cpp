#include "Point.h"

#include <iostream>
using namespace std;

Point::Point(double X, double Y)
{
	x = X;
	y = Y;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

void Point::PrintInfo()
{
	cout<<" X="<<x<<" Y="<<y;
}

