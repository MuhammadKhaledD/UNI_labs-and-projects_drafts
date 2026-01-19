
#include "CSquare.h"

#include <iostream>
using namespace std;

CSquare::CSquare()
{
	FigType= SQUARE;
}

CSquare::~CSquare()
{
	cout<<"square  destrcutor is called"<<endl;
}

void CSquare::ReadData()
{
	// here we don't re-use CRect::ReadData()
	// because we need to read only 1 dimension (because length = width in Squares)

	CFigure::ReadData(); // re-uses the one of class "CFigure" to read m_nID
	                     // Note that we can access the function of the grand-parent class 
	                     // the same way as of the parent class -> class name then scope resolution
	cout<<"Enter Square Length=";
	cin>>m_dLength;      // read only the length from the user
	                     // needs validation
	m_dWidth = m_dLength;
}

void CSquare::PrintArea()
{
	cout<<"\nArea of the Square =";
	cout<< m_dLength * m_dLength;
}

