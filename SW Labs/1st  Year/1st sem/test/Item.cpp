#include "Item.h"

Item::Item(int i, int c) : id(i), count(c) {};

int Item::getCount() const 
{ 
	return count;
}

int Item::getId() const
{
	return id;
}

void Item::setCount(int c)
{
	count = c;
}

void Item::printinfo() const
{
	cout << "Item id: " << getId() << ", Item count: " << getCount() <<endl;
}
