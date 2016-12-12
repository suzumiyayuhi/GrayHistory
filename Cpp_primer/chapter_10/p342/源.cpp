#include<iostream>
#include<iterator>
#include<vector>
#include<list>
using namespace std;
void X10_6(vector<int> &a) {
	fill_n(a.begin(), a.size(), 0);
	for (auto x : a)
		cout << x;
}
void X10_7() {
/*	vector<int> vec = { 1,2,3,4,5 };		源代码vec为空vector，可以使用back_inserter，或者将vec初始化为非空且与lst有相同大小的容器。
	list<int> lst;
	int i, j = 0;
	while (cin>>i)							源代码会陷入死循环，设置计数器控制循环。
	{
		lst.push_back(i);
		++j;
		if (j==5)
		{
			break;
		}
	}
	copy(lst.cbegin(), lst.cend(), vec.begin());
	*/
	//———————————————————————————————————————————————————————————————————————————————————————————————
	/*
	vector<int> vec;					reserve只提升容器可容纳元素的数量，并没有改变该容器现在的大小，因此vec认为空容器，所以引发错误。
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
	*/
}
//10_8
//使用back_inserter时，会在每次赋值前进行push_back操作，藉由此改变大小，而非是算法改变了容器大小。


int main() {
	vector<int> a = { 1,2,3,4,5,67 };
//	X10_6(a);
//	X10_7();
	getchar();
	return 0;
}