#include <iostream>
using namespace std;

// this example is to show the importance of classes and why they are used 
// in this program we use a struct circle and use functions to do changes to this struct (data and functions are separeted )
// this is different from classes as classes have their functions included inside the class then, enable more stable and easy functionality.
// examine this program and try to define the main problems  without classes where every thing is accessable by the user's code .

//Circle Definition
//-----------------
//A struct that implements a Circle

class Circle
{
public:
	double radius; //Circle Radius
	double x,y; //Circle Center Point
};


//Initializes the circle state
// must be called before any other operation.
// Initailaizes all Circle data members
// The default is that circle cener is (1,1) and rad  is 2
void init(Circle *pC)
{
	pC->radius = 2.0;
	pC->x = 1;
	pC->y = 1;
}

//update circle center point. C should be passed by reference
void changeCenter(Circle &C, double a, double b)
{
	C.x = a;
	C.y = b;
}

//update Circle radius to the newRad value
//Note: newRad should be >= zero
void setRadius(Circle &C, double newRad)
{
	if(newRad < 0 )
		C.radius = 2; //default radius
	else
		C.radius = newRad;
}

//Calculate and return circle perimeter
// Why Circle is passed by reference and const? 
double calcPerimeter(const Circle & C) 
{
	return 2 * 3.14 * C.radius;
}

void printCircleData(const Circle & C)
{
	cout<<"\nCircle Data:\n";
	cout<<"Center = ("<<C.x<<","<<C.y<<") Radius = "<<C.radius<<endl;
	cout<<"Perimeter = "<<calcPerimeter(C)<<endl;
}


//Circle User Code
//---------------

int main()
{
	//Create objects of Circle
	Circle Circ1, Circ2;

	//Initialize the Circle, 
	// The circle object is passed by reference, why ? 
	init(&Circ1);
	init(&Circ2);

	cout<<"\nCircle 1:";
	printCircleData(Circ1);

	//update data of Circ2
	changeCenter(Circ2, 10, 15);
	setRadius(Circ2, 5);
	cout<<"\nCircle 2:";
	printCircleData(Circ2);

	//Now, see how the Circle is not protected against user's code.
	//After running once, uncomment the next lines.
	// Circ1.radius = -4 ;	//User shouldn't have direct access to "radius", why?
	// cout<<"\nCircle 1 after radius update:";
	// printCircleData(Circ1);
	// Q: How can we change the code so that the user has no direct access to "radius"? 
	
	return 0;
}
