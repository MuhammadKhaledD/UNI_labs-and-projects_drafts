/*
Data Structures and Algorithms Lab 2

File: passing_pointers.cpp

*/

// Passing pointers to functions

#include <iostream>
using namespace std;

// allocate an array of size n if n > 0 and returns true, otherwise returns false
bool AllocateArray(int *& A, int n) // Note: array pointer A is passed by reference
{
	if (n <= 0)
		return false;

	// Note: we do't need to write else, 
	// because return statement makes us exits the whole function

	A = new int[n]; // that's why array pointer is passed by ref.
				    // because you'll make it point to new memory location (A = ...)

	return true;

}

// read array elements from user
void ReadElements(int * A, int n) // don't need to pass A by reference 
									 // because you'll not make pointer A points to something else
{
	cout << "Enter " << n << " array elements:" <<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
}

// print array elements to user
void PrintElements(int * A, int n) // don't need to pass A by reference 
								// because you'll not make pointer A points to something else
{
	for (int i = 0; i < n; i++)
	{
		cout<< A[i] <<" ";
	}
	cout << endl;
}

// deallocate an array and makes t's pointer points to NULL
void DeallocateArray(int *& A) // Note: array pointer is passed by reference
{
	delete [] A; // that's NOT the line that makes us pass A by reference
	A = NULL; // that's why array pointer is passed by ref.
			  // because you'll make it point to NULL (A = ...)
}

void main()
{
	int * p;

	int n;
	bool is_allocated;

	do
	{
		cout << "Enter number of elements n > 0 :" <<endl;
		cin >> n;

		is_allocated = AllocateArray(p, n);
	} while (!is_allocated); // continue reading untill user enters n>0

	ReadElements(p, n);

	cout << "\nYou Entered:" <<endl;

	PrintElements(p, n);

	DeallocateArray(p); 

	if(p == NULL)
		cout << "p equals NULL"<<endl;
	else
		cout << "p does NOT equal NULL"<<endl;

	// TRY to remove the reference & of DeallocateArray funtion
	// then RUN and see the output

	// TRY to remove the reference & of AllocateArray funtion
	// then RUN and see the output

	system("pause"); // to make the console not be closed without a key press
}