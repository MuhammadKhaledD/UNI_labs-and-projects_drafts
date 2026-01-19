#ifndef _LINE_H
#define _LINE_H

// Should include the header file "Point.h"
#include "Point.h"

class Line
{
// Line consists of two points: "Start" and "End" points.
private:
	Point Start;
	Point End;
public:
	//Line Constructor
	Line(double X1, double Y1,double X2, double Y2);
	~Line();

	//Setters to set start and end points coordinates.
	void SetStart(double a, double b);
	void SetEnd(double c, double d);

	bool PassByOrigin() const; //true if the line passes by the origin
};

#endif