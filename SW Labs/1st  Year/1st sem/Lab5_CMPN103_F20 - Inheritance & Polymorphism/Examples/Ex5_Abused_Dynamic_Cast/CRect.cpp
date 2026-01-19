#include "CRect.h"

#include <iostream>
using namespace std;

CRect::CRect()
{
}

double CRect::GetLength()
{
	return m_length;
}

double CRect::GetWidth()
{
	return m_width;
}

void CRect::ReadData()
{
	CFigure::ReadData(); //function reuse
	cout<<"Enter Rectangle Length=";
	cin>>m_length; // needs validation
	cout<<"Enter Rectangle Width=";
	cin>>m_width; // needs validation
}

CRect::~CRect()
{
}
