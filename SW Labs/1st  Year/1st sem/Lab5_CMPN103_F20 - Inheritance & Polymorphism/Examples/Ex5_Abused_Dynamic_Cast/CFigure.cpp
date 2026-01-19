#include "CFigure.h"

#include <iostream>
using namespace std;

CFigure::CFigure()
{
}

int CFigure::GetID()
{
	return m_id;
}

void CFigure::ReadData()
{
	cout<<"Enter Figure ID=";
	cin>>m_id; // needs validation
}

CFigure::~CFigure()
{
}
