#include<iostream>
#include<string>
#include<memory>
#include<vector>
using namespace std;
//12_6
vector<int>* rturn() {
	vector<int> *x = new vector<int>;
	return x;
}
vector<int>* vecin() {
	auto a = rturn();
	int b;
	while (cin >> b)
	{
		(*a).push_back(b);
	}
	return a;
}
void vecout() {
	auto a = vecin();
	for (auto x : (*a))
		cout << x;
	delete a;
	a = nullptr;
}
//——————————————————————————————————————————————————————————————————————————————————————————————
//12_7
shared_ptr<vector<int>> vecbuild() {
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>> vectin() {
	int a;
	auto b = vecbuild();
	while (cin>>a)
	{
		b->push_back(a);
	}
	return b;
}
void vectout() {
	auto a = vectin();
	for (auto x : *a)
		cout << x;
}

//————————————————————————————————————————————————————————————————————————————————————————————————
//12_8
//p为指向int的指针，p转换为bool返回，使得内存不能释放，造成内存泄漏

//12_9
//r指向q所指向的地方，q指向42，并没被销毁，两者皆为内置指针，r没有办法释放内存
//r2指向q2所指向的地方，q2指向42，两者为智能指针
int main() {
	vectout();
	getchar();
	return 0;
}