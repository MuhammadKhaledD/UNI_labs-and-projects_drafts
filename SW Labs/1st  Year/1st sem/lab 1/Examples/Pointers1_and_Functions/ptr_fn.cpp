/*
Data Structures and Algorithms Lab 1
Module 1: Pointers1_and_Functions

File: ptr_fn.cpp

This is a program that demosntrates the usage of pointers and parameter passing
*/


#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

/*
Function: increment

Demonstrates passing paramters by value and by reference and passing a pointer by incrementing the value of each one.
*/
void increment(int v, int &R, int *P)
{
	cout<<"\nInside function increment......";
	cout<<"\nAddress of v ="<<&v;
	cout<<"\nAddress of R ="<<&R;
	cout<<"\nAddress pointed to by P ="<<P;

	v += 1;
	R += 1;
	*P += 1;
}

//This is the program starting point.
int main()
{
	int a = 1;
	int intArray[100];
	int b = 2;
	int c;

	//Fill the array
	for(int i = 0; i < 100; ++i)
	{
		intArray[i] = i;
	}
	//Now intArray = {0, 1, 2, 3, ...., 99}

	//1. Basic operations
	/*Q(1-1) What are the addresses of 'a' and 'b' ?*/
	
	int *ptr, dummy;
	/*Q(1-2) What are the data types of 'ptr' and 'dummy' ?*/

	ptr = &a;
	/*Q(1-3) What is the value of 'ptr' ? What does it mean ?*/
	

	*ptr = 3;
	/*Q(1-4) What are the values of 'a' and 'b' ? Explain.*/

	*ptr = b;
	/*Q(1-5) What are the values of 'a' and 'b' ? Explain.*/

	ptr = &b;
	/*Q(1-6) What is the value of 'ptr' ? What does it mean ?*/

	int *ptr2 = &b;
	*ptr2 = 0;
	/*Q(1-7) What are the values of 'ptr', 'ptr2', '*ptr', '*ptr2' ?
	Explain why the assignment of '*ptr2' affects the value of '*ptr'.*/

	//2. Parameter passing
	a = b = c = 10;
	
	/*Q(2-1) In the next function call, why 'a' and 'b' are not prefixed with the address operator (&), while c is ? */

	/*Q(2-2) Write down the addresses of 'a', 'b' and 'c'. After returning form the function, check
	the values of 'a', 'b' and 'c' and explain*/

	cout<<"\nAddress of a ="<<&a;
	cout<<"\nAddress of b ="<<&b;
	cout<<"\nAddress of c ="<<&c;

	cout<<"\nBefore function call: a="<<a<<" b="<<b<<" c="<<c;
	increment(a, b, &c);
	cout<<"\nAfter function call: a="<<a<<" b="<<b<<" c="<<c<<endl;

	ptr = &c;
	
	/*Q(2-3) In the next function call, why 'ptr' is not prefixed with the address operator ?*/
	/*Another way to call the function */
	cout<<"\nCalling increment again";
	increment(a, b, ptr);
	cout<<"\nAfter 2nd function call: a="<<a<<" b="<<b<<" c="<<c<<endl;
}