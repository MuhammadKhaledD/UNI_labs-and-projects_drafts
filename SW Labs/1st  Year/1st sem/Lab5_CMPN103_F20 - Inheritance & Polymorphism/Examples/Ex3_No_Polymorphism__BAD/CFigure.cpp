
#include "CFigure.h"

#include <iostream>
using namespace std;

CFigure::CFigure()
{
	FigType = FIGURE; // set FigType
	                  // to the enum value corresponding to the type of this class
	                  // Note that: FigType value is not passed as a parameter
	                  // we set it internally depending on the class
}

void CFigure::ReadData()
{
	cout<<"Enter Figure ID=";
	cin>>m_nID; // needs validation
}


CFigure::~CFigure()
{
	cout<<"Fig destructor is called"<<endl;
}
