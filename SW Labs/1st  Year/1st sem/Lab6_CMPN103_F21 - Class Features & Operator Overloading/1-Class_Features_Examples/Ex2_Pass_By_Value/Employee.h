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
    char *getName() const;
	void setName(char *);
	int getId() const;
	void setId(int);

	// [Step2]
	// The copy constructor 
	//Employee(const Employee & rhs);
	
	
	// [Step3]
	// - comment step 2
	// - uncomment the following statement 
	//Employee(const Employee rhs);

};

#endif