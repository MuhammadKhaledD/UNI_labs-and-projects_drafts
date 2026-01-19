#include <iostream>
using namespace std;
#include "CFigure.h"

CFigure::CFigure(int id)
{
	m_nID = (id >= 0) ? id : 0; // validation
}

void CFigure::setID(int id)
{
	m_nID = (id >= 0) ? id : 0; // validation
}

int CFigure::getID()
{
	return m_nID;
}

void CFigure::PrintInfo()
{
	cout<<"\nID = "<<m_nID;
}

