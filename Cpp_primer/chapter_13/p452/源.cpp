#include<iostream>
using namespace std;
//13_18
struct Employee
{
public:
	string name;
	int ID;
	Employee() { ++counter; ID = counter; }
	static int counter;
private:
	
};
int Employee::counter = 0;
int main() {
	Employee a;
	cout << a.counter;
	getchar();
}
//13_19
//����Ҫ��ÿ��emplyee�����ǲ�ͬ��

//13_20
//����T����T��Text�ͱ����ƶ����Textָ����ͬ��ָ��ͬһ�ļ���result�е�string������ͬ��size_type������ͬ��ַ
//����Q��keyΪ��ֵͬ��TextΪ��ָͬ�룻linesҲΪ��ָͬ��
//����ʱ�����ٳ�Ա���ͷ�ָ��

//13_21
//����Ҫ��ʹ�õ�������ָ�룬���ۺ�ʱ�����԰�ȫ���ͷ�ָ��

//13_22
struct HasPtr
{
public:
	HasPtr(const HasPtr &a):xx(a.xx),yy(new string(*a.yy)) { }
	HasPtr& operator=(const HasPtr &a) { 
		auto temp = *a.yy;
		delete yy;
		yy = new string(temp);
		xx = a.xx; 
		return *this;
	}
private:
	int xx;
	string *yy;
};