#pragma once

// Note: we include "CFigure.h" and "Point.h" 
// because we will use them inside class CRect
#include "CFigure.h"
#include "Point.h"

// CRect "is a" CFigure (inheritance) and "has" 2 points (compositon).

class CRect : public CFigure  // Don't forget "public", if you want it public inheritance
	                          // because the default inheritance type is: "private"
{
private:
	//new members in the derived class
	Point UpperLeft, BottomRight;

	// Now, CRect has 3 data members: 
	// 1- m_nID (inherited from CFigure but not accessible directly)
	// 2- UpperLeft Point,  3- BottomRight Point
	
public:
	// Note that the initializing constructor takes an "id" too
	// to initialize the inherited m_nID
	CRect(int id, double x1, double y1, double x2, double y2);
	double CalcLength();
	~CRect();

	//Q: Do we need to add setID and getID again in CRect??
};
