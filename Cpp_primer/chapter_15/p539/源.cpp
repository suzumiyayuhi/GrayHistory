//15_12
//�б�Ҫ
//����override,����ʹ��������Ҫ���Ǹ��麯������ͼ��ø�Ϊ����
//final���ǲ�����ú���������

//15_13
#include"Bulk_Quote.h"
using namespace std;
class base {
public:
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
	virtual void a() { cout << "a" << endl; }
private:
	string basename;
};
class derived :public base {
public:
	void print(ostream &os) { print(os); os << " " << i; }
	void a() override { cout << "b" << endl; }
private:
	int i;
};
//derived���е�print��������ɵݹ���ѭ��,��print(os)��Ϊbase::print(os)
int main() {
	//15_14
	base bobj;
	derived dobj;
	base *bp1 = &bobj;
	base *bp2 = &dobj;
	base &br1 = bobj;
	base &br2 = dobj;
/*
	bobj.print(); base�෽��
	dobj.print();derived�෽��
	bp1->name();base�෽��
	bp2->name();base�෽��
	br1.print();base�෽��
	br2.print();derived�෽��
	*/
	//____________________________________________________________
	getchar();
}