#pragma once

// Note that Figure Type (and this complicated example) is what we would do IF there were NO polymorphism
// to know the type of the object the base class pointer points to
enum FigureType 
{
	FIGURE,
	RECT,
	SQUARE,	
};

class CFigure  
{
private:
	int m_nID;

public:
	FigureType FigType;	//To know the type at runtime

	CFigure();	
	
	void PrintArea()  // PrintArea?? 
		              // Area of what?? 
					  // What is the area of a "figure"?
	                  // Such function should have NO code.
	{}	// Note that here we provide implementation {} but empty implementation
	    // because we put the braces {}, or we'll have an unresolved external symbol error
	
	void ReadData();
	
	~CFigure();
};
