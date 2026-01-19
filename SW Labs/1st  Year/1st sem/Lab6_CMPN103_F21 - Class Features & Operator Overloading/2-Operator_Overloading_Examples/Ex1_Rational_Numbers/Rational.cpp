#include "Rational.h"

void rational::fixSigns()
{
	if (den < 0) { num = -num; den = -den; }
}

void rational::removeGCD()
{
	int gcd = GCD(abs(num), den);
	if (gcd)  // same as: if (gcd != 0)
	{
	    // Note: will enter here even if gcd == 1
		num /= gcd; // same as: num = num / gcd;
		den /= gcd;
	}
	else // just in case if gcd returned by the function is 0
	{
		if (num) num = num > 0 ? 1 : -1;
		if (den) den = 1;
	}
}

int rational::GCD(int a, int b)
{
	int c;
	while (b)
	{
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}

rational::rational()
{
	num = 0;
	den = 1;
}

rational::rational(int n)
{
	num = n;
	den = 1;
}

rational::rational(int num, int den)
{
	this->num = num; // remove the name conflict with 'this'
	                 // otherwise, the variable of the function will be used
	this->den = den; // same idea of using 'this'
	fixSigns();  // use it to fix signed as explained before
	removeGCD(); // use it to remove the greatest common divisor of the rational number
}

rational::~rational()
{
}

int rational::getNumerator() const
{
	return num;
}

int rational::getDenominator() const
{
	return den;
}

// [Operators Overloaded as Members] ----------------------------------

// === GROUP 1 ===

// [NOTE]:
// we made the return type (rational) to be able to write something like:
// cout << a + b;  OR  c = a + b  OR  d = c + a + d; , ...etc.
// (+ has left-to-right associativity)
rational rational::operator + (const rational & other) const
{
	return rational(num*other.den + den*other.num, den*other.den);  // the equation of adding two rationals
	// [NOTE]: return rational( . . . ) is a nameless object of class rational
	// the return type is by val (rational) not (rational &)
	// which will return a new temp rational object
	// so, c + a + d: will: 
	// + has left-to-right associativity so,
	// -first perform (c + a) and returns temp rational with the result
	// -then (temp + d) is executed and returns another temp with result
}

// same comments as previous function
rational rational::operator - (const rational & other) const
{
	return rational(num*other.den - den*other.num, den*other.den);
}

// same comments as previous function
rational rational::operator * (const rational & other) const
{
	return rational(num*other.num,den*other.den);
}

// same comments as previous function
rational rational::operator / (const rational & other) const
{
	return rational(num*other.den,den*other.num);
}

// === GROUP 4 ===

// post-fix operator (a++) --> "take a copy THEN increment"
// post-fix operator --> needs a dummy int parameter
// we made the return type (rational) to be able to write something like:
// cout << a++;  OR  b  = a++; ...etc.
// [NOTE]: post-fix operator has left-to-right associativity
// unlike the pre-fix which has right-to-left associativity
rational rational::operator ++ (int)
{
	rational temp = *this; // take copy before incrementing
	                       // Note: don't need to define "copy constructor"
	                       // for class rational, can use the one of the compiler
	                       // which makes member-wise assignment
	*this = rational(num + den, den); // make the calling object itself (*this)
	                                  // equal a new rational object with the incremented value
	                                  // Note: we used "the = operator" of the compiler
	                                  // which makes member-wise assignment
	return temp; // return the copy before incrementing
	// return type is by value (rational) not (rational &)
	// so a new temp object is returned
}

// comments as the previous function
rational rational::operator -- (int)
{
	rational temp = *this;
	*this = rational(num - den, den);
	return temp;
}

// pre-fix operator (++a) --> "increment THEN return"
// [NOTE]: pre-fix has right-to-left associativity <------ diffferent associativity
rational rational::operator ++ ()
{
	return (*this = rational(num + den, den));  
	// the preious statement makes 3 things (in order):
	// 1- rational(num + den, den) --> new rational number with incremented value
	// 2- makes the calling object (*this) equals the incremented rational
	// 3- return the calling object (after being incremented in prev. steps)
	
	// return type is by value (rational) not (rational &)
	// so a new temp object is returned
}

// comments as the previous function
rational rational::operator -- ()
{
	return (*this = rational(num - den, den));
}

// === GROUP 5 ===

// [NOTE]:
// we made the return type (rational) to be able to write something like:
// cout << -a;  OR  b = -a; ...etc.
// (unary minus - has right-to-left associativity)  <------ diffferent associativity
rational rational::operator - () const
{
	return rational(-num,den);
	// return type is by value (rational) not (rational &)
	// so a new temp object is returned
}

// === GROUP 6 ===

// [NOTE]:
// we made the return type (rational) to be able to write something like:
// cout << a += b;  OR  c = a += b  OR  a += b += c , ...etc.
// (+= has right-to-left associativity)  <------ diffferent associativity
rational rational::operator += (const rational & other)
{
	return (*this = *this + other); // 
	// the preious statement makes 3 things (in order):
	// 1- *this + other --> [IMPORTANT] uses the + operator 
	//     that we has overloaded before for rational class
	//     to add the passed rational (other) to the calling object (*this)
	// 2- (*this = . . .) --> makes the calling object (*this) equals the addition result
	// 3- return the updated calling object
	
	// return type is by value (rational) not (rational &)
	// so a new temp object is returned

	// [Note]:
	// For a statement like: a += b += c;
	// we do NOT need to make the function return the calling object by ref.

	// Here, what will happen when the function returns by value:
	// operator += is right-to-left associative
	// so, (b += c) will be executed first
	// and a copy of the updated calling object (b) is returned
	// this copy will be the right operand of the first += operator (a += ...)
	// which will change the calling object (a)
	// Here, we don't needto return (b) by reference  in (b += c) 
	// because it will not be changed in the next executed cascaded operation
	// it's only the right operand that only its "value" is needed (not changed)
}

// comments as the previous function
rational rational::operator -= (const rational & other)
{
	return (*this = *this - other); // use the - operator that we overloaded before
}

// comments as the previous function
rational rational::operator *= (const rational & other)
{
	return (*this = *this * other); // use the * operator that we overloaded before
}

// comments as the previous function
rational rational::operator /= (const rational & other)
{
	return (*this = *this / other); // use the / operator that we overloaded before
}

// === GROUP 7 ===

bool rational::operator == (const rational & other) const
{
	return num==other.num && den==other.den;
}

bool rational::operator != (const rational & other) const
{
	return ! (*this == other); // use the == operator that we overloaded before
}

// === GROUP 8 ===

bool rational::operator < (const rational & other) const
{
	return num*other.den < den*other.num;
}

bool rational::operator > (const rational & other) const
{
	return num*other.den > den*other.num;
}

bool rational::operator <= (const rational & other) const
{
	return (*this < other) || (*this == other);
	// implemented using operators < and == that we overloaded before
}

bool rational::operator >= (const rational & other) const
{
	return (*this > other) || (*this == other);
	// implemented using operators > and == that we overloaded before
}

