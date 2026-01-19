#include <iostream>
using namespace std;

// ============================ THE NODE CLASS ============================

//First let's declare a single node in the list
template<typename T>
class Node
{
private:
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
public:

	Node() //default constructor
	{
		next = nullptr;
	}

	Node(T newItem) //non-default constructor
	{
		item = newItem;
		next = nullptr;

	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext

	T getItem() const
	{
		return item;
	} // end getItem

	Node<T>* getNext() const
	{
		return next;
	}
}; // end Node

// ============================ THE LINKED LIST CLASS ============================

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
public:
	LinkedList()
	{
		Head = nullptr;
	}
	////////////////////////////////////////////////////////////////////////
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	// NOTE: DON'T CHANGE THIS FUNCTION
	void PrintList() const
	{
		Node<T>* p = Head;
		while (p)
		{
			cout << p->getItem();
			p = p->getNext();
			if (p)
				cout << " ";

		}
		cout << " NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	////////////////     Requirements   ///////////////////
	//
	void InsertEnd(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (Head == nullptr)
		{
			Head = newNode;
			return;
		}

		Node<T>* temp = Head;
		while (temp->getNext())
			temp = temp->getNext();

		temp->setNext(newNode);
	}

	LinkedList(const LinkedList<T>& other)
	{
		Head = nullptr;

		Node<T>* current = other.Head;
		while (current)
		{
			InsertEnd(current->getItem());
			current = current->getNext();
		}
	}


	bool ApplyRepeatedOperation(const LinkedList<char>& opp, const LinkedList<int>& rep, LinkedList<int>& res)
	{
		Node<int>* r = rep.Head;
		Node<char>* o = opp.Head;
		Node<int>* l = Head;

		while (l)
		{
			if (r && o)
			{
				if (r->getItem() < 1)
					r = r->getNext();

				else if (r->getItem() < 2 && (o->getItem() == '+' || o->getItem() == 'X'))
					r = r->getNext();

				else if (o->getItem() == 'S')
				{
					o = o->getNext();

					for (int i = 0; i < r->getItem(); ++i)
					{
						if (!l)
							return false;

						l = l->getNext();
					}

					r = r->getNext();
				}
				else if (o->getItem() == '+')
				{
					o = o->getNext();
					int sum = 0;

					for (int i = 0; i < r->getItem(); ++i)
					{
						if (!l)
							return false;

						sum += l->getItem();
						l = l->getNext();
					}

					res.InsertEnd(sum);
					r = r->getNext();
				}
				else if (o->getItem() == 'X')
				{
					o = o->getNext();
					int mul = 1;

					for (int i = 0; i < r->getItem(); ++i)
					{
						if (!l)
							return false;

						mul *= l->getItem();
						l = l->getNext();
					}

					res.InsertEnd(mul);
					r = r->getNext();
				}
			}
			else if (r)
			{
				if (r->getItem() < 2)
				{
					r = r->getNext();
					continue;
				}
				int sum = 0;

				for (int i = 0; i < r->getItem(); ++i)
				{
					if (!l)
						return false;

					sum += l->getItem();
					l = l->getNext();
				}

				res.InsertEnd(sum);
				r = r->getNext();
				continue;
			}
			else if (o)
			{
				if (o->getItem() == '+')
				{
					o = o->getNext();
					int sum = 0;

					for (int i = 0; i < 2; ++i)
					{
						if (!l)
							return false;

						sum += l->getItem();
						l = l->getNext();
					}

					res.InsertEnd(sum);
					continue;
				}
				else if (o->getItem() == 'X')
				{
					o = o->getNext();
					int mul = 1;

					for (int i = 0; i < 2; ++i)
					{
						if (!l)
							return false;

						mul *= l->getItem();
						l = l->getNext();
					}

					res.InsertEnd(mul);
					continue;
				}
				else
				{
					o = o->getNext();

					for (int i = 0; i < 2; ++i)
					{
						if (!l)
							return false;

						l = l->getNext();
					}
				}
			}
			else
			{
				int sum = 0;

				for (int i = 0; i < 2; ++i)
				{
					if (!l)
						return false;

					sum += l->getItem();
					l = l->getNext();
				}

				res.InsertEnd(sum);
				continue;
			}

		}
		return true;
	}

	template<class U>
	friend class LinkedList;
};

int main()
{
	int val;
	char c_val;
	LinkedList<int> L;
	LinkedList<char> Opp;
	LinkedList<int> Repeat;
	LinkedList<int> Res;
	cin >> val;
	while (val != -1)
	{
		L.InsertEnd(val);
		cin >> val;
	}
	cin >> c_val;
	while (c_val != '$')
	{
		Opp.InsertEnd(c_val);
			cin >> c_val;
	}
	cin >> val;
	while (val != -1)
	{
		Repeat.InsertEnd(val);

		cin >> val;
	}

	bool b = L.ApplyRepeatedOperation(Opp,Repeat, Res);
	if (b)
	{
		Res.PrintList();
	}
	else
	{
		cout << "Error" << endl;
		Res.PrintList();
	}
	return 0;
}