//13_6
//����Ϊ����
//����ͨ�������ķ�ʽ��ʼ��һ�����󣬻��߶Զ�����и�ֵ
//ʹ�ø�ֵ�������������һ������
//����û�ж�����������������ɣ�Ҳ�������ж���

//13_7
//���ɹ���ʹ���˿������������
#include"StrBlob.h"
int main() {
	StrBlob a({ "ss","sd" });
	StrBlob b = a;
	StrBlobptr c(a);
	StrBlobptr d;
	d = c;
	getchar();
	return 0;
}

//13_8
struct HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
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
