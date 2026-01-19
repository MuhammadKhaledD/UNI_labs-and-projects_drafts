#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T item;
    Node<T>* next;
public:
    Node() : next(nullptr) {}
    Node(const T& r_Item) : item(r_Item), next(nullptr) {}
    void setItem(const T& r_Item) { item = r_Item; }
    void setNext(Node<T>* nextNodePtr) { next = nextNodePtr; }
    T getItem() const { return item; }
    Node<T>* getNext() const { return next; }
};

template <typename T>
class StackADT {
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const T& newEntry) = 0;
    virtual bool pop(T& TopEntry) = 0;
    virtual bool peek(T& TopEntry) const = 0;
    virtual ~StackADT() {}
};

template<typename T>
class ArrayStack : public StackADT<T> {
    enum { MAX_SIZE = 100 };
private:
    T items[MAX_SIZE];
    int top;
public:
    ArrayStack() { top = -1; }

    bool isEmpty() const { return top == -1; }

    bool push(const T& newEntry) {
        if (top == MAX_SIZE - 1) return false;
        top++;
        items[top] = newEntry;
        return true;
    }

    bool pop(T& TopEntry) {
        if (isEmpty()) return false;
        TopEntry = items[top];
        top--;
        return true;
    }

    bool peek(T& TopEntry) const {
        if (isEmpty()) return false;
        TopEntry = items[top];
        return true;
    }
};

template <typename T>
void PrintStack(ArrayStack<T> S) {
    T x;
    while (S.pop(x)) {
        cout << x;
        if (!S.isEmpty())
            cout << " ";
    }
    /*cout << endl;*/
}

template <typename T>
class QueueADT {
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const T& newEntry) = 0;
    virtual bool dequeue(T& frntEntry) = 0;
    virtual bool peek(T& frntEntry) const = 0;
    virtual ~QueueADT() {}
};

template <typename T>
class LinkedQueue : public QueueADT<T> {
private:
    Node<T>* backPtr;
    Node<T>* frontPtr;
public:
    LinkedQueue() : frontPtr(nullptr), backPtr(nullptr) {}

    bool isEmpty() const { return frontPtr == nullptr; }

    bool enqueue(const T& newEntry) {
        Node<T>* newNodePtr = new Node<T>(newEntry);
        if (isEmpty())
            frontPtr = newNodePtr;
        else
            backPtr->setNext(newNodePtr);
        backPtr = newNodePtr;
        return true;
    }

    bool dequeue(T& frntEntry) {
        if (isEmpty()) return false;

        Node<T>* nodeToDeletePtr = frontPtr;
        frntEntry = frontPtr->getItem();
        frontPtr = frontPtr->getNext();

        if (nodeToDeletePtr == backPtr)
            backPtr = nullptr;

        /*delete nodeToDeletePtr;*/
        return true;
    }

    bool peek(T& frntEntry) const {
        if (isEmpty()) return false;
        frntEntry = frontPtr->getItem();
        return true;
    }

    ~LinkedQueue() {
        T temp;
        while (dequeue(temp));
    }
};

template <typename T>
void PrintQueue(LinkedQueue<T> Q) {
    T K;
    while (Q.dequeue(K)) {
        cout << K;
        if (!Q.isEmpty())
            cout << " ";
    }
}




LinkedQueue<int> sumNeg(LinkedQueue<int> Q)
{
    LinkedQueue<int> res;
    LinkedQueue<int> tempq;
    ArrayStack<int> temps;
    bool neg = false;
    int num;

    while (!Q.isEmpty())
    {
        Q.dequeue(num);

        if (num >= 0 && !neg)
        {
            res.enqueue(num);
        }
        else if (num >= 0 && neg)
        {
            tempq.enqueue(num);
            temps.push(num);
        }
        else if (num < 0 && !neg)
        {
            neg = true;
        }
        else if (num < 0 && neg)
        {
            while (!temps.isEmpty())
            {
                temps.pop(num);
                res.enqueue(num);
                tempq.dequeue(num);
            }
        }

    }
        while (!tempq.isEmpty())
        {
            tempq.dequeue(num);
            res.enqueue(num);
        }

    return res;
}

int main()
{
    // note in the input you enter the size before entering the elements
    LinkedQueue<int> Q, result;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Q.enqueue(x);
    }

    result = sumNeg(Q);
    PrintQueue(result);
    return 0;
}