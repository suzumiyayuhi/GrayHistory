#include<memory>
#include<iostream>
using namespace std;
//12_10
//正确
void process(shared_ptr<int> a) {
	int b;
	b = *a + 1;
	cout << b<<" "<<a.use_count()<<endl;
}
int main() {
	shared_ptr<int> a(new int(2));
//	process(shared_ptr<int>(a));

//——————————————————————————————————————————————————————————————————————————————————————————————

//12_11
//	process(shared_ptr<int>(a.get()));
//a.get()返回内置指针，当process结束时，该指针会被释放

//——————————————————————————————————————————————————————————————————————————————————————————————

	//12_12
//	auto p = new int();
//	auto sp = make_shared<int>();
//	process(sp);	sp使用默认初始化为指向0的智能指针，调用正确
//	process(new int()); //调用错误，new int()创造了一个临时内置指针
//	process(p);	调用错误，p为内置指针，不能转换为智能指针
//	process(shared_ptr<int>(p));调用正确，但是程序结束后，指针会被释放

//——————————————————————————————————————————————————————————————————————————————————————————————

	//12_13
	auto sp = make_shared<int>();
	auto p = sp.get();
	delete p;
	//sp为指向0的智能指针，p为指向sp的内置指针，随后释放p，同时释放sp
	//程序结束时会进行二次销毁
//——————————————————————————————————————————————————————————————————————————————————————————————
	getchar();
	return 0;
}