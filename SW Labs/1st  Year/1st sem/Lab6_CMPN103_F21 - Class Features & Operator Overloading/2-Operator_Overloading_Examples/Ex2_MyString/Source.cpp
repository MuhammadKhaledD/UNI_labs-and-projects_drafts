#include "MyString.h"
#include <iostream>

using namespace std;

// ============== Global Functions ================

ostream & operator<<(ostream & out, const MyString & str)
{
	return out << str.cArr;
}

istream & operator >> (istream & in, MyString & str)
{
	char ch_arr[256]; // Assume 256 is the max size (so max no of chars is 255)
	in >> ch_arr;
	str = ch_arr;
	return in;
}

MyString operator+(const char * ch_arr, MyString & str)
{
	MyString result;
	result += str;
	return result;
}

// ============== Main Function ================

int main()
{
	MyString s = "Pello"; // this uses the conversion constructor 
	                      // (from char * to MyString)

	s[0] = 'H'; // Try to comment the overoaded operator:
				// char & MyString::operator[](int index)
				// and keep the:
				// char MyString::operator[](int index) const
				// this statement will generate an error
				// because the second operator returns an rvalue
				// cannot be on the LHS
	            // --> don't forget to uncomment it again to continue the main

	cout << s << endl;  // will output "Hello" not "Pello"
					    // because the the previous statement uses the operator
						// that returns the char by ref (lvalue) 
	                    // so when we make it = 'H', 
	                    // it's changed inside s

	const MyString const_s = s; // this uses the copy constructor 
	
	cout << const_s[0]; // this will call the const version of []
	                    // because const_s is a const object

	// Try to uncomment the following statement
	/*
	const_s[0] = 'T'; // this will generate an error
	                  // because const object will call the const version of []
	                  // which returns an rvalue that cannot appear in LHS
	*/

	MyString s2;   // this uses the default constructor

	s2 = s + " ";  // this statement will use the following:
	               // 1- the conversion constructor (from char *)
	               // to convert " " char * to MyString object
	               // to be able to use the + that works on 2 MyString objects
	               // 2- the + operator that works on 2 MyString objects
	               // and returns the result MyString object
	               // 3- the assignment operator to make s2 equal
	               // the result MyString object of the addition
	               // [Note]: the destructor of the MyString 
	               // created from " " will called too 
	               // [Note]: the copy constructor will be called 
	               // for each pass or return by value 
	               // or declaration and init. in same line

	s2 += "World";

	MyString s3 = "Hi, "; // this uses the conversion constructor (from char *)

	s3 += s += s2; // after executing this statement:
	               // 1- s will contain s + s2 
	               // (and a copy of the updated s is returned)
	               // 2- s3 will contain s3 + the updated s

	cout << s << endl;
	cout << s3 << endl;

	cout << s2 + "!" << endl;
	s2 = "Enter your name: ";
	cout << s2;
	cin >> s;
	cout << "Hello " + s << endl;

	int size = s.getLength();
	cout << "Your name is " << size << " character(s) long" << endl;
	if (size > 0)
	{
		cout << "The last character of your name is " << s[size - 1] << endl;
		s[size - 1] = 'z';
		cout << "if we change it to z, you name will be " << s << endl;
	}
}