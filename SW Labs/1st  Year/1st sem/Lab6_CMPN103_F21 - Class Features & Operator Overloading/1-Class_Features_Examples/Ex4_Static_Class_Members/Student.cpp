#include "Student.h"

int Student::count = 0; // [Note]: the keyword "static" for members is NOT Written here 
	                    // (only inside class header)
						// [Note2]: the initialization of the static data member
						// is written outside the class using scope resolution
						// if you omit this line, you will get:
						// an "unresolved external symbol" error

Student::Student()
{
	count++;    // increment the static count
				// indicating that the number of created objects is increased
				// [Note]: count is a static data member
				// so it's created once for the class and shared among objects
				// actually, it doesn't need an object to exist
				// (it's created for the class as a whole and exist anyways)

	id = count; // take a copy of the current static count 
				// to be the id of the newly-constructed student
				// this trick is usually used to guarantee the uniqueness of the ids
				// [Note]: id (unlike the count) is a non-static data member
				// so it's NOT created once for the class and shared among objects
				// but each object has its own copy of id (non-static member)

	grade = 0; // initial value
}

Student::~Student()
{
	// [Note]: here we didn't decrement the static count
	// in order to guarantee the uniqueness even if some students are deleted

	// for example, we created students with ids: 1, 2 and 3 (current value of count is 3)
	// then if we deleted for example student with id = 1
	// the current value of the static count becomes 2 (if we decremented it in the destructor)
	// so the newly created student will take id = 3 which is already used before

	// so count here in this example represents the number of created students
	// not the students still alive
}

int Student::GetCount() // [Note]: the keyword "static" for members is NOT Written here 
	                    // (only inside class header)
{
	return count;
}

int Student::GetID()
{
	return id;
}

void Student::StaticPrint() // [Note]: the keyword "static" for members is NOT Written here 
	                        // (only inside class header)
{
	cout << count << endl;

	// Try to uncomment each of the following code lines
	// and see what happens

	// Line 1
	// cout << this->count << endl; // [Syntax Error]: "'this' can be used only inside a non-static member function"

	// Line 2
	// cout << this->id << endl;    // [Syntax Error]: "'this' can be used only inside a non-static member function"

	// Line 3
	// cout << id << endl; // [Syntax Error]: cannot access non-static members (that needs a calling object) 
	                       // inside static member function (that offers to work without the need of calling object)

	// Line 4
	// cout << grade << endl; // [Syntax Error]: same as previous error

	// Line 5
	// Print();       // [Syntax Error]: same as previous error
	                  // static functions cannot call non-static functions (without an object)

	// However, can access/call non-static members on another created objects 
	// (not on a calling object because it can exist without a calling object)

	Student S1;
	cout << S1.count << endl;
	cout << S1.id << endl;
	cout << S1.grade << endl;
}

void Student::Print() // non-static member function
{
	StaticPrint();  // non-static functions can call static functions
		            // because non-static functions have a calling object
		            // and the static functions exist anyways (if there is a calling object or not)
	cout << this->count << endl;  // no problem
	cout << count << endl;        // no problem
	cout << id << endl;
	cout << grade << endl;
}