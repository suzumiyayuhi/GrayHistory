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
/*	vector<int> vec = { 1,2,3,4,5 };		Դ����vecΪ��vector������ʹ��back_inserter�����߽�vec��ʼ��Ϊ�ǿ�����lst����ͬ��С��������
	list<int> lst;
	int i, j = 0;
	while (cin>>i)							Դ�����������ѭ�������ü���������ѭ����
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
	//����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
	/*
	vector<int> vec;					reserveֻ��������������Ԫ�ص���������û�иı���������ڵĴ�С�����vec��Ϊ��������������������
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
	*/
}
//10_8
//ʹ��back_inserterʱ������ÿ�θ�ֵǰ����push_back���������ɴ˸ı��С���������㷨�ı���������С��


int main() {
	vector<int> a = { 1,2,3,4,5,67 };
//	X10_6(a);
//	X10_7();
	getchar();
	return 0;
}