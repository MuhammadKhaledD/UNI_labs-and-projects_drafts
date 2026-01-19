#include "Library.h"
#include <iostream>
using namespace std;

int main()
{
	Library Lib;

	int nChoice = 0;
	int ID, ISBN;

	do
	{
		cout << endl;
		cout << "\t\t**********      Main Menu   ***************" << endl << endl;
		cout << "\t\t[1] Add new book" << endl;
		cout << "\t\t[2] Add new member" << endl;
		cout << "\t\t[3] Borrow a book" << endl;
		cout << "\t\t[4] Exit" << endl << endl;
		cout << "\t\t********************************************" << endl;
		cout << "Select an operation <1-4> :";
		cin >> nChoice;

		switch (nChoice)
		{
		case 1:
			Lib.AddBook();
			break;
		case 2:
			Lib.AddMember();
			break;
		case 3:
			cout << "\nEnter Member ID:";
			cin >> ID;
			cout << "\nEnter Book ISBN:";
			cin >> ISBN;
			int ret = Lib.Borrow(ID, ISBN);
			//Print a suitable message according to the value of variable "ret"
			break;
		default:
			return;
		}
	} while (1);
	return 0;
}

