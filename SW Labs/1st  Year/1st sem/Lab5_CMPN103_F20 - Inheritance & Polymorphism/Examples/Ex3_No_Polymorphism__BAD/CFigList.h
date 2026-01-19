#pragma once

#include "CFigure.h" // we use only "CFigure" as you see below, 
                     // so you need to include only it.

// A class that contains array of different types of figures
class CFigList  
{
	enum {MaxSize=20}; // defining MaxSize that way makes it "Constant"
	
	// [m_List]: automatic array of base class pointer: (CFigure *) 
	// to be able to point to "different" types of figures (rectangles, squares, ...etc)
	// That is the way to put different types of objects in the same array
	// because base class pointers can point to objects of any of the derived classes
	CFigure* m_List[MaxSize]; // MaxSize is constant as mentioned above, 
	                          // so can be used with automatic arrays
	
	int m_nFigCount; // actual number of figures in the array
	
public:
	CFigList();
	void AddNewFigure(FigureType type); // takes the figure type as enum value
	                                    // then allocates an object of the class of this type,
	                                    // reads its data and adds it to the list
	void DisplayAreas(); // displays the area of each figure in the list
	~CFigList();
};
