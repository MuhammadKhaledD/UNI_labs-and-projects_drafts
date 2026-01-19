#include <iostream>
using namespace std;

//in this example we see the importance and strength of classes
// classes provide the concept of Encapsulation where data and funcntions are gathered for the same object unlike structs in the previous example.
// classes provide the need to know prenciple as users (and functions) are allowed to access functions and data  they needand have the rights to access only. 
// this done by the defination of private ( accessed only by class members) / public sections ( accessed by all users ) / protected (accessed by class members and child classes).
// classes also provide means to change private data memebers by set functions , where we make sure that neccessary checks are made.
// users can also use get functions to access as aread only mode to private data members .
// "this" pointer is a formal method to access class data members inside the class it self 
// ,it can be used for formality, clearification or in case of name conflicts between class data members and functions parameters. 

//Circle class Definition
//-----------------
//A class that implements a Circle
class Circle
{
	double radius; //Circle Radius
	double x,y; //Circle Center Point
public:
	//Notice that we do not need to pass an object of class Circle 
	//to the following function (as we did in the struct case)
	//Reason: These functions are already members of class Circle and has direct access to
	//        its data members.
	void init();
	void changeCenter(double a, double b);
	void setRadius(double newRad);
	double calcPerimeter();
	void printCircleData();

};


//Circle Methods Definition
//------------------------
//Notice how the function header is written


//Initializes the circle state
// must be called before any other operation.
// Initailaizes all Circle data members
// The default is that circle cener is (1,1) and rad  is 2
void Circle::init()
{
	radius = 2.0;
	x = 1;
	y = 1;
}

//update circle center point.
void Circle::changeCenter(double a, double b)
{
	this->x = a;	//using "this" pointer
	y = b;			//without "this" pointer
}

//update Circle radius to the newRad value
//Note: newRad should be >= zero
void Circle::setRadius(double newRad)
{
	if(newRad < 0 )
		radius = 2; //default radius
	else
		radius = newRad;
}

//Calculate and return circle perimeter
double Circle::calcPerimeter()
{
	return 2 * 3.14 * radius;
}

void Circle::printCircleData()
{
	cout<<"\nCircle Data:\n";
	cout<<"Center = ("<<x<<","<<y<<") Radius = "<<radius<<endl;
	cout<<"Perimeter = "<<calcPerimeter()<<endl;
}


//Circle User Code
//---------------

int main()
{
	//Create objects of Circle
	Circle Circ1, Circ2;

	//Initialize the Circle
	Circ1.init();
	Circ2.init();

	cout<<"\nCircle 1:";
	Circ1.printCircleData();

	//update data of Circ2
	Circ2.changeCenter(10, 15);
	Circ2.setRadius(5);
	cout<<"\nCircle 2:";
	Circ2.printCircleData();

	//Now, see how the Circle becomes protected against user's code.
	//After running once, uncomment the next line.
	//Circ1.radius = -4 ;	//User shouldn't have direct access to "radius"
	
	return 0;
}


