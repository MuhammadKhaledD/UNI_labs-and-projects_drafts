#include "Class.h"

Class::Class()
{
	real = 0;
	img = 0;
}

Class::Class(double r, double i)
{
	real = r;
	img = i;
}

double Class::getReal()
{
	return real;
}

double Class::getImg()
{
	return img;
}

void Class::setValue(double r, double i)
{
	real = r;
	img = i;
}

void Class::print()
{
	cout << "The real part is = " << real << endl;
	cout << "The imaginary part is = " << img << endl; 
}

bool Class::isReal()
{
	if (img > -.0001 && img < .0001)
		return true;
	return false;
}

bool Class::isImg()
{
	if (real > -.0001 && real < .0001)
		return true;
	return false;
}

void Class::add(double i)
{
	img += i;
}

