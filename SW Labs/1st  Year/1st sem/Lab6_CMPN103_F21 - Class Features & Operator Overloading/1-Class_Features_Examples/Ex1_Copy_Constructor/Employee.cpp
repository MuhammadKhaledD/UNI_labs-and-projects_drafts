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
	               // because the constructors and the setters both create new array
	               // so when you go to destructor even without calling any setters
	               // there will be array allocated before in the constructor
	               // I mean: all paths create new dynamicallly allocated array
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

// After the first run and seeing the error (read the main): 
// uncomment the following "Copy Constructor"

/*
Employee::Employee(const Employee &rhs)
{
	id = rhs.id;

	// here is the point!
	// the importance of defining a copy constructor here (instead of using the one of the compiler)
	// is to allocate a new array for the newly-constructed object then copy content ("Deep Copying")
	// so when the passed object is deallocated somewhere in the program and its array deallocated with it
	// the newly-constructed object still has its own dynamic array allocated
	int len = strlen(rhs.name) + 1;
	name = new char[len];
	strcpy_s(name, len, rhs.name);

	// So, the main importance of "Copy constructor": is to avoid “dangling pointer” pointer shown above
	// In general, when a class has a pointer that allocates memory for it in the constructor
	// you need to define for it a copy consturctor (even if not required in the question)
	// to solve the dangling pointer problem by allocating a new memory space for the newly-constructed object

	cout<<"\n\n *** *** *** COPY Constructor is Called *** *** ***\n";

	// Note that providing a copy constructor will prevent the compiler from generating its one
	// which means you need to copy each data member by yourself (note that we did that for the 'id' too)
	
} 
*/
