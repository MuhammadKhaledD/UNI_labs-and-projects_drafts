#include "MyString.h"
#include <cstring>

// default constructor
MyString::MyString()
{
	// creat a char array that contains only the null char
	cArr = new char[1];
	*cArr = '\0';
}

// conversion constructor from char *
MyString::MyString(const char * ch_arr)
{
	// allocate the array
	int size = strlen(ch_arr);
	cArr = new char[size+1]; 

	// copy the array
	strcpy_s(cArr, size + 1, ch_arr);
}

// copy constructor
MyString::MyString(const MyString & other)
{
	// allocate the array
	int size = other.getLength(); // getLength is a member fn. inside MyString class
	                              // cannot use strlen on an object of our class MyString
	cArr = new char[size+1];

	// copy the array
	strcpy_s(cArr, size + 1, other.cArr); // note that we copy from other.cArr (not other)
}

// subscript operator for reading and writing
// so the return is by ref (returns an lvalue) and . . .
// the function is non-const
// note: this function cannot be used with const object
// note: this function can be used as follows: MyStr1[3] = 't';
// I mean can appear in the LHS because it returns an lvalue
char & MyString::operator[](int index)
{
	return cArr[index];
}

// subscript operator for reading only
// so the retun is by value (only a copy of the char; returns an rvalue) and . . .
// the function is const
// note: this function CAN be used with const object
// note: this function CANNOT be used as follows: MyStr1[3] = 't'; --> ERROR
// It cannot appear in the LHS because it returns an rvalue
char MyString::operator[](int index) const
{
	return cArr[index];
}

// concatenate two strings and returns the result string
// doesn't change the operands
MyString MyString::operator+(const MyString & other) const
{
	MyString result = *this; // make temp object for the result
	                         // make it initially contains a copy of the calling object
	return result += other;  // append the other object to the result
	                         // using the += operator overloaded below
	                         // note that the calling object (the left operand)
	                         // is not changed inside the function, 
	                         // so we made it const fn.
}

// concatenate two strings and updates the left operand with the result
// the left operaand is changed
MyString MyString::operator+=(const MyString & other)
{
	int size = getLength(); // call getLength() on the calling object
	int othersize = other.getLength(); // call getLength on the other object

	// allocate the array that will contain the 2 appended strings
	char* newstr = new char[size + othersize + 1]; 

	// copy cArr of the calling object to the newstr using strcpy_s fn
	strcpy_s(newstr, size + othersize + 1, cArr);

	// concatenate cArr of the other object to the newstr using strcat_s fn
	strcat_s(newstr, size + othersize + 1, other.cArr);

	// deallocate the old cArr of the calling object
	// because cArr will point to the new concatenated array, newstr
	delete[] cArr;

	// make cArr of the calling object point to the new array
	cArr = newstr;

	// return a copy of the calling object (by value) after being changed
	// for further cascading
	return *this;

	// [Note]: the return here is NOT needed by ref.
	// because if you write this statement in the main:
	// a += b += c; (where a, b and c are MyString objects)
	// += is right-to-left associative
	// so the previous statement will be executed in the following order:
	// 1- (b += c) which will append the c to b (b is changed)
	// then a copy of b is retuned (by value)
	// which will be used as the right operand of 
	// 2- (a += . . .)
	// don't need to return the b itself only a copy is enough
	// because it will be only "used" in the a += ... operation
	// not "changed" in it

	// [Note]: it's better to make the return type:
	// (const MyString &) instead of (String)
	// to make remove the overhead of making a new copy 
	// and calling the copy constructor
}

MyString MyString::operator=(const MyString & other)
{
	// deallocate the previous array
	// before making cArr points to new array
	delete[] cArr;

	// allocate the new array and make cArr points to it
	int size = other.getLength();
	cArr = new char[size + 1];

	// copy from cArr of other to cArr of the calling obj
	strcpy_s(cArr, size + 1, other.cArr);

	// return a copy of the calling object after being changed
	// for further cascading
	return *this;

	// [Note] the return type is by value 
	// for the same reason mentioned in the +=

	// [Note]: it's better to make the return type:
	// (const MyString &) instead of (String)
}

// can be omitted as mentioned in the .h
MyString MyString::operator=(const char * ch_arr)
{
	// deallocate the previous array
	// before making cArr points to new array
	delete[] cArr;

	// allocate the new array and make cArr points to it
	int size = strlen(ch_arr);
	cArr = new char[size + 1];

	// copy from cArr of other to cArr of the calling obj
	strcpy_s(cArr, size + 1, ch_arr);

	// return a copy of the calling object after being changed
	// for further cascading
	return *this;
}

int MyString::getLength() const
{
	return strlen(cArr);
}

MyString::~MyString()
{
	delete[] cArr;
}
