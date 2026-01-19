#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(): uItemC (0), itemsCount(0)
{
	for (int i = 0; i < 15; ++i)
	{
		itemsArray[i] = nullptr;
	}
}

void ShoppingCart::printShoppingCart()
{
	cout << "Number of diffrent items: " << uItemC << ", Nmber of items: " << itemsCount << endl;

	for (int i = 0; i < uItemC; ++i)
	{
		itemsArray[i]->printinfo();
	}
}

void ShoppingCart::addItem(Item* m)
{
	if (uItemC < 15)
	{
		int d = m->getId();
		for (int i = 0; i < uItemC; ++i)
		{
			if (d == itemsArray[i]->getId())
			{
				int c = itemsArray[i]->getCount();
				itemsArray[i]->setCount(c + m->getCount());
				itemsCount += m->getCount();
				d = -1;
				break;
			}
		}

		if (d != -1)
		{
			itemsArray[uItemC] = m;

			itemsCount += m->getCount();
			++uItemC;
		}
	}
}

void ShoppingCart::remaoveItem(Item* m)
{
	int d = m->getId();
	int removeIndex = -1; // Track the index of the item to remove

	// Search for the item in the cart
	for (int i = 0; i < uItemC; ++i)
	{
		if (d == itemsArray[i]->getId())
		{
			removeIndex = i;
			break;
		}
	}

	// If the item is not found, display a message and return
	if (removeIndex == -1)
	{
		cout << "Item not found in cart!" << endl;
		return;
	}

	// Update the total count of items
	itemsCount -= itemsArray[removeIndex]->getCount();

	// Remove the item by replacing it with the last item in the array
	itemsArray[removeIndex] = itemsArray[uItemC - 1];
	itemsArray[uItemC - 1] = nullptr; // Clear the last slot
	--uItemC;                         // Decrement the count of unique items
}



