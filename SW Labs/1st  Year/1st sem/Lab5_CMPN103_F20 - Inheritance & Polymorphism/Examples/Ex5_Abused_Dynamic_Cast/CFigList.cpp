
#include "CFigList.h"
#include "CRect.h" 
#include "CTriangle.h"

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
	    	pFig = new CTriangle; // make it point to CSquare figure
			break;
	default:
		return;
	}

	pFig->ReadData();
	m_List[m_nFigCount++] = pFig; 
}

// An Example of Abusing Dynamic Case ---> BAD Implementation!!
void CFigList::PrintInfo()
{
	// In this function dynamic_cast is abused with getters
	// to break class responsibilities and complicate the code

	// Here, we used dynamic cast to know the type of the object at runtime
	// Then, we put the logic of printing this type of object inside CFigList::PrintInfo()
	// which means that "CFigList" class does the job that should be done by CRect and CTriangle 
	// of printing themselves --> breaking class responsibiities/jobs

	// The better solution of that is to: 
	// put PrintInfo() as a virtual function in CFigure
	// and override it in CRect and CTriangle 
	// with the logic of printing themselves
	// and simply the next for loop will contain only 1 statement of calling this virtual function
	// which automatically executes PrintInfo() of the object type 
	// (without checking the type using dynamic_cast)

	for (int i = 0; i < m_nFigCount; i++)
	{
		CRect * pR = dynamic_cast<CRect *>(m_List[i]);
		if(pR) // is CRect
		{
			// print the info of the CRect 
			// --> BAD!! This is the job of "CRect" Class
			cout << "=== Rect Info ===" << endl;
			cout << "ID = " << pR->GetID();
			cout << ", Length = " << pR->GetLength();
			cout << ", Width = " << pR->GetWidth();
			cout << endl;
		}
		else // is NOT CRect
		{
			CTriangle * pT = dynamic_cast<CTriangle *>(m_List[i]);
			if(pT) // is CTriangle
			{
				// print the info of the CTriangle  
				// --> BAD!! This is the job of "CTriangle" Class
				cout << "=== Triangle Info ===" << endl;
				cout << "ID = " << pT->GetID();
				cout << ", Side1 = " << pT->GetSide1();
				cout << ", Side2 = " << pT->GetSide2();
				cout << ", Side3 = " << pT->GetSide3();
				cout << endl;
			}
		}
	}
}

// Another Example of Abusing Dynamic Case ---> BAD Implementation!!
void CFigList::DisplayPerimeters()
{
	for (int i = 0; i < m_nFigCount; i++)
	{
		CRect * pR = dynamic_cast<CRect *>(m_List[i]);
		if(pR) // is CRect
		{
			// print the perimeter of the CRect 
			// --> BAD!! This is the job of "CRect" Class
			double perm = (pR->GetLength() + pR->GetWidth()) * 2;
			cout << "Rect Perimeter = " << perm;
			cout << endl;
		}
		else // is NOT CRect
		{
			CTriangle * pT = dynamic_cast<CTriangle *>(m_List[i]);
			if(pT) // is CTriangle
			{
				// print the perimeter of the CTriangle  
				// --> BAD!! This is the job of "CTriangle" Class
				double perm = pT->GetSide1() + pT->GetSide2() + pT->GetSide3();
				cout << "Triangle Perimeter = " << perm;
				cout << endl;
			}
		}
	}
}

CFigList::~CFigList()
{
	cout<<endl<<"\nDeleting a figure list:\n"<<endl;
	for(int i=0; i<m_nFigCount; i++)
	{
		cout<<"Deleting Figure #"<<i+1<<endl;

		delete m_List[i];
	}

}