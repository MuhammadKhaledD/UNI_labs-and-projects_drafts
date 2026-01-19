#include "Class.h"

Class add(Class a, Class b)
{
	double real = a.getReal() + b.getReal();
	double img = a.getImg() + b.getImg();

	Class c(real, img);

	return c;

}

int main()
{
	Class c1(1, 0), c2(3, 4);

	c1.print();
	cout << "\n====================================================\n";
	c2.print();
	cout << "\n====================================================\n";

	if (c1.isReal())
		cout << "C1 is real\n";
	else if (c1.isImg())
		cout << "C1 is imaginary\n";
	else
		cout << "C1 is complex\n";

	cout << "\n====================================================\n";

	if (c2.isReal())
		cout << "C2 is real\n";
	else if (c2.isImg())
		cout << "C2 is imaginary\n";
	else
		cout << "C2 is complex\n";

	cout << "\n====================================================\n";

	c1 = add(c1, c2);
	c1.print();
	cout << "\n====================================================\n";
	c2.print();
	cout << "\n====================================================\n";

	Class c3;
	c3 = add(c1, c2);
	c3.print();

	return 0;
}
