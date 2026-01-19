#pragma once

#include "CFigure.h"

class CRect : public CFigure  
{
protected:
	double m_dWidth, m_dLength; //protected members to be accessed directly by derived classes of CRect
	
	// CRect has more 1 data members inherited from CFigure:
	// 1- m_nID but inaccessible directly (only through public/protected functions)

public:

	// Even if you don't write virtual here, 
	// it is a virtual function as defined by base class.
	// but it is better to write virtual here for readability.

	/*virtual*/ void ReadData();	

	virtual void PrintArea();  // Note: don't put " =0; " here
                               // OR class CRect will be abstract too

	virtual ~CRect();
};
