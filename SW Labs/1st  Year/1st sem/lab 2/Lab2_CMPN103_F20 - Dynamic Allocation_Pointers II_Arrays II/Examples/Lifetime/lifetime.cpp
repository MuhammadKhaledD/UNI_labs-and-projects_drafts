/*
Data Structures and Algorithms Lab 2

File: lifetime.cpp

*/


#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: badReturn
Returns the address of a local variable
*/
int* badReturn()
{
	int a = 500;
	cout<<"\nAddress of variable a ="<<&a;
	return &a;
}
///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: heapReturn
Allocates space for a variable in the heap and returns its address.
*/
int* heapReturn()
{
	int* p = new int;
	cout<<"\nPoiter p points at address:"<<p;

	*p = 500;
	cout<<"\nLocation pointed by p contains the value:"<<*p;

	return p;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//This is the program starting point.
int main()
{

	cout<<"\n\n******************* Pitfalls *********************************\n";

	int* ptr;

	//badReturn and heapReturn are two functions that are supposed to return the address 
	//of a memory location whose values is 500
	ptr = badReturn();
	cout<<"\nAfter calling badReturn......";
	cout<<"\nPointer ptr points at address:"<<ptr;
	cout<<"\nLocation pointed by ptr contains the value:"<<*ptr;

	//Q(1) What is the value of 'ptr' ? What does it represent ?
	//Q(2) What is the value of '*ptr' ?

	cout<<endl;

	ptr = heapReturn();
	cout<<"\nAfter calling heapReturn......";
	cout<<"\nPointer ptr points at address:"<<ptr;
	cout<<"\nLocation pointed by ptr contains the value:"<<*ptr;
	//Q(3) What is the value of 'ptr' ? What does it represent ?
	//Q(4) What is the value of '*ptr' ?
	//Q(5) What is the difference between badReturn and heapReturn
	
	delete ptr;

	cout<<endl;
	return 0;
}
