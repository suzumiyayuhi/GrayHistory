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
//��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
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

//������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//12_8
//pΪָ��int��ָ�룬pת��Ϊbool���أ�ʹ���ڴ治���ͷţ�����ڴ�й©

//12_9
//rָ��q��ָ��ĵط���qָ��42����û�����٣����߽�Ϊ����ָ�룬rû�а취�ͷ��ڴ�
//r2ָ��q2��ָ��ĵط���q2ָ��42������Ϊ����ָ��
int main() {
	vectout();
	getchar();
	return 0;
}