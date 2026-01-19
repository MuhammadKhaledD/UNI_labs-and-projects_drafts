/*
Data Structures and Algorithms Lab 2

File: dynamic_alloc.cpp

*/


#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"


//This is the program starting point.
int main()
{
	int c;

	int* ptr, *ptr2;

	// Example 1 -------------------

	ptr = NULL;
	/* Q(1) What is the value of 'ptr' ?*/

	ptr = new int;
	/* Q(2) What is the value of 'ptr' ?*/

	*ptr = 3;
	c = *ptr;
	/* Q(3) What is the value of 'c' ?*/

	c = 5;

	/* Q(4) What is the value of '*ptr' ?*/

	delete ptr;
	/* Q(5) What is the value of 'ptr' and '*ptr'?
	Why is it a common practice to set a pointer to NULL after deallocation ? */

	// Example 2 -------------------

	ptr = new int ;

	ptr = &c;

	// uncomment the following line and rerun
	//delete ptr;
	/* 
	Q(6) What happened when you run? Why?
	Q(7) There is "ptr = new int ;" (the 1st line after example 2 comment),
	     Where is the correct location to delete (free) this allocated memory?
	*/

	// Example 3 -------------------

	ptr = new int;

	ptr2 = ptr;

	delete ptr2;
	// uncomment the following line and rerun
	//delete ptr;
	/* Q(8) What happened when you run? Why? */

	// Example 4 -------------------

	ptr = new int[3];
	ptr2 = ptr;
	ptr2[0] = 0;
	ptr2[1] = 1;
	ptr2[2] = 2;

	/* Q(9) What are the values of 'ptr[0]', 'ptr[1]' and 'ptr[2]' ? Explain. */
	
	delete[] ptr2;
	
	/* Q(10) What are the values of 'ptr[0]', 'ptr[1]' and 'ptr[2]' ? Explain. */
	/* Q(11) Do we need to: delete[] ptr1; ?? */

	return 0;
}