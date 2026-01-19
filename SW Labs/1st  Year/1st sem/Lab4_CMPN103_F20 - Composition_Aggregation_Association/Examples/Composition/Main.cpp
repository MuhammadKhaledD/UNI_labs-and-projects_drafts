#include "Line.h"
#include <iostream>
using namespace std;

int main()
{
	//Declare an object (instance) of class Line
	//and pass values to its constructor.
	Line L(1,2, 0,0);

	cout<< ( L.PassByOrigin()?"\nLine is passing by origin":"\nLine is not passing by origin");

	//change end point
	cout<<"\nChanging end point to 3,4";
	L.SetEnd(3, 4);
	cout<< ( L.PassByOrigin()?"\nLine is passing by origin":"\nLine is not passing by origin");

	cout<<"\n===============================\nFunction main() is terminating\n";
	return 0;
}
