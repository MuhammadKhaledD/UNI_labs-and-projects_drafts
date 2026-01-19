#pragma once

#include "CRect.h"// Here we use only CRect, so include it

// Note that this example has "multi-level" inheritance:
// CSquare --> CRect --> CFigure
// so CSquare inherted members from Both CRect (parent) and CFigure (grandparent)

class CSquare : public CRect  // we don't write ", public CFigure", 
	                          // CSquare indirectly inherites it through CRect.
{
	// CSquare has 2 data members inherited from parent class "CRect":
	// 1- m_dWidth, 2- m_dLength: accessible directly in CSquare because they're "protected" in CRect

	// It also has 1 data members inherited "indirectly" from grand-parent class "CFigure":
	// 3- m_nID but inaccessible directly because it's private in CFigure 
	//              (accessible only through public/protected functions)
	
public:
	virtual void ReadData();
	virtual void PrintArea();
	virtual ~CSquare();
};
