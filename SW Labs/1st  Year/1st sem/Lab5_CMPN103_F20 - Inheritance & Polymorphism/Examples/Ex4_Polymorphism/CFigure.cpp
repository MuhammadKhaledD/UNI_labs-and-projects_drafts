#include <iostream>
using namespace std;
#include "CFigure.h"

CFigure::CFigure()
{
}

int CFigure::getID()
{
	return m_nID;
}

// Note: keyword "virtual" is only written INSIDE class declaration
// Q: Try to write "virtual" here too and see the error
void CFigure::ReadData()
{
	cout<<"Enter Figure ID=";
	cin>>m_nID; // needs validation
}

CFigure::~CFigure()
{
	cout<<"fig  destrcutor is called\n"<<endl;
}
