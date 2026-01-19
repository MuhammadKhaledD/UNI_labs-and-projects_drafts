#include "Header.h"

int main()
{
	MyMap<int, string> map;
	bool loop = true;
	int k; string v;
	MyPair<int, string> pair;

	while (loop)
	{
		cout << "Enter ur choice 1~5\n";
		int order;
		cin >> order;

		switch (order)
		{
		case 1:
			cout << "Enter Key then value to add: ";
			cin >> k >> v;
			pair.setKey(k); pair.setValue(v);
			map.addPair(pair);
			break;
		case 2:
			cout << "Enter Key then value to update: ";
			cin >> k >> v;
			map.updateValue(k, v);
			break;
		case 3:
			cout << "Enter Key to search: ";
			cin >> k;
			bool found;
			found = map.getValue(k, v);
			if (found)
				cout << "found and the value is: " << v << endl;
			else
				cout << "not found\n";
			break;
		case 4:
			cout << "Enter Key then value to delete: ";
			cin >> k >> v;
			pair.setKey(k);
			pair.setValue(v);
			map.deletePair(pair);
			break;
		case 5:
			map.print();
			break;
		default:
			loop = false;
		}
	}

	//MyMap<Creature*, Position> game;
	//loop = true;
	//Creature* c;
	//Position p;

	return 0;
}