//13_9
//����������һ�����͵ĳ�Ա����
//��������һ������
//û�����ж���ʱ�������������ж���

//13_10
//StrBlob��������
//StrBlobPtr������ʱ���ڴ治����ȫ�ͷ�

//13_11
#include<iostream>
using namespace std;
struct HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
	~HasPtr() {}
	HasPtr& operator=(const HasPtr &a) {
		delete(ps);
		string *newstr = new string(*a.ps);
		ps = newstr;
		i = a.i;
		return *this;
	}
private:
	std::string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &a) :ps(new std::string(*a.ps)), i(a.i) {}

//13_12
//3

struct x {
	x() { cout << "x()" << endl; }
	x(const x& a) { cout << "x(const x& a" << endl; }
	x& operator=(const x& a) { cout << "operator=(const x &a"<<endl; return *this; }
	~x() { cout << "~x()"<<endl; }
};
void ss(x a) {

}
int main() {
	x a, b;
	a = b;
	x c(a);
	ss(a);
	getchar();
	return 0;
}