#include "Point.h"
#include <iostream>
using namespace std;

// this example to show the life time of classes objects 
// classes objects are allocated by constructors and deallocated by destructors.
// classes objects as other variables , are passed to functions by value , refernece or by pointer and have similar behaviour.
// when passed by value , a local copy of obejct is allocated which in turn is deallocated at the end of the function call , this copy is done by something called copu constructor see Point.cpp
// when passed by reference , the same object is passed and no extra copy is made, in this case deallocation is not made at the end of function call by default.
// when passed by pointer , the user is responsible of freeing the memory by deleting the pointer to the object so the destructor c=can be called.


Point* test(Point Point_byvalue, Point& Point_byref, Point* Point_byPointer)
{
	//a new object Point_byvalue is created 
	//Hint: Point_byvalue object will call the copy constructor
	//we will discuss copy constructor during the next labs and sections in details
	Point_byvalue.setX(10);
	Point_byvalue.setY(10);

	//Point (2, 2) will be updated to (20, 20)
	Point_byref.setX(20);
	Point_byref.setY(20);

	//Point (3, 3) will be updated to (30, 30)
	Point_byPointer->setX(30);
	Point_byPointer->setY(30);
	
	Point P(40 , 40);	//Create a point (40, 40)
	
	Point *ptr = new Point(50, 50);  //Allocate point (50, 50)
	return ptr;
}

int main()
{
	//After 1st run, 
	//uncomment the code according to the numbers shown in square brackets

	//Uncomment [1] ==> What is the problem? Solution?
     //Point P;
	
	//Automatic objects
	Point P1(1,1);
	Point P2(2,2);

	//Dynamic object
	//Uncomment [2]
	//Point* P3= new Point(3,3);

	cout<<endl;
	if(true)
	{
		//Object defined in certain scope.
		Point P4(4,4);
		//Uncomment [3]
	   //delete P3;        //the destructor for P3 is called here
	}  
	                      //the destructor for P4 is called here
	cout<<"after if\n";
	

	Point P5(5,5);


	cout<<endl;
	//Uncomment [4], Q: Can you explain each printed line? 
	/*
	Point* P6;
	P6=test(P1,P2,&P5);

	P1.print();
	P2.print();
	P5.print();
	P6->print();
	*/
	
	//Uncomment [5]
	//delete P6;

	cout<<endl;	

	return 0;
}