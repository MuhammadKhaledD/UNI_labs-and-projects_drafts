#pragma once

class CFigure  
{
private:
	int m_nID;

public:
	CFigure(int id);	
	void setID(int id);
	int getID();
	void PrintInfo(); // prints the CFigure's data members: m_nID
};
