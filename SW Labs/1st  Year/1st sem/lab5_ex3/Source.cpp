#include <iostream>

using namespace std;

class Employee
{
private:
    string name;
    int rank;
    int tasks;
public:
    Employee(string n, int r, int t)
    {
        rank = r;
        tasks = t;
        name = n;
    }

    virtual void inc_rank() = 0;
    virtual void inc_tasks() = 0;
    virtual bool assign_task(Employee* e) = 0;
    virtual int comp(Employee* e) = 0;
    virtual int get_rank() = 0;
    virtual void print() = 0;

};

class Manager : public Employee
{
private:
    string name;
    int rank;
    int tasks;
public:
    Manager(string n = 0, int r = 0, int t = 0) :Employee(n, r, t)
    {
        this->rank = r;
        this->tasks = t;
        this->name = n;
    }

    virtual void inc_rank() { this->rank++; }
    virtual void inc_tasks() { this->tasks++; }
    virtual int get_rank() { return rank; }

    virtual int comp(Employee* e)
    {
        Manager* casted = dynamic_cast<Manager*> (e);
        if (!casted)
        {
            return 1;
        }
        if (e->get_rank() > rank)
            return -1;
        else if (e->get_rank() < rank)
            return 1;
        else
            return 0;
    }

    virtual bool assign_task(Employee* e)
    {
        if (comp(e) == 1)
        {
            e->inc_tasks();
            return true;
        }
        return false;
    }

    virtual void print()
    {
        cout << "Type is Manager\nName is " << name << "\nRank is " << rank << "\nNo. of Tasks assigned is " << tasks << endl;
    }

};

class DepEmp : public Employee
{
private:
    string name;
    int rank;
    int tasks;
public:
    DepEmp(string n = 0, int r = 0, int t = 0) :Employee(n, r, t)
    {
        this->rank = r;
        this->tasks = t;
        this->name = n;
    }

    virtual void inc_rank() { this->rank++; }
    virtual void inc_tasks() { this->tasks++; }
    virtual int get_rank() { return rank; }

    virtual bool assign_task(Employee* e)
    {
        if (comp(e) == 1)
        {
            e->inc_tasks();
            return true;
        }
        return false;
    }

    virtual int comp(Employee* e)
    {
        DepEmp* casted = dynamic_cast<DepEmp*> (e);
        if (!casted)
        {
            return -1;
        }
        if (e->get_rank() > rank)
            return -1;
        else if (e->get_rank() < rank)
            return 1;
        else
            return 0;
    }

    virtual void print()
    {
        cout << "Type is Department Employee\nName is " << name << "\nRank is " << rank << "\nNo. of Tasks assigned is " << tasks << endl;
    }

};



int main()
{
    Employee* EmployeesList[5];
    EmployeesList[0] = new DepEmp("DepEmp1", 4, 7);
    EmployeesList[1] = new DepEmp("DepEmp2", 3, 5);
    EmployeesList[2] = new Manager("Manager1", 2, 2);
    EmployeesList[3] = new Manager("Manager2", 1, 3);
    EmployeesList[4] = new DepEmp("DepEmp3", 3, 2);
    int c = 50;
    int e1 = 50, e2 = 50; //e1 and e2 are the indices that will be used to access the array
    while (c != 0)
    {
        cin >> c;
        if (c == 1) // printing
        {
            cin >> e1;
            //print info of e1
            EmployeesList[e1]->print();
        }
        else if (c == 2) //assign
        {
            cin >> e1 >> e2;
            //let e1 assign a task to e2 and the output of assigning is the following bool variable "isValid"
            bool isValid = EmployeesList[e1]->assign_task(EmployeesList[e2]);
            if (isValid)
                cout << "valid" << endl;
            else
                cout << "invalid" << endl;
        }
        else if (c == 3) //compare the rank levels of two employees
        {
            cin >> e1 >> e2;
            //compare the rank of first Employee e1 to the rank of Employee e2, the result is the following int variable"comRes"
            int comRes = EmployeesList[e1]->comp(EmployeesList[e2]);
            if (comRes == 1)
                cout << "e1 is higher" << endl;
            else if (comRes == 0)
                cout << "the same rank" << endl;
            else
                cout << "e2 is higher" << endl;
        }
    }
}

