#include "Creature.h"

Creature::Creature(string iName,int x, int y, int Hlth, int Fpwr)
{
	creatureName = iName;
	is_killed = false;
	this->x = x;
	this->y = y;
	Health = Hlth;
	FirePower = Fpwr;
}

string Creature::getName()
{	return creatureName; }

void Creature::move(int a, int b) //move creature to (a, b)
{
	x = a;
	y = b;
}


bool Creature::DecHealth(int h)
{
	Health -= h;	//decrement health
	if(Health <= 0)	//check if killed
		is_killed = true;

	return is_killed;	//return is_killed status (returns true if killed, false if not)
}

bool Creature::SamePosition(int X, int Y)
{
	//returns true if given position is the same as the creatrue's position
	return ( (x == X)&&(y == Y) );
}


void Creature::DrawOnScreen() //print creature info on the screen
{
	cout<<"Name= " << creatureName<< ", at ( "<<x <<" , " << y << " )";
	cout<<", Fire Power= "<<FirePower;
	cout<<", Health= "<<Health;	
}


