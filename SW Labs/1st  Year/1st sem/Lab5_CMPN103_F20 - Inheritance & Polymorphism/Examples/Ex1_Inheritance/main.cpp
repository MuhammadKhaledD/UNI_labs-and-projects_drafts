
#include "CRect.h"
// we need to include only "CRect.h"
// because we use only CRect in this file (and anyway it includes "CFigure.h" and "Point.h")

#include <iostream>
using namespace std;

void main()
{
	// Q: Write the expected output before running 
	// then run and check your answer

	//Create an object of class CRect	
	cout<<"\nConstructing a CRect(1,10,20,30,40) object....";
	cout<<"\nNotice the order of construction\n";

	CRect R(1, 10, 20 ,30, 40);

	//1- CRect object can directly call its base class (CFigure)'s public functions. 
	cout<<"\n\n-------------------------------------------------";
	cout<<"\n1- CRect object can directly call CFigure's public functions:";

	cout<<"\nCalling getID for example, ID=";
	cout << R.getID();

	cout<<"\nCalling setID for example, changing the ID";
	R.setID(3);

	cout<<"\nNow CRect ID=";
	cout << R.getID();

	cout<<"\n-------------------------------------------------";
		
	//2- CRect object can call its own public functions. 
	cout<<"\n\n-------------------------------------------------";
	cout<<"\n2- CRect objects can call its own public functions:";

	cout<<"\nCRect Length = ";
    cout << R.CalcLength();

	cout<<"\n-------------------------------------------------";

	//Destructors are called at the end of the scope.
	cout<<"\n\n-------------- The End of the Main --------------";
	cout <<"\nNotice the order of destruction\n";

}