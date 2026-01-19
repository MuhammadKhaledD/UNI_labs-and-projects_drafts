#pragma once

#include <iostream>
using namespace std;

class Student
{
	static int count; // static data member  (note: it's private here in the example)
	                  // contains the number of created students
	                  // initially is 0 and incremented in the constructor
	int id; // non-static data member
	        // contains the id of the student
	float grade; // non-static data member
	             // contains the student grade
public:
	Student();
	~Student();

	static int GetCount(); // static member function

	int GetID(); // non-static member function

	static void StaticPrint(); // static member function

	void Print(); // non-static member function

};

