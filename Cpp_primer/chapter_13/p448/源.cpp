#include<iostream>
#include<memory>
using namespace std;	
int a = 0;

//13_14
//�����ͬ��ֵ

//13_15
//��ı�,�ÿ����������������ÿ������캯��

//13_16
//�������ᱻ�ı�
//f����ʵ�λ���ÿ������캯��������һ����ʱ����
//������const���;Ͳ���ı����ݽṹ�е�����

//13_17
struct numbered{
public:

	numbered() { ++a; mysn = a;  }
	numbered(const numbered &b) { ++a; mysn = a; }
	int mysn;
};
void f( numbered a) {
	cout << a.mysn << endl;
}
int main() {
	numbered c, d = c, e = c;
	f(c); f(d); f(e); 
	getchar();
}