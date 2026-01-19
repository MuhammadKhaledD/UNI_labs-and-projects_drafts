#include "Car.h"
#include <iostream>
using namespace std;

int main()
{
	Car *ptr;	//How many cars/engines are allocated by this line? Why?
	int topSpeed;
	int hp;

	topSpeed = 180;
	hp = 200;
	Car A(topSpeed, hp);	//Automatic object (Car)	

	if (true)	//any dummy scope
	{ //Scope of Car B

		topSpeed = 200;
		hp = 220;
		Car B(topSpeed, hp);

		topSpeed = 140;
		hp = 180;
		ptr = new Car(topSpeed, hp);

		B.printInfo();
	}

	ptr->printInfo();
	Engine * ptrOldEngine = ptr->detachEngine(); //removing ptr's old engine
	ptr->printInfo();
	delete ptr; // Is engine destructor called? Why?

	A.printInfo();

	A.attachEngine(ptrOldEngine); //Why is Engine destructor called?
	A.printInfo();


	return 0;
}
