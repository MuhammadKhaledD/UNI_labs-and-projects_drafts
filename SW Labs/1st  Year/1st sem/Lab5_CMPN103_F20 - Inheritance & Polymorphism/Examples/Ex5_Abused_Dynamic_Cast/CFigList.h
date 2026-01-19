#pragma once

#include "CFigure.h"

class CFigList  
{
	enum {MaxSize=20};  

	CFigure* m_List[MaxSize];
	
	int m_nFigCount; 
	
public:
	CFigList();
	void AddNewFigure(int nChoice); 
	void PrintInfo();         // prints the info of each figure in the list
	void DisplayPerimeters(); // displays the area of each figure in the list
	~CFigList();
};