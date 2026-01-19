#include "Student.h"

#include <iostream>
using namespace std;

int main()
{
	// cout << Student::count; // Error: inaccessible because private

	cout << Student::GetCount() << endl;  // Note: don't need an object to call static functions
	Student::StaticPrint();               // Note: don't need an object to call static functions

	cout << endl;

	Student S1;
	cout << S1.GetCount() << endl; // Note: can call a static function also using a calling object 
	                               // but can be called without it

	S1.StaticPrint();  // Note: can call a static function also using a calling object but can be called without it

}