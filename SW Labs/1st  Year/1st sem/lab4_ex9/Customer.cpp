#include "Customer.h"

Customer::Customer() { cout << "Customer Constructor is called\n"; }

void Customer::read_info(string name, string number) {
	
	this->name = name;

	if (number.length() != 7) {

		cout << "invalied SSN numbers\n";

		for (int i = 0; i < 7; ++i)
			SSN[i] = 0;

	}
	else
		for (int i = 0; i < 7; ++i)
			SSN[i] = number[i];
}

void Customer::print_info() const {
	
	cout << "name: " << this->name << ", SSN: " << this->SSN << endl;
}

int* Customer::get_id() const
{
	return SSN[];
}

Customer::~Customer() { cout << "Customer Destructor is called\n"; }

