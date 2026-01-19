#include "Point.h"
#include <iostream>
using namespace std;


Point::Point(double a, double b)
{
	x = a;
	y = b;
	cout<<endl<<"||| Point ("<<x<<","<<y<<") is being constructed |||";
}
Point::Point(const Point& P)
{
    //copy constructor is called when an object is bypassed by vlaue or copy assignement (i.e. P1=P2;)
	//when an object is bypassed by value to a function a new object is created and connstructed and in this case 
	//the copy constructor is called instead of the convential default constructor
	//we will discuss copy constructor during the next labs and sections in details
	x = P.x;
	y = P.y;
	cout<<endl<<"||| A new Point ("<<x<<","<<y<<") is being constructed via copy constructor|||";
}

Point::~Point()
{
	cout<<endl<<"~ ~ ~ ~ Point ("<<x<<","<<y<<") is being destructed ~ ~ ~ ~\n";
}

void Point::setX(double a)
{
	x = a;
}

double Point::getX()
{
	return x;
}

void Point::setY(double b)
{
	y = b;
}

double Point::getY()
{
	return y;
}

void Point::print()
{
	cout<<endl<<"Print Point ("<<x<<","<<y<<")\n";
}
