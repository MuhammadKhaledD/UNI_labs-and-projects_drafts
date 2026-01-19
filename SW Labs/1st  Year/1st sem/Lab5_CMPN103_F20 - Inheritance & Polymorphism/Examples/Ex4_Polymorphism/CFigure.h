#pragma once

class CFigure  
{
private:
	int m_nID;

public:
	
	//No separate variable to hold type info is needed.
	//FigType is NOT needed any more -> Thanks to Polymorphism :)
	
	CFigure();

	int getID(); // [non-virtual] 
	             // because it does NOT have
	             // different implementation (behaviour) in derived classes
	             // same behaviour, so put it once in base class

	//[Pure Virtual Function] 
	//  1- must be overridden in derived class 
	//     If not, no syntax error but the derived will be abstract class too
	//  2- makes the class abstract (cannot make objects of it)

	virtual void PrintArea()=0;	// [pure virtual] 
	                            // 1- virtual: because has different behaviour 
	                            //    in derived classes (each has different area)
								// 2- pure: because meaningless implementation
	                            //    of printArea() of class CFigure (has no logical area)
	                            // --> Do not forget " =0; " to make it pure
	                            // --- OR you'll get unresolved external symbol error

	virtual void ReadData();    // [virtual] (not pure) 
	                            // because there is a meaningful implementation
	                            // to read the id of the CFigure

	//Destructor should be virtual.
	// Q: Try to remove the keyword "virtual" and see the effect
	virtual ~CFigure();	
};
