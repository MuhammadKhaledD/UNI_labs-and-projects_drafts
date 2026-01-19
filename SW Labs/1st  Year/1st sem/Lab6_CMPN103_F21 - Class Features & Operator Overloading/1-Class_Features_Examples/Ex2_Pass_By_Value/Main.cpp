#include <iostream>
using namespace std;

#include "Employee.h"

void printEmployeeData(Employee E)	// E is passed by value --> so the "Copy Constructor" is called here
{
	cout << endl;
	cout << "Employee Id is " << E.getId() << " , ";
	cout << "Employee name is " << E.getName() << endl;
}

int main()
{
    Employee programmer("Ahmed",22);

	const Employee E1;
	Employee E2(E1); // Note that if you don't provide copy constructor
	                 // the one of the compiler will be used which doesn't have a cout inside it :)
	                 // so, you don't see the message printed on the console ...

	// Next code line calls function printEmployeeData and pass "programmer" object to it
	// For the function to work, it should first construct its local variable E
	// E is constructed given a full Employee object "programmer" 
	// --> a constructor that takes an object of the same class (Copy Constructor)
	// Hence the compiler searches for a constructor that takes an Employee object (i.e. the copy ctor)
	// If not found, the default COPY ctor of the compiler is called
	printEmployeeData(programmer); // Note: you won't see the copy ctor message printed on the console
	                               // if the user defined copy constructor that contains the cout is commented
	
	// Q: Why the printed name of the next statement is garbage if you use the compiler's copy constructor??
	cout << endl << "After function returns name =" << programmer.getName() << endl; 
	
	// Don't put system pause or cin here to be able to see the error

	// After the first run and seeing the error,
	// make step 2 then step 3 as mentioned in the lab doc

    return 0;
} 