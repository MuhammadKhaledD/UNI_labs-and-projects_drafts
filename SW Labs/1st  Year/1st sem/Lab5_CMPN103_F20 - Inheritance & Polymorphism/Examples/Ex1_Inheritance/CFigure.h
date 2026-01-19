#pragma once

class CFigure  
{
private:
	int m_nID; // Note: m_nID is private not protected, 
	           // so can't be accessed directly in derived classes
	           // they have to use public/protected functions to access it
	           // (e.g. setID, getID, ... etc)

public:

	CFigure(int id);	

	void setID(int id);

	int getID();

	~CFigure();
};
