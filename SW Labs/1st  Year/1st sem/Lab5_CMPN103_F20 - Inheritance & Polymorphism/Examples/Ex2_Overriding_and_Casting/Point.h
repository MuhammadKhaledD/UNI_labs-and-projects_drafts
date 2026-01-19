#pragma once

class Point
{
	double x,y;

public:
	Point(double X, double Y);
	double getX();
	double getY();
	void PrintInfo(); // prints the Point's data members: x,y
};
