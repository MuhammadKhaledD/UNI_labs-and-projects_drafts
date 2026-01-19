#include "Car.h"
#include <iostream>
using namespace std;

//Car Non-default constructor
Car::Car(int n, int hp)
{

	cout << "||| Car of top speed" << n << " is being constructed |||" << endl;
	topSpeed = n;
	//Aggregation: Outer object is responsible for constructing inner object(s)
	//Logically: engines can exist independently
	eng = new Engine(hp);
}

//Car Destructor
Car::~Car()
{
	cout << "~ ~ ~ ~ Car of top speed " << topSpeed << " is being destructed ~ ~ ~ ~" << endl;

	//Aggregation: Outer object is responsible for destructing inner object(s)
	//delete all the allocated carriages
	//Q2: what happens with memory if you commented the next line?
	if (eng) { //First check that I still own the engine
		delete eng;
	}
}

//Prints the cars info
void Car::printInfo() const
{
	cout << endl << "*******   Car Info **************" << endl;
	cout << "Car has top speed of " << topSpeed << endl;
	if (eng) {
		cout << "Car has engine" << endl;
		eng->printInfo();
	}
	else {
		cout << "Car does not have an engine" << endl;
	}

}

//detaching engine from car
Engine * Car::detachEngine()
{
	Engine* temp = eng;
	eng = NULL;
	return temp;
}

//attaching an engine to car
void Car::attachEngine(Engine * newEngine)
{
	if (!newEngine) {
		return;
	}
	if (eng) {
		delete eng;
	}
	eng = newEngine;
}
