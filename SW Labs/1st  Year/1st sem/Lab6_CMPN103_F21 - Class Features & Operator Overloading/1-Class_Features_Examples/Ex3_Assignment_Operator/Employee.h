#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee 
{
private:
    int id;
    char * name;

public:
    Employee(char *name="", int id=0);
    ~Employee();
    char *getName();
	void setName(char *);
	int getId();
	void setId(int);

	// The Copy Constructor	
	Employee(const Employee &rhs);

	// The Overloaded Assignment Operator
	// [Step2]: uncomment this
	//void operator = (const Employee & rhs);

};

#endif