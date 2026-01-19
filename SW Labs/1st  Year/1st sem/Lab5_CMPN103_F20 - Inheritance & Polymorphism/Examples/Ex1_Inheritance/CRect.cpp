
#include "CRect.h"
// Note: we don't need to include "CFigure.h" and "Point.h" here
// because they're included already in "CRect.h"
// which is included here

#include <iostream>
using namespace std;


CRect::CRect(int id, double x1, double y1, double x2, double y2)
	  : CFigure(id), UpperLeft(x1,y1), BottomRight(x2,y2) 
	  // Q: Must use initializer list. Why??
	  // Note the difference between calling the non-default constructor 
	  // of the base class and of the data member objects
{	
	cout<<"\n ||| CRect constructor is executed |||";

	// Q: Assume we don't have an initializing constructor for class CFigure
	// and we want to initialize m_nID with the passed id. Can we set it like that?

	// m_nID = id;

	// Uncomment the previous line. 
	// Does any problem occur? if yes, why and how to solve it?
}


double CRect::CalcLength()
{
	// cannot directly access the privates of the data member obj/ptr(s). Remember?
	return ( BottomRight.getX() - UpperLeft.getX() );
}


CRect::~CRect()
{
	cout<<"\n ~~~ CRect destructor is executed ~~~";
}

