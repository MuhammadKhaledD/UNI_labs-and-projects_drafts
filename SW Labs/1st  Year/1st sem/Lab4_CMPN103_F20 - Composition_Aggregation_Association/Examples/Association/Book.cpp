#include "Book.h"
#include <iostream>
using namespace std;

/*
 The naming of class methods parmeters in this code follows one of the naming conventions
 which precedes the parameter name by the letter "r".
*/
// Book Constructor
Book::Book(const char* rTitle,int rISBN)
{
	cout<<"\nBook ["<<rTitle<<"]: Constructor is called\n\n";
	
	Title = NULL;
	setTitle(rTitle);
	setISBN(rISBN);

	//Book is NOT responsible for allocating or deallocating Author object
	BookAuthor = NULL;	
}
////////////////////////////////////////////////////////////////////////
//Data members setters and getters
////////////////////////////////////////////////////////////////////////
void Book::setTitle(const char* rTitle)
{
	if (Title != NULL)
		delete[] Title;
	int len = strlen(rTitle) + 1;
	Title = new char[len];
	strcpy_s(Title, len, rTitle);
}

const char* Book::getTitle() const
{
	return Title;	
}
////////////////////////////////////////////////////////////////////////	
void Book::setISBN(int rISBN)
{
	ISBN = rISBN;
}
	
int Book::getISBN() const
{
	return ISBN;
}
////////////////////////////////////////////////////////////////////////
void Book::setBookAuthor(Author *A)
{
	BookAuthor = A;
}

Author* Book::getBookAuthor() const
{
	return BookAuthor;
}
////////////////////////////////////////////////////////////////////////
//Prints Book info
void Book::PrintInfo() const
{
	cout<<"\nBook info:";
	cout<<"\nTitle:"<<Title<<"\tISBN:"<<ISBN;	
	if(BookAuthor == NULL)
		cout<<"\nNo Author information";
	else
		BookAuthor->PrintInfo();
}
////////////////////////////////////////////////////////////////////////
//Book Destructor
Book::~Book()
{	
	cout<<"\nBook ["<<Title<<"]: Destructor is called\n\n";
	if (Title != NULL)
		delete[] Title;
	//Book is not responsible for destructing Author's object
	//The author existence is not correlated with the book existence
}
