#include "CRect.h"
#include <iostream>
using namespace std;


CRect::CRect()
{
	FigType= RECT; 
}

CRect::~CRect()
{
	cout<<"rectangle destrcutor is called"<<endl;
}

void CRect::ReadData()
{
	CFigure::ReadData(); // to read m_nID from the user
	cout<<"Enter Rectangle Length=";
	cin>>m_dLength; // needs validation
	cout<<"Enter Rectangle Width=";
	cin>>m_dWidth; // needs validation
}


// Q: What if you don't redefine PrintArea() for class CRect?
// Does any error occur?
void CRect::PrintArea()
{
	cout << "\nArea of the Rectangle =";
	cout << m_dLength * m_dWidth;
}
