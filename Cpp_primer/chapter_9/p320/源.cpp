//9_35
//capacity代表容器所分配的空间大小可以容纳多少条数据，size指容器内的数据数目。

//9_36
//不可能

//9_37
//list作为链表数据存储在内存并不是物理紧邻的，删除元素意味着释放空间，添加元素因为增加空间。
//array为固定大小数组，空间固定。

#include<iostream>
#include<vector>
using namespace std;
void X9_38() {
	vector<int> x;
	for (int i = 0; i < 20; ++i) {
		x.push_back(1);
		cout << x.size() << " ";
		cout << x.capacity();
		cout << endl;
	}
}
//9_39
//首先创建一个空的vector<string>对象svec，给svec分配至少容纳1024个string的空间，接受标准输入流输入的string对象并添加进svec。
//最后在容器后添加svec.size()+svec.size()/2个空string。

//9_40
//1024，1024，1536，2304

int main() {
	X9_38();
	getchar();
	return 0;
}