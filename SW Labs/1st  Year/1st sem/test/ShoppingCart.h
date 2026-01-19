#pragma once
#include "Item.h"

class ShoppingCart
{
private:
	int uItemC;
	int itemsCount;
	Item* itemsArray[15];

public:
	ShoppingCart();

	void printShoppingCart ();
	void addItem(Item*);
	void remaoveItem(Item*);
};

