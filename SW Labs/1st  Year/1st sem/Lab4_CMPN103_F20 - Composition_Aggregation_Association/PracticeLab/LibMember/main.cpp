#include "Author.h"
#include "LibMember.h"
#include <iostream>
using namespace std;

int main()
{

	Author A1("Mohamed", 500);
	Author A2("Ahmed", 600);

	Book B1("Book1", 1001);

	Book B2("Book2", 1122);
	B2.setBookAuthor(&A1);
	B2.PrintInfo();

	Book B3("Book3", 3113);
	B3.setBookAuthor(&A1);
	B3.PrintInfo();


	//Let B1 points to A1
	B1.setBookAuthor(&A1);
	B1.PrintInfo();

	//B1 points to another Author. A1 is still alive.
	B1.setBookAuthor(&A2);
	B1.PrintInfo();

	LibMember L("Yousef Ahmed", 9000);
	L.BorrowBook(&B1);
	L.PrintInfo();
	L.BorrowBook(&B2);
	L.PrintInfo();
	L.BorrowBook(&B3);
	L.PrintInfo();

	L.ReleaseBook(2222);
	L.PrintInfo();
	L.ReleaseBook(1122);
	L.PrintInfo();

	return 0;
}
