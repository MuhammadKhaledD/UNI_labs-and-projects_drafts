#include <iostream>
#include "Rational.h"

using namespace std;

// 1- [The Prototypes of the Operators Overloaded as "Global"]  --------------------------------

// --> We will put the definition below the main

// NOTE: It's better to read the main first with the comments written inside it
//       to be able to decide which operators we need and if we can make it global or member

ostream& operator<<(ostream& output, const rational& number);
istream& operator>>(istream& input, rational& number);

rational operator+(int integer, const rational& number);
rational operator-(int integer, const rational& number);
rational operator*(int integer, const rational& number);
rational operator/(int integer, const rational& number);

bool operator==(int integer, const rational& number);
bool operator!=(int integer, const rational& number);
bool operator<(int integer, const rational& number);
bool operator>(int integer, const rational& number);
bool operator<=(int integer, const rational& number);
bool operator>=(int integer, const rational& number);

//////////////////////////////////////////////////////////////////////

// 2- [The Main Function] --------------------------------

int main()
{
	// --> Note the comment beside each statement
	// --> that describes the needed function of each statement 
	// Note: in the comments, we only mention the functions that are not mentioned in prev. statements

	rational a(2, 3), b = 5, c(4); // 1-rational a(2, 3): needs constructor for rationall that takes 2 int
	                               // 2-rational b = 5; : needs also a "conversion constructor" to rational from passed int
	                               //  which is: rational::rational(int n)
	                               //  cannot use convertion operator here 
	                               //  because the 'from type' is int (built-in)
	                               // 3-rational c(4) : will use the constructor defined for object b
	
	// === GROUP 0 ===

	cout << "a = " << a << endl; // this line needs to overload << (left: ostream &) (right: rational)
	                             // and (return: ostream &) to be cascaded later (with endl in this statement)
	                             // can be overloaded only as global 
	                             // because we cannot write it inside the left class (ostream)
	cout << "b = " << b << endl; // same as previous
	
	cout << endl;

	// === GROUP 1 ===

	cout << "a+b = " << a + b << endl; // this line needs to overload + (left: rational) (right: rational) 
	                                   // and (return: depending on the meaning; can be: "rational" here) 
	                                   // return cannot be void to be able to print it in the cout
	                                   // can be overloaded as global or member in rational (the left class)
	cout << "a-b = " << a - b << endl; // same as previous but for operator -
	cout << "a*b = " << a * b << endl; // same as previous but for operator *
	cout << "a/b = " << a / b << endl; // same as previous but for operator /

	cout << endl;

	// === GROUP 2 ===

	cout << "a+5 = " << a + 5 << endl; // this line needs one of the following solutions: 
	                                   // Sol_1: to overload + (left: rational) (right: "int" this time) <----
	                                   //   and (return: depending on the meaning; can be: "rational" here) 
	                                   //   return cannot be void to be able to print it in the cout
									   //   can be overloaded as global or member in rational (the left class)
	                                   // Sol_2: to make a conversion constructor to rational from int
  	                                   //   which we needed and implemented before
									   //   so this statmens will be executed as follows:
									   //   1- convert: int 5 to temp rational ("implicitely" - max one level of conversion)
									   //   2- add: a + the temp rational 
									   //      using the + operator of left rational and right rational defined before
	                                   // Here, we used Sol_2 because we already defined all it needs
	cout << "a-5 = " << a - 5 << endl; // same as previous but for operator -
	cout << "a*5 = " << a * 5 << endl; // same as previous but for operator *
	cout << "a/5 = " << a / 5 << endl; // same as previous but for operator /

	cout << endl;

	// === GROUP 3 ===

	cout << "5+b = " << 5 + b << endl; // this line needs to overload + (left: "int") (right: rational)
	                                   // and (return: depending on the meaning; can be: "rational" here) 
	                                   // return cannot be void to be able to print it in the cout
									   // can be overloaded only as global in this case
	                                   // because we cannot write it inside the left class (int --> built-in data type)
	cout << "5-b = " << 5 - b << endl; // same as previous but for operator -
	cout << "5*b = " << 5 * b << endl; // same as previous but for operator *
	cout << "5/b = " << 5 / b << endl; // same as previous but for operator /

	cout << endl;

	// === GROUP 4 ===
	
	cout << "a++ = " << a++ << endl; // this line needs to overload the unary postfix ++ 
	                                 // (the operand: rational)
	                                 // (the return: depending on the meaning; can be: "rational" here) 
	                                 // return cannot be void to be able to print it in the cout
	                                 // can be overloaded as global or member in rational (the unary operand class)
	                                 // Note: postfix needs a dummy int in the parameters to distinguish it from prefix
	cout << "++a = " << ++a << endl; // this is the prefix operator ++
	                                 // same comments as previous
	                                 // but there is NO dummy int should be passed to it
	cout << "a-- = " << a-- << endl; // same comments as "postfix" operator ++
	cout << "--a = " << --a << endl; // same comments as "prefix" operator ++
	
	cout << endl;

	// === GROUP 5 ===
	
	cout << "-a = " << -a << endl; // this line needs to overload the unary operator - 
	                               // (the operand: rational)
	                               // (the return: depending on the meaning; can be "rational" here) 
	                               // return cannot be void to be able to print it in the cout
	                               // can be overloaded as global or member in rational (the unary operand class)
	cout << "-b = " << -b << endl; // same as previous
	
	cout << endl;

	// === GROUP 6 ===

	cout << "a += b =" << (a += b) << endl; // this line needs to overload the binary operator +=
	                                        // (the left operand: rational)
	                                        // (the right operand: rational)
	                                        // (the return: depending on the meaning; can be "rational" here) 
	                                        // return cannot be void to be able to print it in the cout
	                                        // can be overloaded as global or member in rational (the left operand class)
	                                        // Note: we need to put (a += b) between ( ) here
	                                        // because << has higher precedence than +=
	cout << "a += b += c =" << (a += b += c) << endl;  // same as previous
	cout << "a -= b =" << (a -= b) << endl;  // same as previous
	cout << "a *= b =" << (a *= b) << endl;  // same as previous
	cout << "a /= b =" << (a /= b) << endl;  // same as previous

	// === GROUP 7 ===

	cout << "a==b = " << (a == b) << endl; // this line needs to overload == operator
	                                       // (left operand: rational) (right operand: rational)
	                                       // (return: depending on the meaning; can be "bool" here)
	                                       // can be overloaded as global OR ...
	                                       // OR member in rational (the left operand class)
	cout << "9==b = " << (9 == b) << endl; // this line needs to overload == operator
	                                       // (left operand: "int") (right operand: rational)
	                                       // (return: depending on the meaning; can be "bool" here)
									       // can be overloaded only as global in this case
	                                       // because we cannot write it inside the left class (int --> built-in data type)
	cout << "b==9 = " << (b == 9) << endl; // this line needs one of the following solutions
	                                       // 1- to overload == operator
	                                       //    (left operand: rational) (right operand: "int")
	                                       //    (return: depending on the meaning; can be "bool" here)
	                                       //    can be overloaded as global OR ...
	                                       //    OR member in rational (the left operand class)
	                                       // 2- use the previously defined 'conversion constructor'
										   // that converts from int to rational
	                                       // to convert from int 5 to rational of 9
	                                       // then the == operator that compares 
	                                       // 2 rational numbers can be used
	                                       // that's the solution we used here
	cout << "a!=b = " << (a != b) << endl; // same comments as: cout << "a==b = " << (a == b) << endl;
	cout << "9!=b = " << (9 != b) << endl; // same comments as: cout << "a==b = " << (9 == b) << endl;
	cout << "b!=9 = " << (b != 9) << endl; // same comments as: cout << "a==b = " << (b == 9) << endl;
	cout << endl;

	// === GROUP 8 ===

	cout << "4<b = " << (9 < b) << endl;   // same comments as: cout << "9==b = " << (9 == b) << endl;
	cout << "4>b = " << (9 > b) << endl;   // same comments as: cout << "9==b = " << (9 == b) << endl;
	cout << "4<=b = " << (9 <= b) << endl; // same comments as: cout << "9==b = " << (9 == b) << endl;
	cout << "4>=b = " << (9 >= b) << endl; // same comments as: cout << "9==b = " << (9 == b) << endl;

	cout << "b<4 = " << (b < 9) << endl;  // same comments as: cout << "b==9 = " << (b == 9) << endl;

	cout << "a<b = " << (a < b) << endl;   // same comments as: cout << "a==b = " << (a == b) << endl;
	cout << "a>b = " << (a > b) << endl;   // same comments as: cout << "a==b = " << (a == b) << endl;

	cout << endl;

	// === GROUP 0 - Part 2 ===

	cout << "Enter a Rational Number (format: Numerator Denominator): ";
	cin >> a; // this line needs to overload >> (left: istream&) (right: rational)
	          // and (return: can be void here to make: cin >> a; working) 
	          // but better to make the return: (istream &) to be able to cascase to: cin >> a >> b;
	          // can be overloaded only as global 
	          // because we cannot write it inside the left class (istream)

	cout << "You entered: " << a << endl;

	return 0;
}

//////////////////////////////////////////////////////////////////////

// 3- [The Definition of the Operators Overloaded as "Global"]  --------------------------------

// === GROUP 0 ===

// [NOTE]: ostream can NOT be passed or returned by val 
// because its copy constructor is disabled
// [NOTE]: we make the return (ostream &) not (void)
// to be able to cascade: cout << a << b; 
// [NOTE]: << has left-to-right associativity
ostream & operator << (ostream & output, const rational& number)
{
	if (number.num == 0 || number.den == 1)
		return output << number.num; // this statements returns output itself after writing on it
	else
		return output << number.num << '/' << number.den; // same as revious comment
}

// same comments as previous function
istream& operator >> (istream& input, rational& number)
{
	input >> number.num >> number.den;
	number.fixSigns();
	number.removeGCD();
	return input;
}

// === GROUP 3 ===

// [NOTE]:
// we made the return type (rational) to be able to write something like:
// cout << 5 + b;  OR  c = 5 + b, ...etc.
// (+ has left-to-right associativity)
rational operator + (int integer, const rational& number)
{
	return rational(integer*number.den + number.num, number.den); // the equation of adding an int with rational
	// [NOTE]: return rational( . . . ) is a nameless object of class rational
	// the return type is by val (rational) not (rational &)
	// which will return a new temp rational object

	// Q1: What about this statement?? How the "right" hand side is executed??
	//    d = 5 + a + d;

	// + has left-to-right associativity so,
	// -first perform (5 + a) and returns temp rational with the result
	// -then (temp + d) is executed which uses the overloaded +
	//  that take rational number in its left and right operand

	// Q2: What about this statement?? How the "right" hand side is executed??
	//    d = 5 + (6 + d);
	
	// -parentheses first: (6 + d) which returns temp rational
	// -then (5 + temp) which returns temp rational with the result

	// Q3: What about: 	d = 5 + 6 + d; ??

	// NOTE: in the rational class you don't need to overload the = operator
	// because the class doesn't have pointer data members that need deep copying
	// so, we can use the default assignment operator generated by the compiler
}

// same comments as previous function
rational operator - (int integer, const rational& number)
{
	return rational(integer*number.den - number.num, number.den);
}

// same comments as previous function
rational operator * (int integer, const rational& number)
{
	return rational(integer * number.num, number.den);
}

// same comments as previous function
rational operator / (int integer, const rational& number)
{
	return rational(integer * number.den, number.num);
}

// === GROUP 7 ===

bool operator == (int integer, const rational& number)
{
	return 1 == number.den && integer == number.num; 
}

bool operator != (int integer, const rational& number)
{
	return ! (integer == number); // use the == operator that we overloaded before
}

// === GROUP 8 ===

bool operator < (int integer, const rational& number)
{
	return integer*number.den < number.num;
}

bool operator > (int integer, const rational& number)
{
	return integer*number.den > number.num;
}

bool operator <= (int integer, const rational& number)
{
	return (integer < number) || (integer == number);
	// implemented using operators < and == that we overloaded before
}

bool operator >= (int integer, const rational& number)
{
	return (integer > number) || (integer == number);
	// implemented using operators > and == that we overloaded before
}

