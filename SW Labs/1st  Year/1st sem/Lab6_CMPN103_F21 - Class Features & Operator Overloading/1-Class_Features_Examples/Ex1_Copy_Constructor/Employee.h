#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee 
{
private:
    int id;
    char * name;

public:
    Employee(char *name = "", int id = 0);
    ~Employee();
    char *getName() const;
	void setName(char *);
	int getId() const;
	void setId(int);

	// After the first run and seeing the error (read the main): 
	// uncomment the following "Copy Constructor"

	/*
	Employee(const Employee &rhs); // Note that the copy constructor must be passed by reference
	                                 // because if passed by value, that will call itself the copy constructor again
	                                 // and an infinite loop will happen
	*/
};

#endif