#include<iostream>
using namespace std;

class College
{
private:
	char name[20];
	int students;

public:
	College(char arr[], int num)
	{
		if (strlen(arr) <= 20)
			strcpy_s(name, arr);

		students = num;
		cout << "collage constructor is called with " << name  << " " << students << endl;
	}

	char* get_name() { return name; }
	int get_students() const { return students; }
	void PrintInfo() const { cout << name << " " << students << endl; }

	void ReadData()
	{
		char arr[20];
		cin >> arr;
		if (strlen(arr) <= 20)
			strcpy_s(name, arr);
		int n;
		cin >> n;
		students = n;
	}

	~College() { cout << "collage destructor is called with name = " << name << endl; }
};

class Universty {
private:
	College* Clgs[20];
	int num;

public:
	Universty() 
	{
		num = 0;
		cout << "uni constructor is called\n";
	}

	void AddOneCollege()
	{
		if (num < 20)
		{
			char arr[20];
			cin >> arr;
			int n;
			cin >> n;

			bool exist = false;
			for (int i = 0; i < num; ++i)
			{
				if (!strcmp(arr,Clgs[i]->get_name()))
					exist = true;
			}

			if (!exist)
			{
				Clgs[num] = new College(arr, n);
				num++;
			}
		}
	}

	void RemoveCollage(char arr[])
	{
		bool exist = false;
		int j;
		for (int i = 0; i < num; ++i)
		{
			if (!strcmp(arr, Clgs[i]->get_name()))
			{
				exist = true;
				j = i;
			}
		}

		if (exist)
		{
			for (int i = j; i < num - 1; ++i)
				Clgs[i] = Clgs[i + 1];
				delete Clgs[num-1];
		     num--;
		}
	}

	void PrintInfo() 
	{
		cout << "number of collage = " << num << endl;
		for (int i = 0; i < num; ++i)
		{
			Clgs[i]->PrintInfo();
		}
	}

	void PrintMostDenseCollage()
	{
		if (num > 0)
		{
			int m = 0;
			for (int i = 0; i < num; ++i)
				if (Clgs[i]->get_students() > Clgs[m]->get_students())
					m = i;
			Clgs[m]->PrintInfo();
		}
	}

	void operator++(int d) 
	{
		AddOneCollege();
	}

	~Universty()
	{
		cout << "uni constructor is called\n";

		for (int i = 0; i < num; ++i)
		{
			delete Clgs[i];
		}
	}
};

int main()
{
	Universty u;

	u.AddOneCollege();
	u.AddOneCollege();
	u.AddOneCollege();

	u.PrintMostDenseCollage();

	cout << "Enter name to remove\n";
	char arr[20];
	cin >> arr;
	u.RemoveCollage(arr);

	cout << "Enter name to remove\n";
	cin >> arr;
	u.RemoveCollage(arr);

	u.PrintInfo();
	u++;

	return 0;
}