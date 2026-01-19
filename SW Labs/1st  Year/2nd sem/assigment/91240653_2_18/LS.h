#ifndef _NODE
#define _NODE

#include <iostream>
using namespace std;

//First let's declare a single node in the list
template<typename T>
class Node
{
private:
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
	Node<T>* prev;  // Pointer to prev node
public:

	Node() //default constructor
	{
		next = nullptr;
		prev = nullptr;
	}

	Node(T newItem) //non-default constructor
	{
		item = newItem;
		next = nullptr;
		prev = nullptr;

	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext
	void setPrev(Node<T>* prevNodePtr)
	{
		prev = prevNodePtr;
	} // end setNext
	T getItem() const
	{
		return item;
	} // end getItem

	Node<T>* getNext() const
	{
		return next;
	}
	Node<T>* getPrev() const
	{
		return prev;
	}
}; // end Node

#endif	

#ifndef _DOUBLYLINKEDLIST
#define _DOUBLYLINKEDLIST

template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	DoublyLinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~DoublyLinkedList()
	{
		DeleteAll();
	}
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	///////////////////////////////////////////
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
	///////////////////////////////////////////
	/*
	* prints the values of all nodes in a doubly linked list starting from the Head.
	*/
	void DisplayForward()	const
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
	/////////////////////  Requirements  //////////////////////
	/*
	//You are supposed to implement the following member functions:
	-----------------------------------------------------------------
	InsertBeg −> Adds an element at the beginning of the DLL.*
		

		DeleteBeg −> Deletes an element at the beginning of the DLL.*

		InsertLast −> Adds an element at the end of the DLL.*

		DeleteLast −> Deletes an element from the end of the DLL.*

		InsertAfter −> Adds an element after the first occurance of an item in the DLL.

		Delete −> Deletes an element from the list using the item,if the item exists more than once, all copies should be deleted*

		DisplayBackward −> Displays the complete list in a backward manner.*
	*/
	////////////////////////////////////////////////////////////////////////
	bool IsEmpty()
	{
		return Head == nullptr;
	}
	void InsertBeg(T n)
	{
		Node<T>* temp = new Node<T>(n);
		temp->setNext(Head);
		Head = temp;
		Head->setPrev(nullptr);
		if (temp->getNext())
			temp->getNext()->setPrev(temp);
	}

	void InsertLast(T n)
	{
		if (!Head)
		{
			Head = new Node<T>(n);
			return;
		}
		Node<T>* temp = new Node<T>(n);
		Node<T>* tail = Head;

		while (tail->getNext())
			tail = tail->getNext();

		temp->setPrev(tail);
		temp->setNext(nullptr);
		temp->getPrev()->setNext(temp);
	}

	void DeleteBeg()
	{
		if (!Head)
			return;

		if (Head->getNext() == nullptr)
		{
			delete Head;
			Head = nullptr;
			return;
		}

		Node<T>* temp = Head;
		Head = Head->getNext();
		delete temp;
		temp = nullptr;
		Head->setPrev(nullptr);
	}

	void DeleteLast()
	{
		if (!Head)
			return;

		if (Head->getNext() == nullptr)
		{
			delete Head;
			Head = nullptr;
			return;
		}

		Node<T>* tail = Head;

		while (tail->getNext())
			tail = tail->getNext();

		tail->getPrev()->setNext(nullptr);
		delete tail;
		tail = nullptr;
	}

	void DisplayBackward()
	{
		if (!Head)
			return;

		Node<T>* tail = Head;

		while (tail->getNext())
			tail = tail->getNext();

		while (tail)
		{
			cout << tail->getItem();
			tail = tail->getPrev();
			if (tail)
				cout << " ";
		}
		cout << "NULL\n";
	}

	void Delete(T d)
	{
		Node<T>* temp = Head;
		while (temp)
		{
			if (temp->getItem() == d)
			{
				if (temp->getPrev() == nullptr)
				{
					DeleteBeg();
					temp = Head;
				}
				else if (temp->getNext() == nullptr)
				{
					DeleteLast();
					break;
				}
				else
				{
					temp->getPrev()->setNext(temp->getNext());
					temp->getNext()->setPrev(temp->getPrev());

					Node<T>* toDelete = temp;
					temp = temp->getNext();

					delete toDelete;
				}
			}
			else
				temp = temp->getNext();
		}
	}

	void InsertAfter(T d, T D)
	{
		Node<T>* temp = Head;
		while (temp)
		{
			if (temp->getItem() == d)
			{
				if (temp->getNext() == nullptr)
				{
					Node<T>* node = new Node<T>(D);
					node->setNext(nullptr);
					node->setPrev(temp);
					temp->setNext(node);
					return;
				}
				
				Node<T>* node = new Node<T>(D);
				node->setNext(temp->getNext());
				node->setPrev(temp);
				temp->setNext(node);
				node->getNext()->setPrev(node);
				return;
			}
			temp = temp->getNext();
		}
	}

	DoublyLinkedList(const DoublyLinkedList<T>& other)
{
    Head = nullptr;
    Node<T>* current = other.Head;

    while (current)
    {
        InsertLast(current->getItem());
        current = current->getNext();
    }
}

	friend bool FoldBiotonic(DoublyLinkedList<int>& L, DoublyLinkedList<int>& Res);
};
#endif	