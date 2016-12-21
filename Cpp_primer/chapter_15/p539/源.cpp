//15_12
//有必要
//填上override,可以使得我们需要覆盖该虚函数的意图变得更为明显
//final则是不允许该函数被覆盖

//15_13
#include"Bulk_Quote.h"
using namespace std;
class base {
public:
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
	virtual void a() { cout << "a" << endl; }
private:
	string basename;
};
class derived :public base {
public:
	void print(ostream &os) { print(os); os << " " << i; }
	void a() override { cout << "b" << endl; }
private:
	int i;
};
//derived类中的print函数会造成递归死循环,讲print(os)改为base::print(os)
int main() {
	//15_14
	base bobj;
	derived dobj;
	base *bp1 = &bobj;
	base *bp2 = &dobj;
	base &br1 = bobj;
	base &br2 = dobj;
/*
	bobj.print(); base类方法
	dobj.print();derived类方法
	bp1->name();base类方法
	bp2->name();base类方法
	br1.print();base类方法
	br2.print();derived类方法
	*/
	//____________________________________________________________
	getchar();
}