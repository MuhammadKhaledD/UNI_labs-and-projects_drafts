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
char * Employee::getName() const
{
	return name;
}
int Employee::getId() const
{
	return id;
}

// [Step2]:
// Uncomment the following 
/*
Employee::Employee(const Employee & rhs)
{
	id = rhs.id;

	// Make deep copying
	int len = strlen(rhs.name) + 1;
	name = new char[len];
	strcpy_s(name, len, rhs.name);

	cout<<"\n\n *** *** *** COPY Constructor is Called *** *** ***\n";

} 
*/


// [Step3]
// - Comment step2
// - Uncomment the following 
//  ---> compilation error .. would lead to infinte loop, so the compiler prevents it from the beginning
/*
Employee::Employee(const Employee rhs) // the by ref & is removed --> compilation error
{
	id = rhs.id;

	// Make deep copying
	int len = strlen(rhs.name) + 1;
	name = new char[len];
	strcpy_s(name, len, rhs.name);

	cout<<"\n\n *** *** *** COPY Constructor is Called *** *** ***\n";

} 
*/