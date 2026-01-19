#include "Point.h"
#include <iostream>
using namespace std;

// in this example we see three different ways to define constructors of hte same class all together 
// this similar to the concept of function overloading.

int main()
{
	Point P1;		//No parameters passed ==> Default constructor is called
	
	//According to the number of parameters passed, the appropriate constrcutor is called.
	Point P2(1,1);
	Point P3(2,2,2);
	
	//Dynamic Object Allocation (the "new" operator)
	//You can use any constructor

	// Q: How many calls for the destructors? Is that correct or not and why? 
	// Q: What's missing?  
	Point* ptr;
	ptr = new Point;
	ptr = new Point(3, 4);
	ptr = new Point(5, 6, 7);

	cout<<"\nSix objects were constructed using different types of constructors";	
	cout<<endl;

	
	return 0;
}