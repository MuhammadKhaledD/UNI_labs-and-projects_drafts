#pragma once

#include "CFigure.h"

class CTriangle : public CFigure
{
	double m_side1, m_side2, m_side3;
public:
	CTriangle();
	double GetSide1();
	double GetSide2();
	double GetSide3();
	virtual void ReadData();
	virtual ~CTriangle();
};

