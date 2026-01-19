
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
	void PrintList()	const
	{
		//cout << endl;
		Node<T>* p = Head;

		while (p)
		{
			cout << p->getItem() << " ";
			p = p->getNext();
		}
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
	// TODO: Implement the following member function

	void InsertEnd(Node<T>* e)
	{
		Node<T>* E = new Node<int>();
		E->setItem(e->getItem());

		if (!Head)
		{
			Head = E;
			return;
		}

		Node<T>* ptr = Head;

		while (ptr->getNext())
			ptr = ptr->getNext();

		ptr->setNext(E);
	}

	void DeleteLast()
	{
		if (!Head)
			return;
		
		if (!Head->getNext())
		{
			delete Head;
			Head = nullptr;
			return;
		}

		Node<T>* l = Head;

		while (l->getNext()->getNext())
			l = l->getNext();

		delete l->getNext();
		l->setNext(nullptr);
	}

	Node<T>* RemoveMin()
	{
		if (!Head)
			return nullptr;

		if (!Head->getNext())
		{
			Node<T>* r = Head;
			Head = nullptr;
			return r;
		}

		T minValue = Head->getItem();

		Node<T>* ptr = Head;
		Node<T>* MIN = Head;
		Node <T>* per = nullptr;
		Node <T>* perit = nullptr;
		int index = 0;

		while (ptr)
		{
			if (ptr->getItem() < minValue)
			{
				MIN = ptr;
				per = perit;
			}

			ptr = ptr->getNext();

			if (index == 0)
				perit = Head;
			else
				perit = perit->getNext();

			++index;

		}

		if (per == nullptr)
		{
			MIN = Head;
			Head = Head->getNext();
			return MIN;
		}
		

		per->setNext(MIN->getNext());

		return MIN;
	}

	//LinkedList<T>* sum(Node<T>* Head2)
	//{
	//	int l1 = 0;
	//	int l2 = 0;
	//	Node<T>* h1 = Head;
	//	Node<T>* h2 = Head2;

	//	while (h1)
	//	{
	//		h1 = h1->getNext();
	//		++l1;
	//	}
	//	while (h2)
	//	{
	//		h2 = h2->getNext();
	//		l2++;
	//	}
	//	

	//	if (l1 != l2)
	//		returm nullptr;

	//	LinkedList<T>* L;
	//	Node<T>* node = new Node<T>();

	//	h1 = Head;
	//	h2 = Head2;

	//	while (h2 && h1)
	//	{
	//		node->setItem(h1->getItem() + h2->getItem());
	//		L->InsertEnd(node);
	//		h2 = h2->getNext();
	//		h1 = h1->getNext();
	//	}

	//	return L;
	//}

	LinkedList<T>* sum(LinkedList<T>& list2)
	{
		int l1 = 0, l2 = 0;
		Node<T>* h1 = Head;
		Node<T>* h2 = list2.Head;

		while (h1)
		{
			h1 = h1->getNext();
			++l1;
		}
		while (h2)
		{
			h2 = h2->getNext();
			++l2;
		}

		if (l1 != l2)
			return nullptr;

		LinkedList<T>* L = new LinkedList<T>();

		h1 = Head;
		h2 = list2.Head;

		while (h1 && h2)
		{
			Node<T>* node = new Node<T>(h1->getItem() + h2->getItem());
			L->InsertEnd(node);
			h1 = h1->getNext();
			h2 = h2->getNext();
		}

		return L;
	}

	LinkedList<T>* MergeSorted(LinkedList<T>& list2)
	{
		LinkedList<T>* mergedList = new LinkedList<T>();
		Node<T>* ptr1 = Head;
		Node<T>* ptr2 = list2.Head;

		while (ptr1 && ptr2)
		{
			if (ptr1->getItem() < ptr2->getItem())
			{
				mergedList->InsertEnd(ptr1);
				ptr1 = ptr1->getNext();
			}
			else
			{
				mergedList->InsertEnd(ptr2);
				ptr2 = ptr2->getNext();
			}
		}

		while (ptr1)
		{
			mergedList->InsertEnd(ptr1);
			ptr1 = ptr1->getNext();
		}

		while (ptr2)
		{
			mergedList->InsertEnd(ptr2);
			ptr2 = ptr2->getNext();
		}

		list2.Head = nullptr;

		return mergedList;
	}



};

// TODO: MODIFY THE MAIN FOR EACH PROBLEM
	int main()
	{
		LinkedList<int> L;	//create an object of class LinkedList
		int val;

		cin >> val;
		Node<int>* e = new Node<int>();

		while (val != -1)
		{
			e->setItem(val);
			L.InsertEnd(e); // TODO: REPLACE THIS
			cin >> val;
		}

		//cin >> val;
		//e->setItem(val);
		//L.InsertEnd(e);
		//L.PrintList();
		//L.DeleteLast();
		//L.PrintList();
		//Node<int>*  i = L.RemoveMin();
		//L.PrintList();
		//cout << endl;
		//if(i)
		//{
		//	cout << i->getItem();
		//}
		

		LinkedList<int> L1;	

		cin >> val;
		while (val != -1)
		{
			e->setItem(val);
			L1.InsertEnd(e); 
			cin >> val;
		}

		LinkedList<int>* s = L.MergeSorted(L1);
		if(s)
		s->PrintList();

		return 0;
	}