#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
	int SSN[7];
	string name;
public:
	Customer();
	void read_info(string name, string number); //set all
	void print_info() const; // print all
	int* get_id() const;
	~Customer();

};

