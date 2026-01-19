#include <iostream>
using namespace std;

#include "Employee.h"

int main()
{
    Employee programmer("Ahmed",22); 

	Employee E = programmer;	// COPY constructor is called here (as declaration and initialization are in the same line)

	Employee Manager;     // normal default constructor is called here
	Manager = programmer; // NOTE: Copy Constructor is NOT called here because:
	                      //       object Manager was already constructed in the previous line.
	                      //       so, the cout written inside the copy constructor will not be printed here


	cout<<"\nManager name is "<<Manager.getName()<<endl;

	// [Step3]:
	// - uncomment the next code (trying self-assignment), what happens?
	/*
	Manager=Manager; 
	cout<<"\nManager name is "<<Manager.getName()<<endl;
	*/

	return 0;
} 