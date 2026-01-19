#include "CTriangle.h"

#include <iostream>
using namespace std;

CTriangle::CTriangle()
{
}

double CTriangle::GetSide1()
{
	return m_side1;
}

double CTriangle::GetSide2()
{
	return m_side2;
}

double CTriangle::GetSide3()
{
	return m_side3;
}

void CTriangle::ReadData()
{
	CFigure::ReadData(); //function reuse
	cout<<"Enter Length of Side1 =";
	cin>>m_side1; // needs validation
	cout<<"Enter Length of Side2 =";
	cin>>m_side2; // needs validation
	cout<<"Enter Length of Side3 =";
	cin>>m_side3; // needs validation
}

CTriangle::~CTriangle()
{
}
