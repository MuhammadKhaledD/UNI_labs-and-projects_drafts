#include <iostream>
using namespace std;

// this example is to show the importance of classes and why they are used 


// Assume the default is that the circle cener is (1,1) and rad  is 2
void init(double& radius, double& x, double& y)
{
	radius = 2.0;
	x = 1;
	y = 1;
}

//update Circle radius to the newRad value
//Note: newRad should be >= zero
void setRadius(double newRad, double& radius)
{
	if (newRad < 0)
		radius = 2; //default radius
	else
		radius = newRad;
}

//Calculate and return circle perimeter
double calcPerimeter(double radius)
{
	return 2 * 3.14 * radius;
}

void printCircleData(double x, double y, double radius)
{
	cout << "\nCircle Data:\n";
	cout << "Center = (" << x << "," << y << ") Radius = " << radius << endl;
	cout << "Perimeter = " << calcPerimeter(radius) << endl;
}


//Circle User Code
//---------------

int main()
{

	// Create two circles 
	// circle 1
	double radius1;
	double x1, y1;

	// circle 2
	double radius2;
	double x2, y2;

	//Initialize the Circle, 
	// The circle object is passed by reference, why ? 
	init(radius1, x1, y1);
	init(radius2, x2, y2);

	cout << "\nCircle 1:";
	printCircleData(x1, y1, radius1);

	//update data of Circ2
	x2 = 10;
	y2 = 15;
	setRadius(5, radius2);
	cout << "\nCircle 2:";
	printCircleData(x2, y2, radius2);

	return 0;
}
