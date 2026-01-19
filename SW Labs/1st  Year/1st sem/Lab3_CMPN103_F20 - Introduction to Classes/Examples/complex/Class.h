#ifndef _CLASS_H_
#define _CLASS_H_

#include <iostream>

using namespace std;

class Class
{
private:

	double real, img;

public:

	Class();
	Class(double r, double i);
	double getReal();
	double getImg();
	void setValue(double r, double i);
	void print();
	bool isReal();
	bool isImg();
	void add(double i);

};
#endif

