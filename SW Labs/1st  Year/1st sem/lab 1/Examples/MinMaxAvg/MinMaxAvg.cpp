/*
Data Structures and Algorithms Lab 1
Module 2 - MinMaxAvg

File: MinMaxAvg.cpp

This is a program that calculates minimum, maximum and average of values in an array
It shows how to pass an array to a function
*/


#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

/*
Function: min
Gets the minimum value in an array

Parameters:
	Items : Array of float values. (passed as pointer)
	n : Number of values in the array (int).
Returns: Minimum value (float)
*/
float min(float *Items, int n)
{
	//Assume the 1st value is the minimum
	float minimum = Items[0];

	//Loop through the array. If a value is less than the current minimum, set it as the minimum.
	for(int i = 1; i < n; i++)
	{
		if(Items[i] < minimum)
			minimum = Items[i];
	}

	return minimum;	//"return" immediately exists the function
}
/////////////////////////////////////////////////////////////////////////////////////

float max(float *Items, int n)
{
	float maximum = Items[0];

	for(int i = 1; i < n; i++)
	{
		if(Items[i] > maximum)
		{
			maximum = Items[i];
		}
	}

	return maximum;
}
/////////////////////////////////////////////////////////////////////////////////////

float avg(float Items[], int n) //Another syntax to pass an array
{
	float sum = 0.0f;

	for(int i = 0; i < n; i++)
	{
		sum += Items[i];	//Equivalent to "sum = sum + Items[i]"
	}

	return sum / n;
}
/////////////////////////////////////////////////////////////////////////////////////

//This is the program starting point.
int main()
{
	const float pi = 3.14f;
	int size;
	float values[100];	//Array of 100 float values

	cout << "Enter number of values (1 <= n <= 100):";
	cin >> size;	//Read number of values

	//Validate that (1 <= n <= 100)
	while(size < 1 || size > 100)	
	{
		cout << "Invalid number of values" << endl;
		cout << "Enter number of values (1 <= n <= 100):";
		cin >> size;
	}

	cout << "Enter " << size << " numbers: ";

	//Read values
	for(int i = 0; i < size; ++i)
		cin >> values[i];
	
	float maximum = max(values, size);
	float minimum = min(values, size);
	float average = avg(values, size);

	cout << "Maximum is " << maximum << endl;
	cout << "Minimum is " << minimum << endl;
	cout << "Average is " << average << endl;

	return 0;
}
