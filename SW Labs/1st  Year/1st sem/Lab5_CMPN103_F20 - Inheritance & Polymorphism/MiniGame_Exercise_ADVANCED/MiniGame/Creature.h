#ifndef Creature_h
#define Creature_h

#include <string>
#include <iostream>
using namespace std;
class Creature
{
protected:
	string creatureName;
	bool is_killed ;
	int x,y;

	int Health;
	int FirePower;
public:
	Creature(string iName,int x, int y, int Hlth, int Fpwr);
	string getName();

	bool SamePosition(int X, int Y);
	bool DecHealth(int h);	
	virtual bool Attack(Creature *) = 0; //Each creature has its own way of attack
	virtual void DrawOnScreen();
	void move(int x, int y);

	virtual ~Creature() { }
};

#endif
