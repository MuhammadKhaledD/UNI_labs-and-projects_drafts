#ifndef BOOK_H
#define BOOK_H

#include "Author.h"

class Book
{

private:
	char*	Title;	//Pointer data member
	int		ISBN;	//International Standard Book Number
	Author* BookAuthor;
	bool Borrowed;	//Shows if a book is borrowed or not.

public:
	Book(const char* rtitle, int risbn);

	void setTitle(const char* rtitle);
	const char* getTitle() const;

	void setISBN(int risbn);
	int getISBN() const;

	void setBookAuthor(Author* A);
	Author* getBookAuthor() const;

	void PrintInfo() const;

	void setBorrowed(bool);
	bool IsBorrowed() const;

	~Book();
};

#endif