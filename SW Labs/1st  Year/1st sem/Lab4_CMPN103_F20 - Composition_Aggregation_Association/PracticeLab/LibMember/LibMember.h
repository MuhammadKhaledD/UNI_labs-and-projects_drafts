#ifndef LIB_MEMBER_H
#define LIB_MEMBER_H

#include "Book.h"

class LibMember
{
private:
	const int ID;
	char* Name;

	//Array of books borrowed by this member (Max 5 books for simplicity)
	Book* BookList[5];
	//What if we want to make a different max no. of borrowed books for each member??


	//Number of actually borrowed books
	int BookCount;

public:
	LibMember(const char* rName, int rID);

	int getID() const;

	void setName(const char* rName);
	const char* getName() const;

	//Adds a book to the list of borrowed books
	void BorrowBook(Book*);

	//Returns a book to the library
	//i.e: Removes the book from the BookList and adjusts the list.
	//Returns false if book not found
	bool ReleaseBook(int BookISBN);

	//Prints Name, ID of the member, then
	//Prints the information about the borrowed books
	void PrintInfo() const;

	~LibMember(); //Deallocated any memory allocated by the constrcutor

};

#endif