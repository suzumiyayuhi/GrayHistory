#include<string>
#include<iostream>
#include<list>
#include<forward_list>
using namespace std;
void X9_31(list<int> &a1) {
	auto x = a1.begin();
	while (x!=a1.end())
	{
		if (*x % 2) 
		{
			x=a1.insert(x, *x);
			++x;
			++x;
		}
		else
		{
			x=a1.erase(x);
		}
	}
}
void X9_31(forward_list<int> &a1) {
	auto x = a1.begin();
	auto y = a1.before_begin();
	while (x != a1.end())
	{
		if (*x % 2)
		{
			x = a1.insert_after(x, *x);
			y = x;
			++x;
		}
		else
		{
			x=a1.erase_after(y);
		}
	}
}
//9_32
//���Ϸ�
//����ʱ�����������ȴ���*iter++����ֵ����ɵ�һ�����ݵ�ʵ�γ������������ҡ�

//9_33
//ԭ�ȵ�begin��ʧЧ�����³������

//9_34
//���������������ҵ������������һ��������ֵ��ͬ��int���󣬲���������ָ����֮���һ��int����
//����++iterû����ѭ����֮�У�������֮����ż�����ڻ�ʹ����������ѭ����
int main() {
	list<int> a1{ 1,2,3,4,5,6,7,8 };
	forward_list<int> a2{ 1,2,3,4,5,6,7,8 };
	X9_31(a1);
	for (auto i : a1)
		cout << i;
	cout << endl;
	X9_31(a2);
	for (auto i : a2)
		cout << i;
	getchar();
	return 0;
}
