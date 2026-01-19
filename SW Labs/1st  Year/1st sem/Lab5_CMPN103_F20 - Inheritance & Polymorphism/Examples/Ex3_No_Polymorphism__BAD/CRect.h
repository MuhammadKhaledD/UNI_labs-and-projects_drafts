#pragma once

#include "CFigure.h"

class CRect : public CFigure  
{
protected:
	double m_dWidth, m_dLength; //protected members to be accessed directly by derived classes of CRect

	// CRect has more 2 data members inherited from CFigure:
	// 1- m_nID but inaccessible directly (only through public/protected functions)
	// 2- FigType which is accessible directly for sure. It's public!
	
public:
	CRect();
	~CRect();
	void ReadData();  // overriding function
	                  // CRect has 2 versions of ReadData()
	                  // 1- the one inherited from CFigure
	                  // 2- its own one (which hides the inherited version)
	void PrintArea(); // overriding function - same as above
};
