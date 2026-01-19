#include "ShoppingCart.h"

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main()
{
	test1();
	cout << "==========================================================================================\n";
	test2();
	cout << "==========================================================================================\n";
	test3();
	cout << "==========================================================================================\n";
	test4();
	cout << "==========================================================================================\n";
	test5();
	cout << "==========================================================================================\n";
	test6();
	cout << "==========================================================================================\n";

	return 0;
}

void test1()
{
	Item i(1, 10);
	Item j(2, 20);

	i.printinfo(); j.printinfo();
}
void test2()
{
	Item* j[20];
	ShoppingCart s;
	for (int i = 0; i < 20; ++i)
	{
		j[i] = new Item(i, 1);
		s.addItem(j[i]);
	}

	s.printShoppingCart();

	for (int i = 0; i < 20; ++i)
	{
		delete j[i];
	}
}
void test3()
{
	ShoppingCart s;
	Item i(1, 15);
	Item j(2, 1);
	s.addItem(&i);
	s.addItem(&j);
	s.printShoppingCart();
}
void test4()
{
	Item* j[3];
	ShoppingCart s;
	for (int i = 0; i < 3; ++i)
	{
		j[i] = new Item(1, i+1);
		s.addItem(j[i]);
	}

	s.printShoppingCart();

	for (int i = 0; i < 3; ++i)
	{
		delete j[i];
	}
}
void test5()
{
	ShoppingCart s;
	Item i(4, 4);
	s.addItem(&i);
	s.printShoppingCart();
	s.remaoveItem(&i);
	s.printShoppingCart();
}
void test6()
{
	ShoppingCart s;
	Item i(1, 1);
	Item j(2, 1);
	Item k(3, 1);
	s.addItem(&i);
	s.addItem(&j);
	s.printShoppingCart();
	s.remaoveItem(&k);
	s.printShoppingCart();
	s.remaoveItem(&i);
	s.printShoppingCart();
}