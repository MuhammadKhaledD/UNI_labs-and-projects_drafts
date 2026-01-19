#ifndef _CIRCLE_H
#define _CIRCLE_H
/*
The include gards "#ifndef" checks whether the given token has been #defined earlier 
in the file or in an included file; if not, it includes the code between 
it and the closing #else or, if no #else is present, #endif statement. 
#ifndef is often used to make header files idempotent by defining a token 
once the file has been included and checking that the token was not set at the top of that file.
To understand why not using the guards will cause a problem, check this link 
https://en.wikipedia.org/wiki/Include_guard 
*/

/*
*******[Important Note]*******:
You can create the class .h and .cpp quickly in visual studio by:
- Right click or project name in "Solution Explorer" 
- Add + Class
- press Add button
- choose the name of the class in "Class Name" and press Ok
You'll find the .h and .cpp created with default constructor and destructor
and with "#pragma once" which is one sentence but makes the same functionality of #ifndef, #define and #endif
*/

#include <iostream>
const double PI = 3.14;
using namespace std;

//Circle class Interface
//-----------------
//A class that implements a Circle
class Circle
{
	double radius; //Circle Radius
	double x,y; //Circle Center Point
public:
	//Notice that we do not need to pass an object of class Circle 
	//to the following function (as we did in the struct case)
	//Reason: These functions are already members of class Circle and has direct access to
	//        its data members.
	void init();
	void changeCenter(double a, double b);
	void setRadius(double newRad);
	double calcPerimeter();
	void printCircleData();
	bool isPoint();
	double calcArea();

};

#endif