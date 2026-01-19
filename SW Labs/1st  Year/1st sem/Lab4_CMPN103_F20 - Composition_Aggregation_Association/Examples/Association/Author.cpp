#include "Author.h"
#include <string.h>
#include <iostream>
using namespace std;

/*
 The naming of class methods parmeters in this code follows one of the naming conventions
 which precedes the parameter name by the letter "r".
*/
//Author's Constructor
Author::Author(const char* rName, int rID)
{
	cout<<"\nAuthor ["<<rName<<"]: Constructor is called\n\n";
	Name = NULL;
	setName(rName);
	setID(rID);
}

////////////////////////////////////////////////////////////////////////
//Data members setters and getters
////////////////////////////////////////////////////////////////////////
void Author::setID(int rID)
{
	ID = rID;
}

int Author::getID() const
{
	return ID;
}
////////////////////////////////////////////////////////////////////////
void Author::setName(const char* rName)
{
	if (Name != NULL)
		delete[] Name;
	int len = strlen(rName) + 1;
	Name = new char[len];
	strcpy_s(Name, len, rName);
}

const char* Author::getName() const
{
	return Name;
}
////////////////////////////////////////////////////////////////////////
void Author::PrintInfo() const
{
	cout<<"\nAuthor ID:"<<ID<<"\tAuthor Name:"<<Name;
}
////////////////////////////////////////////////////////////////////////
//Author's Destructor
Author::~Author()
{
	cout<<"\nAuthor ["<<Name<<"]: Destructor is called\n\n";
	if (Name != NULL)
		delete[] Name;
}

