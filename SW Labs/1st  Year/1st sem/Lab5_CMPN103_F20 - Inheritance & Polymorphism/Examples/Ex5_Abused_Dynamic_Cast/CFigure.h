#pragma once

class CFigure
{
	int m_id;
public:
	CFigure();
	int GetID();
	virtual void ReadData();
	virtual ~CFigure();
};

