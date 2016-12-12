//13_29
//在swap(HasPtr&,HasPtr&)中调用的swap是标准库里的swap

//13_30
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
struct HasPtr
{
public:
	friend void swap(HasPtr a, HasPtr b);
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &p) :ps(new string(*p.ps)), i(p.i) {}
	HasPtr operator=(const HasPtr &p);
	//13_31
	bool operator<(const HasPtr &p) {
		cout << "<";
		return *ps < *p.ps;
	}
	//_____________________________________________________
	~HasPtr()
	{
		delete ps;
	}
private:
	string *ps;
	int i;
};
HasPtr HasPtr::operator=(const HasPtr &p) {
	delete ps;
	ps = new string(*p.ps);
	i = p.i;
	return *this;
}
void swap(HasPtr a, HasPtr b) {
	swap(a.i, b.i);
	swap(a.ps, b.ps);
	cout << "swap";
}
int main() {
	HasPtr a("dd");
	HasPtr b("xx");
	vector<HasPtr> x;
	x.push_back(a);
	x.push_back(b);
	sort(x.begin(),x.end());
	swap(a, b);
	getchar();
	return 0;
}
//13_32
//不会