//9_35
//capacity��������������Ŀռ��С�������ɶ��������ݣ�sizeָ�����ڵ�������Ŀ��

//9_36
//������

//9_37
//list��Ϊ�������ݴ洢���ڴ沢����������ڵģ�ɾ��Ԫ����ζ���ͷſռ䣬���Ԫ����Ϊ���ӿռ䡣
//arrayΪ�̶���С���飬�ռ�̶���

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
//���ȴ���һ���յ�vector<string>����svec����svec������������1024��string�Ŀռ䣬���ܱ�׼�����������string������ӽ�svec��
//��������������svec.size()+svec.size()/2����string��

//9_40
//1024��1024��1536��2304

int main() {
	X9_38();
	getchar();
	return 0;
}