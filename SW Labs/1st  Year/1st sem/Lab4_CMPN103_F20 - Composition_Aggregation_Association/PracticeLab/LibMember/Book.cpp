#include "Book.h"
#include <string.h>
#include <iostream>
using namespace std;


//Constructor should allocate memory for pointer data members
Book::Book(const char* rtitle, int risbn)
{
	cout << "\nBook " << rtitle << " :Constructor is called ==> Allocating memory\n\n";

	//Allocate storage for book Title
	Title = new char[strlen(rtitle) + 1];
	strcpy(Title, rtitle);

	setISBN(risbn);

	BookAuthor = NULL;

	Borrowed = false;
}

void Book::setTitle(const char* rtitle)
{
	delete[] Title;
	Title = new char[strlen(rtitle) + 1];
	strcpy(Title, rtitle);
}

const char* Book::getTitle() const
{
	return Title;
}


void Book::setISBN(int risbn)
{
	ISBN = risbn;
}

int Book::getISBN() const
{
	return ISBN;
}


void Book::setBookAuthor(Author *A)
{
	BookAuthor = A;
}

Author* Book::getBookAuthor() const
{
	return BookAuthor;
}

void Book::PrintInfo() const
{
	cout << "\nBook info:";
	cout << "\nTitle:" << Title << "\tISBN:" << ISBN;

	if (Borrowed)
		cout << "\nBook is borrowed";
	else
		cout << "\nBook is availabe:";

	if (BookAuthor == NULL)
		cout << "\nNo Author information";
	else
		BookAuthor->PrintInfo();
}

void Book::setBorrowed(bool status)
{
	Borrowed = status;
}

bool Book::IsBorrowed() const
{
	return Borrowed;
}

Book::~Book()
{
	cout << "\nBook " << Title << " :Destructor is called ==> free reserved memory\n\n";

	//Free the allocated storage to avoid memory leak.
	delete[]Title;
}
