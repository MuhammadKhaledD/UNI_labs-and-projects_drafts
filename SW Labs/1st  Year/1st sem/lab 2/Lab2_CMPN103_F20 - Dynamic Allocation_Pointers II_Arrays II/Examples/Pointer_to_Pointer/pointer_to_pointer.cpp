/*
Data Structures and Algorithms Lab 2

File: pointer_to_pointer.cpp

*/


#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

//This is the program starting point.
int main()
{
	cout<<"\n\n******************* Pointer to Pointers **********************\n";

	int b = 5;
	int* ptr;

	ptr = &b;

	cout<<"\n b ="<<b;
	*ptr = 7;
	cout<<"\n b ="<<b;

	int **R;
	R = &ptr;
	/*Q(1) What does the previous statement mean ?
	Explain the relation between the following expressions:
		*R
		ptr
		&b
	*/

	**R = 10;
	cout<<"\n b ="<<b;
	/*Q(2) What is the value of b ? Explain.*/

	int y = 50;
	*R = &y;
	cout<< "\n *ptr =" << *ptr;

	*ptr = 100;
	cout<<"\n b ="<<b;
	cout<<"\n y ="<<y;

	return 0;
}
