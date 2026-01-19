
#include "CFigList.h"
#include "CSquare.h" // if you check the implementation below,
                     // you'll find that we use CRect and CSquare classes
                     // that's why we need to include them
                     // so we included "CSquare.h" which already includes "CRect.h" inside it

#include <iostream>
using namespace std;

CFigList::CFigList()
{
	m_nFigCount=0;
	for(int i=0; i<MaxSize; i++)
		m_List[i] = NULL; 
}

void CFigList::AddNewFigure(int nChoice)
{
	
	CFigure* pFig; // base class pointer 
	               // (a general pointer that can point to any figure type: CRect or CSquare)

	switch (nChoice)
	{
	case 1:
			pFig = new CRect;   // make it point to CRect figure
			break;
	case 2:
			pFig = new CSquare; // make it point to CSquare figure
			break;
	default:
		return;
	}

	// [Note]:
	// No type check or downcast is needed 
	// to call ReadData() of the object type! 
	// Thanks to virtual functions and polymorphism :)
	pFig->ReadData();

	m_List[m_nFigCount++] = pFig; // add it to the list and increment the count
}

void CFigList::DisplayAreas()
{
	cout<<"\nAreas of Figures:"<<endl;
	
	// [Note]:
	// No type check or downcast is needed 
	// to call PrintArea() of the object type! 
	// Thanks to virtual functions :)
	for(int i=0; i<m_nFigCount; i++)
		m_List[i]->PrintArea();
}

// Example of good use of dynamic_cast<..>(..) to check on figure type
int CFigList::CountSquares()
{
	int count = 0;
	for (int i = 0; i < m_nFigCount; i++)
	{
		CSquare * pS = dynamic_cast<CSquare *>(m_List[i]);
		if (pS) // means if NOT NULL
			count++;
	}
	return count;

	// Note: that's an example of good use of dynamic_cast
	// but dynamic_cast is sometimes abused
	// to replace virtual functions
	// check the next examples for more details
}

CFigList::~CFigList()
{
	cout<<endl<<"\nDeleting a figure list:\n"<<endl;
	for(int i=0; i<m_nFigCount; i++)
	{
		cout<<"Deleting Figure #"<<i+1<<endl;

		// Q: After making the destructors virtual (of CFigure, ...etc),
		//    Which destructor is called by delete ?!!!
		//    the destructor of pointer type: Cfigure 
		//    or of object type: CRect or CSquare??
		delete m_List[i];
	}

}