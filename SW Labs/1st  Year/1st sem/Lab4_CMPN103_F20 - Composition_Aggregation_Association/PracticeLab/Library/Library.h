#ifndef LIBRARY_H
#define LIBRARY_H

#include "Author.h"
#include "Book.h"
#include "LibMember.h"


class Library
{
private:
	Book*		Books[50]; //List of Library books
	LibMember*	Members[20];//List of Library Mambers

							///
							///Add any data members you need here
							///

public:
	Library();	//Constructor
	~Library();	//Destructor

				//function AddBook()
				//Reads book details (ISBN, Title, Author name, ID) from the user
				//then Adds a new book to the library
	void AddBook();

	Book* getBook(int ISBN) const;//gets a book with ISBN (NULL if not found)

								  //function AddMember()
								  //Reads member's details (name, ID) from the user
								  //Then adds a new Member to the library
	void AddMember();

	LibMember* getMember(int ID) const;//gets a member with ID (NULL if not found)

									   //Makes a member with ID borrows a book with ISBN
									   //if no member with this ID, return -1 
									   //if no book with this ISBN return -2
									   //if the book is already borrowed, return -3.
									   //return 1 if everyting is OK
									   //It's better to use enum for return type
	int Borrow(int ID, int ISBN);
};

#endif
