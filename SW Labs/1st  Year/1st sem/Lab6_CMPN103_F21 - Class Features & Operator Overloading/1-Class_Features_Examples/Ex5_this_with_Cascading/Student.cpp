#include "Student.h"


Student::Student(float g)
{
	grade = (g >= 0 ? g : -g);
}


void Student::AddToGrades_No(float g)
{
	grade += (g >= 0 ? g : -g);
}

// [Note]: the return type is by value (Student)
Student Student::AddToGrades_Val(float g)
{
	grade += (g >= 0 ? g : -g);
	return *this; // return a "copy" of the calling object after being updated
	              // because the return type of the function is by value
}


// [Note]: the return type is by reference (Student &)
Student& Student::AddToGrades_Ref(float g)
{
	grade += (g >= 0 ? g : -g);
	return *this; // return the calling object "itself" after being updated
	              // because the return type of the function is by reference
}

Student& Student::ReturnLocal_By_Ref()
{
	// return a local copy of the calling object by ref
	// this function will cause a problem in the main

	// because it returns a reference to a local variable
	// that will destructed with the end of function scope

	Student copy;
	copy = *this;
	return copy;

	// if you want to correct this function, you have one of 2 ways:

	// 1- return * this; and the return type remains by ref 
	// --> this will return the calling obj itself

	// 2- return *pcopy; where "pcopy" is ...
	// a pointer to a Student allocated dynamically with "new" keyword
	// and its object equals the calling object (*pcopy = *this)
	// --> this will return a copy of the calling obj
	// but a copy that is alive beyond the function scope till deleted using delete statement
}

void Student::Print()
{
	cout << "grade = " << grade << endl;
}
