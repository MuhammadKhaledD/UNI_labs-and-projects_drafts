#ifndef AUTHOR_H
#define AUTHOR_H

//<string> is a C++ standard library include, and <string.h> is C standard library include.
//The equivalent of <string.h> in C++ is <cstring>, although both work.

#include "string"
using namespace std;


class Author
{
	
private:
	int ID;			//Author's ID
	char* Name;	//Author's name

public:
	//Author's Constructor
	Author(const char*, int);
	
	//Data members setters and getters
	void setID(int);
	int getID() const;
	
	void setName(const char* );
	const char* getName() const;

	//Prints Author's info
	void PrintInfo() const;
	
	//Author's Destructor
	~Author();

};

#endif