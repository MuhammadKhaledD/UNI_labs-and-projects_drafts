#include "Line.h"
#include <iostream>
using namespace std;

//Line Consrtuctor
// Note: No explicit calling to 'Start' and 'End' point constructors, constructors are called automatically
// Q1: when are these data members constructed?
Line::Line(double X1, double Y1,double X2, double Y2)//:Start(X1,Y1),End(X2,Y2)
{	//Q2: What alternative ways to initialize "Start" and "End" Points data members, other than the default way?
	//Q3: When would it be obligatory to use this alternative way?
	cout<<endl<<"Line Constructor is called";	
	cout<<endl<<"Setting Start and End Points coordinates";	
	Start.setX(X1);  //Q4:Can you do this : Start.x = X1; ? Why?
	Start.setY(Y1);
	End.setX(X2);
	End.setY(Y2);
}

//Line Desrtuctor 
//Q5: What other Destructors would be called impilicitly? In what sequence?
Line::~Line()
{
	cout<<endl<<"Line Destructor is called";	
}

//Sets the x-y coordinates of Line start Point
void Line::SetStart(double a, double b)
{
	Start.setX(a);
	Start.setY(b);
}

//Sets the x-y coordinates of Line end Point
void Line::SetEnd(double c, double d)
{
	End.setX(c);
	End.setY(d);
}

bool Line::PassByOrigin() const
{
	//see how outer class calls function of inner objects
	//It is Start.isOrigin() not Point.isOrigin()
	double slope = (End.getY() - Start.getY()) / (End.getX() - Start.getX());
	double intercept = Start.getY() - (slope * Start.getX());
	return (Start.isOrigin() || End.isOrigin() || intercept == 0);
}

