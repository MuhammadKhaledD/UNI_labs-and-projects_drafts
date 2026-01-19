#include "CRect.h"
#include <iostream>
using namespace std;

CRect::~CRect()
{
	cout<<"rectangle  destrcutor is called"<<endl;
}

void CRect::ReadData()
{
	CFigure::ReadData(); //function reuse
	cout<<"Enter Rectangle Length=";
	cin>>m_dLength; // needs validation
	cout<<"Enter Rectangle Width=";
	cin>>m_dWidth; // needs validation
}

// the overriding implementation of the pure virtual function
void CRect::PrintArea()
{
	cout<<"\nArea of the Rectangle =";
	cout<<m_dLength*m_dWidth;
}
