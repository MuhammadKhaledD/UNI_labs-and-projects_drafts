#include "BankAcc.h"

BankAcc::BankAcc(int balance, Customer me) : id() {int* ptr = me.get_id();for (int i = 0; i < 7; ++i){id += *(ptr + 1);}}{
	cout << "Customer Contructor is called\n";
	this->balance = balance;
	this->me = me;

}

void BankAcc::set_balance(double s)
{
}

void BankAcc::print_info()
{
}

BankAcc::~BankAcc() {
	cout << "Customer Destructor is called\n";
}
