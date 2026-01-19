#pragma once

#include "CFigure.h"
#include "Point.h"

class CRect : public CFigure  
{
private:
	Point UpperLeft, BottomRight;
	
public:
	CRect(int id, double x1, double y1, double x2, double y2);
	double CalcLength();
	void PrintInfo(); // prints the CRects's data members: 
	                  // data members inherited from CFigure: m_nID
	                  // plus UpperLeft and BottomRight information
	
	// Note that CRect now has 2 versions of void PrintInfo():
	// 1- the one inherited from CFigure
	// 2- its own one

	// Q: Does one of them hide the other one??

	// That is called function overriding.
	// CRect::PrintInfo() overrides CFigure::PrintInfo()

	// Q: Does CRect::PrintInfo() override Point::PrintInfo()?? why?

};
