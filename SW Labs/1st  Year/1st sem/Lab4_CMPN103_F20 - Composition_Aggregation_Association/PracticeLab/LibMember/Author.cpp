#include "Author.h"
#include <string.h>
#include <iostream>
using namespace std;


Author::Author(const char *rName, int rID)
{
	cout << "\nAuthor " << rName << " :Constructor is called ==> Allocating memory\n\n";

	//Allocate storage for author Name
	Name = new char[strlen(rName) + 1];
	strcpy(Name, rName);

	setID(rID);

}

void Author::setID(int rID)
{
	ID = rID;
}

int Author::getID() const
{
	return ID;
}

void Author::setName(const char *rName)
{
	delete[]Name;
	Name = new char[strlen(rName) + 1];
	strcpy(Name, rName);
}

const char* Author::getName() const
{
	return Name;
}

void Author::PrintInfo() const
{
	cout << "\nAuthor ID:" << ID << "\tAuthor Name:" << Name;
}

Author::~Author()
{
	cout << "\nAuthor " << Name << " :Destructor is called ==> free reserved memory\n\n";
	delete[]Name;
}

