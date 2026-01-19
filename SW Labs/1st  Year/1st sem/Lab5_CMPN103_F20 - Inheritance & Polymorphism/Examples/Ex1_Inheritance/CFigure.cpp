
#include "CFigure.h"

#include <iostream>
using namespace std;

CFigure::CFigure(int id)
{
	m_nID = (id >= 0) ? id : 0; // validation of non-default constructor
	cout<<"\n ||| CFigure with ID="<<m_nID<<" constructor is executed |||";
}

void CFigure::setID(int id)
{
	m_nID = (id >= 0) ? id : 0; // validation
}

int CFigure::getID()
{
	return m_nID;
}

CFigure::~CFigure()
{
	cout<<"\n ~~~ CFigure with ID="<<m_nID<<" destructor is executed ~~~";
}
