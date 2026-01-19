#include "Engine.h"
#include <iostream>
using namespace std;

//Class non-default constructor
Engine::Engine(int h)
{
	setHorsepower(h);
	cout << "||| Engine with horsepower (" << horsepower << ") is being constructed |||" << endl;
}

//Class Destructor
Engine::~Engine()
{
	cout << "~ ~ ~ ~ Engine with horsepower (" << horsepower << ") is being destructed ~ ~ ~ ~" << endl;
}

void Engine::setHorsepower(int a)
{
	horsepower = a;
}

int Engine::getHorsepower() const
{
	return horsepower;
}

void Engine::printInfo()
{
	cout << "Engine with horsepower (" << horsepower << ")" << endl;
}
