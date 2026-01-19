#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class K, class V>
class MyPair
{
private:
	K key;
	V value;

public:
	/*MyPair(K k = 0, V v = 0)
	{
		key = k;
		value = v;
	}*/

	void setPair(K k, V v)
	{
		key = k;
		value = v;
	}

	void setKey(K k)
	{
		key = k;
	}

	void setValue(V v)
	{
		value = v;
	}

	K getKey() const
	{
		return key;
	}

	V getValue() const
	{
		return value;
	}

	bool operator==(const MyPair& obj)
	{
		if (this->getKey() == obj.getKey() && this->getValue() == obj.getValue())
			return true;

		return false;
	}

};