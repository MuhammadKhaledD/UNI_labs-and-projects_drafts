#pragma once
#include "Customer.h"

class BankAcc {
private:
	const int id;
	double balance;
	Customer me;
public:
	BankAcc(int balance, Customer me);
	void set_balance(double s);
	void print_info();
	~BankAcc();
};

