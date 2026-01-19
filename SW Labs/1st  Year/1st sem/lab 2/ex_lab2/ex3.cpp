#include <iostream>

using namespace std;

void merge(int* A1, int* A2, int s1, int s2, int* &p)
{
	int j = 0;
	p = new int[s1 + s2];

	for (int i = 0; i < s1; ++i)
	{
		*(p + j) = *(A1 + i);
		++j;
	}

	for (int i = 0; i < s2; ++i)
	{
		*(p + j) = *(A2 + i);
		++j;
	}
}
int main()
{
	int s1, s2;
	cin >> s1;
	int* A1 = new int[s1];
	for (int i = 0; i < s1; ++i)
	{
		cin >> *(A1 + i);
	}

	cin >> s2;
	int* A2 = new int[s2];
	for (int i = 0; i < s2; ++i)
	{
		cin >> *(A2 + i);
	}

	if (s1 == s2 && s1 == 0)
	{
		cout << "Empty\n";
		return 0;
	}

	int* p = NULL;

	merge(A1, A2, s1, s2, p);

	cout << endl;
	for (int i = 0; i < (s1 + s2); ++i)
	{
		cout << *(p + i) << " ";
	}
	cout << endl << endl;

	for (int c = 0; c < 5; ++c)
	{
		cin >> s1;
		A1 = new int[s1];
		for (int i = 0; i < s1; ++i)
		{
			cin >> *(A1 + i);
		}

		cin >> s2;
		A2 = new int[s2];
		for (int i = 0; i < s2; ++i)
		{
			cin >> *(A2 + i);
		}

		if (s1 == s2 && s1 == 0)
		{
			cout << "Empty\n\n";
			continue;
		}

		merge(A1, A2, s1, s2, p);

		cout << endl;
		for (int i = 0; i < (s1 + s2); ++i)
		{
			cout << *(p + i) << " ";
		}
		cout << endl << endl;
	}

	delete[]A1;
	delete[]A2;
	delete[]p;
	A1 = NULL;
	A2 = NULL;
	p = NULL;

	return 0;
}

