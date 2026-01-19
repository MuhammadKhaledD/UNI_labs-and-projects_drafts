#include "CRect.h"
#include <iostream>
using namespace std;


CRect::CRect(int id, double x1, double y1, double x2, double y2)
	  :CFigure(id),UpperLeft(x1,y1),BottomRight(x2,y2)
{	
	// Yes, Empty :D
}


double CRect::CalcLength()
{
	return ( BottomRight.getX() - UpperLeft.getX() );
}


void CRect::PrintInfo()
{
	cout << "\n== The CRect Information: ==";

	CFigure::PrintInfo();    // [function Reuse]: reuse the already written function (instead of using getters)
	// Q: Replace the the above line with the following line:
	// PrintInfo();
	// Does any problem occur? why?
	
	// Q: [Important Question] Is it a must to use scope resolution 
	// to call a base class fucntion inside the base class??
	// if no, when do we usually need it??

	cout<<"\nUpper Left Corner:";
	UpperLeft.PrintInfo();   // [function Reuse] instead of using getters

	cout<<"\nBottom Right Corner:";
	BottomRight.PrintInfo(); // [function Reuse] instead of using getters

	// Notice the difference between calling:
	// 1- a function from base class (through base "class" name then scope resolution :: ) 
	// 2- a function from data member obj/ptr (through obj/ptr name then dot/arrow operator)

	cout << endl;
}


