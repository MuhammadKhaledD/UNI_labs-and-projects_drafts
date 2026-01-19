#include "Point.h"
#include <iostream>
using namespace std;

//Default constructor
Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
	cout<<endl<<"Point ("<<x<<","<<y<<","<<z<<") is being constructed";
}

//Constructor with two arguments
Point::Point(double a, double b)
{
	x = a;
	y = b;
	z = 0;
	cout<<endl<<"Point ("<<x<<","<<y<<","<<z<<") is being constructed";
}

//Constructor with three arguments
Point::Point(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
	cout<<endl<<"Point ("<<x<<","<<y<<","<<z<<") is being constructed";
}

//Destructor
Point::~Point()
{
	cout<<endl<<"Point is being destructed";
}

