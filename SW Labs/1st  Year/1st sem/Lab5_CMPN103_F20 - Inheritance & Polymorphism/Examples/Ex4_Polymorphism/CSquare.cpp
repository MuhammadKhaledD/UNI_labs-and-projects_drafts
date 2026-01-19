#include "CSquare.h"
#include <iostream>
using namespace std;

CSquare::~CSquare()
{
	cout<<"square  destrcutor is called"<<endl;
}

void CSquare::ReadData()
{
	CFigure::ReadData(); //function reuse
	cout<<"Enter Square Length=";
	cin>>m_dLength;  // needs validation
	m_dWidth = m_dLength;
}

void CSquare::PrintArea()
{
	cout<<"\nArea of the Square =";
	cout<<m_dLength*m_dLength;
}