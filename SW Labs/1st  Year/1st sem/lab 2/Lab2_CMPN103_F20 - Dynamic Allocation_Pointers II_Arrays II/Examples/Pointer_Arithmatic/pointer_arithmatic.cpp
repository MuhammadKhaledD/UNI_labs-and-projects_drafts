/*
Data Structures and Algorithms Lab 2

File: pointer_arithmatic.cpp

*/


#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

//This is the program starting point.
int main()
{
	int a = 1;
	int A[100];
	int b = 2;

	for(int i = 0; i < 100; ++i)
	{
		A[i] = i;
	}

	//Now A = {0, 1, 2, 3, ...., 99}

	//1. Pointer Arithmetic and Relationship between Pointers and Arrays

	cout<<"\n******************* Pointers and Arrays **********************\n";
	int intSize = sizeof(int);
	cout<<"\nSize of integer = "<<intSize<<" Bytes";

	/*Q(1) 
	What is the value of 'intSize' ? What does it mean ?*/

	cout<<"\n A="<<A;
	cout<<"\n &A[0]="<<&A[0];
	cout<<"\n A[0]="<<A[0];
	cout<<"\n *A="<<*A;

	
	/*Q(2) 
	According to the above values, can you explain what does the identifier "A" represent ?*/

	/*Q(3) What is the value of the following expression: &A[1]
	Explain the differnece in values between &A[1] and &A[0] */


	int* ptr;
	ptr = A;
	
	/*Q(4) What is the value of ptr ? What does it mean ?*/


	//Accesssing A through ptr
	cout<<"\n\nptr ="<<ptr;
	cout<<"\nAccesssing A through ptr";
	ptr[2] = 99;
	cout<<"\nintArray[2]="<<A[2];


	/// Pointer Arithmetic
	cout<<"\n\n******************* Pointer Arithmetic ***********************\n";
	cout<<"\nptr ="<<ptr;
	ptr = ptr + 3;
	cout<<"\nNow ptr ="<<ptr;
	cout<<"\nptr[0] ="<<ptr[0];
	

	/*Q(5) What are the values of the following expressions:
		ptr + 3
		&(ptr[3])
		*(ptr + 3)
		ptr[3]
	-Explain the difference between ptr + 3 and ptr
	-According to these values what is the EXACT function of the [] operator for pointers and arrays?*/
	
	return 0;
}
