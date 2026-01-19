
// NOTE: NO COPY CONSTRUCTOR OR ASSIGNMENT OPERATOR DEFINED FOR TREE

// TODO: WRITE YOUR NAME AND ID
// STUDENT NAME: Muhammad Khaled Hamed
// STUDENT ID:   91240653

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

	void rec_destroy(TNode*& subroot) {
		if (subroot != nullptr)
		{
			// recursive call on left
			rec_destroy(subroot->getleft());

			// recursive call on right
			rec_destroy(subroot->getright());

			delete subroot;
			subroot = nullptr; // this line is why we pass subRoot by reference (subRoot = something)
		};
	}

	// =========================== The Required Function ==================================

	// TODO
	bool recLeavesDivisibles(TNode*& subRoot)
	{
		if (!subRoot)
		{
			subRoot = new TNode(0);
			return false;
		}

		if (!subRoot->getleft() && !subRoot->getright())
		{
			return true;
		}


		if (subRoot->getleft()->getleft()) // has ch has lev
		{
			TNode* l = new TNode(0);
			TNode* r = new TNode(0);

			TNode* templ = subRoot->getleft();

			TNode* tempr = subRoot->getright();

			l->setleft(templ);
			r->setright(tempr);

			subRoot->setleft(l);
			subRoot->setright(r);
			bool ll, rr;

			ll = recLeavesDivisibles(subRoot->getleft()->getleft());
			rr = recLeavesDivisibles(subRoot->getright()->getright());

			return  ll && rr;
		}
		else if (subRoot->getright()) // has left and right lev
		{
			int templ, tempr;
			templ = subRoot->getleft()->getdata();
			tempr = subRoot->getright()->getdata();

			if (tempr % 10 == 0 && templ % 10 == 0)
			{
				templ += tempr;
				templ += subRoot->getdata();
				subRoot->setdata(templ);

				TNode* tl = subRoot->getleft();
				TNode* tr = subRoot->getright();

				delete tl;
				delete tr;

				tl = nullptr;
				tr = nullptr;

				subRoot->setleft(tl);
				subRoot->setright(tr);
			}
			else if (tempr % 10 == 0)
			{
				templ *= 10;
				subRoot->getleft()->setdata(templ);
			}
			else if (templ % 10 == 0)
			{
				tempr *= 10;
				subRoot->getright()->setdata(tempr);
			}
			else
			{
				tempr *= 10;
				subRoot->getright()->setdata(tempr);
				templ *= 10;
				subRoot->getleft()->setdata(templ);
			}
			
			return false;
		}
		else // has left lev
		{
			int temp = subRoot->getleft()->getdata();
			if (temp % 10 == 0)
			{
				temp += subRoot->getdata();
				subRoot->setdata(temp);

				TNode* t = subRoot->getleft();
				delete t;
				t = nullptr;
				subRoot->setleft(t);
			}
			else
			{
				temp *= 10;
				subRoot->getleft()->setdata(temp);
			}


			return false;
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


	bool LeavesDivisibles()
	{
		// Note: You may change in the public function if needed
		return !recLeavesDivisibles(root);
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

	bool result = BT.LeavesDivisibles();
	cout << result << endl;
	BT.PrintTree();
	// --- Note: Don't change the main function ----

	return 0;
}
