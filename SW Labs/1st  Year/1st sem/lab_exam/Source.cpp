//#include <iostream>
//#include <string>
//using namespace std;
//
//class FootBallPlayer {
//private:
//	string name;
//	bool inj;
//	bool playing;
//
//public:
//	FootBallPlayer(string n, bool i = 0, bool p = 1)
//	{
//		setName(n);
//		setInj(i);
//		setPlaying(p);
//	}
//
//	void setName(string n)
//	{
//		int l = n.length();
//		bool valid = false;
//
//		for (int i = 0; i < l; ++i)
//		{
//			if ((n[i] >= 65 && n[i] <= 90) || (n[i] >= 97 && n[i] <= 122))
//			{
//				valid = true;
//				break;
//			}
//		}
//
//		if (valid)
//		{
//			name = n;
//		}
//		else
//		{
//			name = "invalid";
//		}
//	}
//
//	void prints() const
//	{
//		cout << name << " " << (int)inj << " " << (int)playing  << " ";
//	}
//
//	void setInj(bool i)
//	{
//		if (/*!inj*/ true)
//		{
//			inj = i;
//		}
//	}
//	void setPlaying(bool p)
//	{
//		if (!inj)
//		{
//			playing = p; 
//		}
//		/*else 
//		{
//			playing = false;
//		}*/
//
//	}
//};
//
//
//void GetDRD(int* A, int M, int num)
//{
//	int N = 0;
//	int L = 0;
//
//	for (int i = 0; i < M; ++i)
//	{
//		if (A[i] % num == 0 && A[i] > 0)
//		{
//			++N;
//		}
//		if (i == M - 1)
//			continue;
//		if (A[i] != A[i+1] && A[i] > 0)
//		{
//			if (i == M - 2)
//			{
//				L++;
//			}
//			++L;
//		}
//	}
//
//	int* B = new int[N];
//	int* C = new int[L];
//
//	int n = 0;
//	int l = 0;
//
//	for (int i = 0; i < M; ++i)
//	{
//		if (A[i] % num == 0 && A[i] > 0)
//		{
//			B[n] = A[i];
//			++n;
//		}
//		if (i == M - 1)
//			continue;
//		if (A[i] != A[i + 1] && A[i] > 0)
//		{
//			C[l] = A[i];
//			++l;
//
//			if (i == M - 2)
//			{
//				C[l] = A[i + 1];
//				++l;
//			}
//		}
//	}
//
//	if (n == N && L == l)
//	{
//		cout << "2B ";
//		for (int i = 0; i < N; ++i)
//		{
//			cout << B[i] << " ";
//
//		}
//
//		cout << "C ";
//
//		for (int i = 0; i < L; ++i)
//		{
//			cout << C[i] << " ";
//		}
//	}
//	else
//	{
//		cout << "Unexpected Error\n";
//	}
//}
//
//
//int main()
//{
//
//	while (true)
//	{
//		int choice;
//		cin >> choice;
//
//		if (choice == 1)
//		{ 
//			string name;
//			cin >> name;
//			FootBallPlayer FP1(name);
//			cout << "1 ";
//			FP1.prints();
//			int n;
//			cin >> n;
//			bool inj, playing;
//			for (int i = 0; i < n; ++i)
//			{
//				cin >> inj >> playing;
//				FP1.setInj(inj);
//				FP1.setPlaying(playing);
//
//				FP1.prints();
//				cout << endl;
//			}
//
//		}
//		else if (choice == 2)
//		{
//			int num;
//			cin >> num;
//			int size;
//			cin >> size;
//
//			int* A = new int[size];
//
//			for (int i = 0; i < size; ++i)
//			{
//				cin >> A[i];
//			}
//
//			GetDRD(A, size, num);
//		}
//	}
//
//	return 0;
//
//}


#include <iostream>
#include <string>
using namespace std;

class FootBallPlayer {
private:
	string name;
	bool inj;
	bool playing;

public:
	FootBallPlayer(string n, bool i = 0, bool p = 1)
	{
		setName(n);
		inj = i;
		playing = p;
	}

	void setName(string n)
	{
		int l = n.length();
		bool valid = false;

		for (int i = 0; i < l; ++i)
		{
			if ((n[i] >= 65 && n[i] <= 90) || (n[i] >= 97 && n[i] <= 122))
			{
				valid = true;
				break;
			}
		}

		if (valid)
		{
			name = n;
		}
		else
		{
			name = "invalid";
		}
	}

	void prints() const
	{
		cout << name << " " << (int)inj << " " << (int)playing << " ";
	}

	void setInj(bool i)
	{
		if (!playing /*true*/)
		{
			inj = i;
		}
	}
	void setPlaying(bool p)
	{
		if (!inj)
		{
			playing = p;
		}
		/*else
		{
			playing = false;
		}*/

	}
};


void GetDRD(int* A, int M, int num, int* &B, int* &C, int& N, int& L)
{
	 N = 0;
	 L = 0;

	for (int i = 0; i < M; ++i)
	{
		if (A[i] % num == 0 && A[i] > 0)
		{
			++N;
		}
		if (i == M - 1)
			continue;
		if (A[i] != A[i + 1] && A[i] > 0)
		{
			if (i == M - 2)
			{
				L++;
			}
			++L;
		}
	}

	B = new int[N];
	C = new int[L];

	int n = 0;
	int l = 0;

	for (int i = 0; i < M; ++i)
	{
		if (A[i] % num == 0 && A[i] > 0)
		{
			B[n] = A[i];
			++n;
		}
		if (i == M - 1)
			continue;
		if (A[i] != A[i + 1] && A[i] > 0)
		{
			C[l] = A[i];
			++l;

			if (i == M - 2)
			{
				C[l] = A[i + 1];
				++l;
			}
		}
	}

	if (n == N && L == l)
	{
		return;
	}
	else
	{
		cout << "Unexpected Error\n";
	}
}


int main() 	// ???? ???? ???? 91240653 
{
	while (true)
	{
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			string name;
			cin >> name;
			FootBallPlayer FP1(name);
			cout << "1 ";
			FP1.prints();
			int n;
			cin >> n;
			bool inj, playing;
			for (int i = 0; i < n; ++i)
			{
				cin >> inj >> playing;
				FP1.setInj(inj);
				FP1.setPlaying(playing);

				FP1.prints();
			}
			cout << endl;

		}
		else if (choice == 2)
		{
			int num;
			cin >> num;
			int size;
			cin >> size;

			int* A = new int[size];

			for (int i = 0; i < size; ++i)
			{
				cin >> A[i];
			}
			int* B = nullptr;
			int* C = nullptr;
			int N;
			int L;
			 GetDRD(A, size, num, B, C, N, L);

			 cout << "2 B ";
			 for (int i = 0; i < N; ++i)
			 {
				 cout << B[i] << " ";

			 }

			 cout << "C ";

			 for (int i = 0; i < L; ++i)
			 {
				 cout << C[i] << " ";
			 }
		}
	}

	return 0;

}