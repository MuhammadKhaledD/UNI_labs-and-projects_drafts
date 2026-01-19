#pragma once

#include <iostream>
using namespace std;

// This class, MyString, that represents strings implemented internally as char array
class MyString
{
	char * cArr; // the internal char array
public:
	MyString(); // default constructor

	MyString(const char * ch_arr); // conversion constructor (constructor that takes 1 parameter)
	                               // to convert from (char *) to (MyString)

	MyString(const MyString& other); // copy constructor
									 // the shallow copy (the default behavior of the compiler's copy ctor) 
	                                 // will only copy the pointer (cArr = other.cArr)
	                                 // which will make the 2 pointers points to the same array
	                                 // so it won't work here since we need to 
	                                 // allocate a new character array to hold the copied data.

	char& operator[](int index); // subscript operator to access the characters 
	                             // for reading or "writing"

	char operator[](int index) const; // this is used to read character from (const MyString) object
	                                  // since the previous function above 
	                                  // is inaccessible from (const MyString)
	                                  // because the prev. fn. is non-const function
	                                  // cannot be called using const objects

	                                  // note too that the return type becomes by value
	                                  // in order to return only a copy of the char
	                                  // in order not to be changed inside

	MyString operator+(const MyString& other) const; // this is used to concatenate 2 strings 
	                                                 // and return the result string
	                                                 // [Note]: the 2 input strings are not changed
	                                                 // [Note]: this operator will work with 
	                                                 // (MyString + MyString) and 
	                                                 // (MyString + const char *) too 
	                                                 // because we have the conversion constructor :
	                                                 // MyString(const char *)

	MyString operator+=(const MyString& other);   // this is used to concatenate/append the passed string
	                                              // to the calling object (the left operand)
	                                              // [Note]: the left operand is changed
	                                              // [Note]: we need to overload operator += explicitely
	                                              // overloading the + operator and the = operator 
	                                              // doesn't make += overloaded (cannot use it)
	                                              // in general, operators must be overloaded explicitely
	
	MyString operator=(const MyString& other); // assignment operator: 
	                                            // because shallow copies 
	                                            // (the default behavior of the comiler's operator)
	                                            // will not do the job
	                                            // because there is a pointer data member
	                                            // the dangling pointer problem described before

	MyString operator=(const char * ch_arr);   // this can be omitted 
												// because we already have: 
												// 1- the constructor MyString(const char *) and 
												// 2- the operator=(const MyString&), 
												// but anyway, this is more efficient

	// other member functions

	int getLength() const;
	~MyString();

	// =========== Friend Functions (NOT MEMBERS) ===========
	
	friend ostream& operator << (ostream& out, const MyString& string);
	friend istream& operator >> (istream& in, MyString& string);

	friend MyString operator+ (const char* ch_arr, MyString& string); 
	               // We need this because the operator + declared above as member 
	               // will NOT work for (const char * + MyString).
};

