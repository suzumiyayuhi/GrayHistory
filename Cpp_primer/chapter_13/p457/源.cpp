#include<iostream>
#include<memory>
using namespace std;
//13_27
struct HasPtr
{
public:
	HasPtr(int aa, string bb) :a(aa), b(new string(bb)),counter(new size_t(1)) {}
	HasPtr(const HasPtr &q):a(q.a),b(q.b),counter(q.counter) { ++(*counter); }
	HasPtr& operator=(const HasPtr &q) {
		a = q.a;
		b = q.b;
		++*q.counter;
		counter = q.counter;
		if (--*counter == 0)
		{
			delete b;
			delete counter;
		}
		return *this;
	}
	~HasPtr()
	{
		if (--(*counter) == 0) {
			delete b;
			delete counter;
		}
	}
private:
	int a;
	string *b;
	size_t *counter;
};
//13_28
//(a)
//____________________________________________________________________________________
class TreeNode {
public:
	TreeNode(string a, TreeNode *c, TreeNode *d) :value(a), counter(new int(1)), left(c), right(d) {  }
	TreeNode(const TreeNode &q) :value(q.value),counter(q.counter),left(q.left),right(q.right) {
		++*counter;
	}
	TreeNode& operator=(const TreeNode& q) {
		value = q.value;
		if (--*counter == 0)
		{
			delete counter;
			delete left;
			delete right;
		}
		counter = q.counter;
		++*counter;
		right = q.right;
		left = q.left;
		return *this;
	}
	~TreeNode()
	{
		if (--*counter == 0) {
			delete counter;
			delete left;
			delete right;
		}
	}
private:
	string value;
	int *counter;
	TreeNode *left;
	TreeNode *right;
};
//(b)
//____________________________________________________________________________________
class BingStrTree {
public:
	BingStrTree(TreeNode *a) :root(a) {}
	BingStrTree(const BingStrTree &a) {
		root = a.root;
	}
	BingStrTree& operator=(const BingStrTree &a) { 
		delete root;
		root = a.root;
		return *this;
	}
	~BingStrTree()
	{
		delete root;
	}
private:
	TreeNode *root;
};