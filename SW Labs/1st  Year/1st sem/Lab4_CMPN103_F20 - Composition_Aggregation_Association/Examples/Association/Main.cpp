#include "Author.h"
#include "Book.h"
#include <iostream>
using namespace std;

int main()
{

	Author* pA = new Author("Mohamed Ali", 500);
	Author A2("Ahmed Hassan", 600);
	
	Book B1("Intorduction to C++",1001);

	//Let B1 points to pA
	B1.setBookAuthor(pA);
	B1.PrintInfo();
	
	{//Scope of B2
		Book B2("Programming Techniques",1002);
		B2.setBookAuthor(pA);
		B2.PrintInfo();
	}//B2 is destructed. pA is still alive. 
	//( Q1:What if Book destructor destructs the Author object too?!! )


	//Let B1 points to another Author. pA is still alive.
	cout<<"\n\nChanging Book author...\n";
	
	B1.setBookAuthor(&A2);
	B1.PrintInfo();
	
	cout<<endl;
	
	//pA is no longer needed
	delete pA;
	
	return 0;
}
