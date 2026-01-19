
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

// =========================== STACK Code ==================================
# define STACK_SIZE 100
template<typename T>
class ArrayStack  //Dont change this
{
private:
	T items[STACK_SIZE];		// Array of stack items
	int      top;                   // Index to top of stack

public:

	ArrayStack()
	{
		top = -1;
	}  // end default constructor

	//Function getCapacity() returns the stack max size
	//added for array implementaion only 
	int getCapacity()
	{
		return STACK_SIZE;
	}

	bool isEmpty() const
	{
		return top == -1;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (top == STACK_SIZE - 1) return false;	//Stack is FULL

		top++;
		items[top] = newEntry;
		return true;
	}  // end push

	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		top--;
		return true;
	}  // end pop

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		return true;
	}  // end peek


	//Copy constructor
	ArrayStack(const ArrayStack<T>& S)
	{
		for (int i = 0; i <= S.top; i++)
			items[i] = S.items[i];
		top = S.top;
	}

}; // end ArrayStack

// =========================== QUEUE Code ==================================

template < typename T>
class Node
{
private:
	T item; // A data item
	Node<T>* next; // Pointer to next node
public:

	Node()
	{
		next = nullptr;
	}

	Node(const T& r_Item)
	{
		item = r_Item;
		next = nullptr;
	}

	Node(const T& r_Item, Node<T>* nextNodePtr)
	{
		item = r_Item;
		next = nextNodePtr;
	}
	void setItem(const T& r_Item)
	{
		item = r_Item;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	Node<T>* getNext() const
	{
		return next;
	}

};

template <typename T>
class LinkedQueue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:

	LinkedQueue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;

	}

	bool isEmpty() const
	{
		return (frontPtr == nullptr);
	}

	bool enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		// Insert the new node
		if (isEmpty())	//special case if this is the first node to insert
			frontPtr = newNodePtr; // The queue is empty
		else
			backPtr->setNext(newNodePtr); // The queue was not empty

		backPtr = newNodePtr; // New node is the last node now
		return true;
	} // end enqueue

	bool dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
			backPtr = nullptr;

		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;
		return true;
	}

	bool peek(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;
	}

	~LinkedQueue()
	{
		T temp;

		//Free (Dequeue) all nodes in the queue
		while (dequeue(temp));
	}

	// Copy Constructor
	LinkedQueue(const LinkedQueue<T>& LQ)
	{
		Node<T>* NodePtr = LQ.frontPtr;
		if (!NodePtr) //LQ is empty
		{
			frontPtr = backPtr = nullptr;
			return;
		}

		//insert the first node
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		frontPtr = backPtr = ptr;
		NodePtr = NodePtr->getNext();

		//insert remaining nodes
		while (NodePtr)
		{
			Node<T>* ptr = new Node<T>(NodePtr->getItem());
			backPtr->setNext(ptr);
			backPtr = ptr;
			NodePtr = NodePtr->getNext();
		}
	}



};

//end of queue class

template < typename T>
void PrintQueue(LinkedQueue<T> Q)
{
	T K;
	while (Q.dequeue(K))
	{
		cout << K;
		if (!Q.isEmpty())
			cout << " ";
	}
	cout << endl;
}

template < typename T>
void PrintStack(ArrayStack<T> S)
{
	T x;
	while (S.pop(x))
	{
		cout << x;
		if (!S.isEmpty())
			cout << " ";
	}
	cout << endl;
}


// =========================== The Required Function ==================================


// TODO: WRITE THE REQUIRED FUNCTION HERE
void chooseQueueValues(ArrayStack<char>& val, LinkedQueue<int>& pos, LinkedQueue<char>& choosedValue)
{
	ArrayStack<char> temps = val;

	int i = 0;
	char tempch;

	while (!temps.isEmpty())
	{
		++i;
		temps.pop(tempch);
	}

	int tempp;
	while (!pos.isEmpty())
	{
		pos.dequeue(tempp);
		if (tempp > i || tempp < 1)
			continue;

		int j;
		for (j = 0; j < i - tempp; ++j)
		{
			val.pop(tempch);
		}
		
		i -= (j+1);

		val.pop(tempch);
		choosedValue.enqueue(tempch);
	}


}


// =========================== Main ==================================

int main()
{
	int n = 0;
	char x;
	ArrayStack<char> val;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		val.push(x);
	}
	int charPos;
	LinkedQueue<int> pos;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> charPos;
		pos.enqueue(charPos);
	}
	LinkedQueue<char> choosedValue;
	chooseQueueValues(val, pos, choosedValue);
	if (!choosedValue.isEmpty())
	{
		PrintQueue(choosedValue);
		PrintStack(val);
	}
	else
	{
		cout << "Empty";
	}
	return 0;
}