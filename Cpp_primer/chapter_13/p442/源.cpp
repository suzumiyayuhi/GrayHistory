//13_1
//�ں�������ʱʹ��
//���У�������ʼ������
//�š��������и��ࡣ�������ܡ�����

//13_2
//������Ǹ�sales_data��������
//������ÿ������캯�������
//����ʵ�ε��ÿ������캯�������ÿ������캯������ʵ�Ρ�����ѭ��������

//13_3
#include"StrBlob.h"
int main() {
	StrBlob a = { "sd","sd" };
	StrBlob b = a;
	StrBlobptr c(a);
	StrBlobptr d = c;
	//���񲻻ᷢ��ʲô���� -_-||
}

//13_4
//Point global;
//Point foo_bar(Point arg){			����= =
//Point local=arg, *heap = new Point(global);	�����һ�������ʼ��= =
//*heap = local;
//Point pa[ 4 ] = {local, *heap};	�����һ�������ʼ����
//return *heap;
//}


//13_5
struct HasPtr{
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
private:
	std::string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &a) :ps(new std::string(*a.ps)), i(a.i) {}
