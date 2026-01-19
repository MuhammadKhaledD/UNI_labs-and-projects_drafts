#pragma once
#include "mymap.h"

class Position
{
private:
	int x;
	int y;

public:
	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }

	int getX() const { return x; }
	int getY() const { return y; }

	bool operator== (const Position& obj)
	{
		if (this->getX() == obj.getX() && this->getY() == obj.getY())
			return true;

		return false;
	}

};

class Creature
{
private:
	string name;

public:
	void setName(string n) { name = n; }

	string getName() const { return name; }

	bool operator== (const Creature& obj)
	{
		if (this->getName() == obj.getName())
			return true;

		return false;
	}

};

class Dragon : public Creature
{};
class Player : public Creature
{};
class Monster : public Creature
{};
class Soilder : public Creature
{};

ostream& operator << (ostream& O, const Creature*& C)
{
	O << C->getName();
	return O;
}

ostream& operator << (ostream& O, const Position& C)
{
	O << "(" << C.getX() << " ," << C.getY() << ")\n";
	return O;
}

