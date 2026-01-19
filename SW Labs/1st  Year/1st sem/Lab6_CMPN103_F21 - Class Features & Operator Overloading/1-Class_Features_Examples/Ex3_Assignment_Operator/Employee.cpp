#include "Employee.h"

#include <cstring>
#include <iostream>
using namespace std;

Employee::Employee(char * m_name, int m_id)
{
    setId(m_id);

	int len = strlen(m_name) + 1; // + 1 for null terminator
    name = new char[len]; // allocate memory for pointer name
    strcpy_s(name, len, m_name);

	cout << "\nConstructor is Called for name: " << name << "...";
}

Employee::~Employee()
{
	cout<<"\nEntered Destructor for name: " << name << "...";
    delete[] name; // deallocate memory pointed to by pointer name
	               // note that here, we don't need to check if not null before deleting
	cout<<"\nout of the Destructor";
}
void Employee::setName(char* m_name)
{
	delete[] name; // don't need to check if name not equal null here
	               // because we allocate an array for it in the constructor

	int len = strlen(m_name)+1;
	name=new char[len];
	strcpy_s(name, len, m_name);
}
void Employee::setId(int m_id)
{
	id = m_id > 0 ? m_id: 0; 
}
char * Employee::getName()
{
	return name;
}
int Employee::getId()
{
	return id;
}

// The Copy Constructor
Employee::Employee(const Employee &rhs)
{
	id = rhs.id;

	// Make deep copying
	int len = strlen(rhs.name) + 1;
	name = new char[len];
	strcpy_s(name, len, rhs.name);

	cout<<"\n\n *** *** *** COPY Constructor is Called *** *** ***\n";
} 

// The Overloaded Assignment Operator
// [Step2]: uncomment the following function
// [Note]: Here void is returned
//      To allow cascading the assignment operator (i.e.  (x = y = z= w;)), 
//		let the function return a copy of the object. (Try it as exercise!).
/*
void Employee::operator = (const Employee & rhs)
{
	cout<<"\nAssginment operator is called";
	// [Step4]: Uncomment the next line
	//if(&rhs != this) // Check for self-assignment
	{
		cout<<"\nPerforming actual assignment:";
		id = rhs.id;

		// Deleting any previously allocated storage (to prevent memory leakage) 
		delete[] name;

		// Make deep copying
		int len = strlen(rhs.name) + 1;
		name = new char[len];
		strcpy_s(name, len, rhs.name);
	}
}
*/
