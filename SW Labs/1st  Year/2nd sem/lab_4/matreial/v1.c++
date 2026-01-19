#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include "string"
using namespace std;



// ============================ Tree Code ==============================

class TNode
{
private:
	int data;
	TNode* left;
	TNode* right;
public:
	TNode(int val)
	{
		data = val;
		left = right = nullptr;
	}
	void setdata(int d)
	{
		data = d;
	}
	int getdata()
	{
		return data;
	}
	void setright(TNode* p)
	{
		right = p;
	}
	TNode*& getright()
	{
		return right;
	}

	void setleft(TNode* p)
	{
		left = p;
	}
	TNode*& getleft()
	{
		return left;
	}
};

class BinaryTree
{
private:
	TNode* root;
	// ============================The private version of the required function ==============================

	// TODO




	// =====================================================================================

	void rec_destroy(TNode*& subroot) {
		if (subroot != nullptr)
		{
			// recursive call on left
			rec_destroy(subroot->getleft());

			// recursive call on right
			rec_destroy(subroot->getright());

			delete subroot;
			subroot = nullptr; // this line is why we pass subRoot by reference (subRoot = something) // (14)
		}
	}

	void printQ1(TNode* subroot)
	{
		if (subroot)
		{
			if ((subroot->getright() || subroot->getleft()) && subroot->getdata() % 2 == 0)
			{
				cout << subroot->getdata() << " ";
			}

			printQ1(subroot->getleft());
			printQ1(subroot->getright());

		}
	}



	static bool recEqualSiblings(TNode*& subroot)
	{
		if (subroot == nullptr || (!subroot->getright() && !subroot->getleft()))
			return true;

		recEqualSiblings(subroot->getleft());
		recEqualSiblings(subroot->getright());
		
		if ((subroot->getright() && subroot->getleft()))
		{
			if(subroot->getright()->getdata() != subroot->getleft()->getdata())
				return false;

			return recEqualSiblings(subroot->getleft()) && recEqualSiblings(subroot->getright());
		}
		else
		{
			if (subroot->getright())
			{
				TNode* temp = subroot->getright();
				delete temp;
				subroot->setright(nullptr);
			}
			if (subroot->getleft())
			{
				TNode* temp = subroot->getleft();
				delete temp;
				subroot->setleft(nullptr);
			}
		}


	}


public:
	BinaryTree() { root = nullptr; }
	BinaryTree(int val) { root = new TNode(val); }

	// Inserts in the first empty child for the tree to remain "Complete Tree"
	// So it inserts level by level from left to right (no gaps in the middle --> Complete Tree)
	void Insert(int val)
	{
		if (root == nullptr)
		{
			root = new TNode(val); return;
		}
		queue<TNode*>Q;
		Q.push(root);
		TNode* temp;
		while (Q.empty() == false)
		{
			temp = Q.front();
			Q.pop();
			if (temp->getleft() == nullptr) // if it doesn't have left, add the new node at left
			{
				TNode* nnode = new TNode(val);
				temp->setleft(nnode);
				return;
			}
			else // else push in queue (to check later level by level)
			{
				Q.push(temp->getleft());
			}
			if (temp->getright() == nullptr) // if it doesn't have right, add the new node at right
			{
				TNode* nnode = new TNode(val);
				temp->setright(nnode);
				return;
			}
			else // else push in queue (to check later level by level)
			{
				Q.push(temp->getright());
			}

		}
	}

	// Prints the tree level by level from left to right
	// There is a new line after each level
	void PrintTree() {
		if (root == nullptr) return;
		queue<TNode*>q;
		TNode* newline = new TNode(-99999); // a number just representing that we should print a new line here
		TNode* v;
		q.push(root);
		q.push(newline);

		while (q.empty() == false) {
			v = q.front();
			q.pop();
			if (v == newline) {
				printf("\n");
				if (q.empty() == false)
					q.push(newline);
			}
			else {
				cout << v->getdata() << " ";
				if (v->getleft() != nullptr)
					q.push(v->getleft());
				if (v->getright() != nullptr)
					q.push(v->getright());
			}
		}
		delete newline;
	}

	~BinaryTree() { rec_destroy(root); }

	// ============================The public version of the required function ==============================

	// TODO
	void printEvenParent()
	{
		printQ1(root);
	}

	bool Q1()
	{
		return recEqualSiblings(root);
	}



};

// ============================ Main Function ==============================

int main()
{
	// --- Note: Don't change the main function ----
	int n, x;
	cin >> n;
	BinaryTree BT;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		BT.Insert(x); // inserts level by level from left to right then left and so on
	}
	// Call the public version of the function


	//BT.PrintTree();
	// --- Note: Don't change the main function ----

	//BT.printEvenParent();


	//cout <<BT.Q1() << endl;
	//BT.PrintTree();





	return 0;
}

