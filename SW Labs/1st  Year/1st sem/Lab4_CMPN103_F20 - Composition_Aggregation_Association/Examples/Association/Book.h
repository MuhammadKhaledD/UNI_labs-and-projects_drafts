#ifndef BOOK_H
#define BOOK_H

#include "Author.h"

class Book
{

private:	
	char*	Title;	//Book Title
	int		ISBN;	//International Standard Book Number
	Author* BookAuthor; //Pointer data member (association), 
						//Book is not responsible for constructing and destructing the Author's object

public:
	//Book Constructor
	Book(const char* rTitle,int rISBN);
	//Data Members setter and getters
	void setTitle(const char* );
	const char* getTitle() const;

	void setISBN(int );
	int getISBN() const;

	void setBookAuthor(Author*);
	Author* getBookAuthor() const;
	
	//Prints book info
	void PrintInfo() const;

	//Book Destructor
	~Book();
};

#endif