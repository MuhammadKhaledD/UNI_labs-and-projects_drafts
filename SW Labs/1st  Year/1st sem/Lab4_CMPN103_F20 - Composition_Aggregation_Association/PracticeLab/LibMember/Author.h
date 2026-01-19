#ifndef AUTHOR_H
#define AUTHOR_H

class Author
{

private:
	int ID;
	char* Name;

public:
	Author(const char* rName, int rID);

	void setID(int rID);
	int getID() const;

	void setName(const char* rName);
	const char* getName() const;

	void PrintInfo() const;

	~Author();

};

#endif