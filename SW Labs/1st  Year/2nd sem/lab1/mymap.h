#pragma once
#include "mypair.h"

template<class K, class V>
class MyMap
{
private:
	MyPair<K, V> ls[100];
	int pos;

public:
	MyMap(): pos(0) {}

	void addPair(MyPair<K, V> pair)
	{
		ls[pos] = pair;
		++pos;
	}

	bool getValue(K k,V v)
	{
		for (int i = 0; i < pos; ++i) {
			if (k == ls[i].getKey())
			{
				v = ls[i].getValue();
				return true;
			}
		}

		return false;
	}

	int count() { return pos; }

	bool updateValue(K k, V v)
	{
		for (int i = 0; i < pos; ++i) {
			if (k == ls[i].getKey())
			{
				ls[i].setValue(v);
				return true;
			}
		}

		return false;
	}

	void print()
	{
		for (int i = 0; i < pos; ++i)
			cout << "(" << ls[i].getKey() << " ," << ls[i].getValue() << ")\n";
	}

	void deletePair(const MyPair<K, V>& pair)
	{
		for (int i = 0; i < pos; ++i)
		{
			if (pair.getKey() == ls[i].getKey() && pair.getValue() == ls[i].getValue())
			{
				ls[i] = ls[pos-1];
				--pos;
			}
		}
	}
};