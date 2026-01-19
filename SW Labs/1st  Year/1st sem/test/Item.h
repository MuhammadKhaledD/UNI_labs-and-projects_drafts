#pragma once
#include <iostream>
using namespace std;

class Item
{
private:
	const int id;
	int count;

public:
	Item(int i, int c);

	int getCount() const;
	int getId() const;
	void setCount(int c);

	void printinfo () const;

};

