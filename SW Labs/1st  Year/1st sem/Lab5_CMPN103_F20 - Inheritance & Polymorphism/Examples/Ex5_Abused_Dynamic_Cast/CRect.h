#pragma once

#include "CFigure.h"

class CRect : public CFigure
{
	double m_length, m_width;
public:
	CRect();
	double GetLength();
	double GetWidth();
	virtual void ReadData();
	virtual ~CRect();
};

