#include <iostream>
using namespace std;

#include "Student.h"

int main()
{
	Student s1;
	s1.AddToGrades_No(1);
	// Try to uncomment the following line:
	// s1.AddToGrades_No(1).AddToGrades_No(10); // error

	Student s2;
	s2.AddToGrades_Val(2).AddToGrades_Val(20); 
	s2.Print(); // 2 is printed
	            // should be 22
	            // but 2 because by value

	Student s3;
	s3.AddToGrades_Ref(3).AddToGrades_Ref(30); 
	s3.Print(); // 33 is printed

	s3.AddToGrades_Ref(300).Print(); // 333 is printed

	// Q: what if we want this statement to be valid? How should we modify function Print()??
	// s3.AddToGrades_Ref(300).Print().AddToGrades_Ref(300);

	// Q: what should be printed in the following 2 statements? and why?
    // Note: we used AddToGrades_Val that returns by "value".
	// Does this make a difference in result if we uses the AddToGrades_Ref instead??
	Student s4;
	s4.AddToGrades_Val(4).AddToGrades_Val(40).Print(); // 44 is printd
	s4.Print(); // 4 is printed (NOT 44. why??)

	Student s5;
	s5.ReturnLocal_By_Ref().Print(); // the behavior is undefined and you maybe a garbage is printed. Why??
}