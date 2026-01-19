
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


void CFigList::AddNewFigure(FigureType type)
{
	CFigure* pFig; // base class pointer 
	               // (a general pointer that can point to any figure type: CRect or CSquare)
	switch (type)
	{
	case RECT:
			pFig = new CRect;   // make it point to CRect figure
			((CRect*)pFig)->ReadData();   // need downcasting to call CRect::ReadData() 
			                              // --> BAD Implementation! See the next example "Polymorphism"
			break;
	case SQUARE:
			pFig = new CSquare; // make it point to CSquare figure
			((CSquare*)pFig)->ReadData(); // need downcasting to call CSquare::ReadData()
						                  // --> BAD Implementation! See the next example "Polymorphism"
			break;
	default:
		return;
	}

	m_List[m_nFigCount++] = pFig; // add it to the list and increment the count

}

void CFigList::DisplayAreas()
{
	cout<<"\nAreas of Figures:"<<endl;
	
	for(int i=0; i<m_nFigCount; i++)
	{
		// Here we need to check the type of the object first then downcast to that type
		// to be able to call PrintArea() version existing in the class of "the object" type
		// --> BAD Implementation!!

		// See the next example "Polymorphism" to know the better and easier way
	    // to call the version of the object type without checking or downcasting (virtual functions)

		switch (m_List[i]->FigType)
		{
			case RECT:
				((CRect*)m_List[i])->PrintArea();  // need downcasting to call CRect::PrintArea() 
								                   // --> BAD Implementation!
				break; 
			
			case SQUARE:
				((CSquare*)m_List[i])->PrintArea(); // need downcasting to call CSquare::PrintArea()
													// --> BAD Implementation!
				break;
		}
	}

}

CFigList::~CFigList()
{
	cout<<endl<<"deleting a figure list:"<<endl;
	for(int i=0; i<m_nFigCount; i++)
	{
		cout<<"Deleting Figure #"<<i+1<<endl;
		
		// Q: Which destructor is called by delete ?!!!
		//    the destructor of pointer type: Cfigure 
		//    or of object type: CRect or CSquare??
		delete m_List[i];
	}	

}