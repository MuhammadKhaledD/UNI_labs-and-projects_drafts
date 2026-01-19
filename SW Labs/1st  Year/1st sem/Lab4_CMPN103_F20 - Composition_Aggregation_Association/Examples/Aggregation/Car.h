#ifndef CAR_H
#define CAR_H

#include "Engine.h"
class Car
{
	Engine* eng;	// The cars engine. Dynamic allocation.
	int topSpeed;
public:
	//Car non-default Constructor
	Car(int n, int hp);
	//Prints the Car's info
	void printInfo() const;
	//detach engine from car
	Engine* detachEngine();
	//attach engine to car
	void attachEngine(Engine * newEngine);
	//Car Destructor
	~Car();


};

#endif