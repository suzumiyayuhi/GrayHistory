//16_25
//extern template class vector<string>;
//��vector<string>ʵ��������Ϊextern,���������������ļ���ʵ����
//template class vector<Sales_data>;
//��ʾ�ڸ��ļ���ʵ����vector<Sales_data>

#include<iostream>
#include<vector>
using namespace std;
//16_26
struct NoDefault {
public:
	explicit NoDefault(string a):s(a ){}
private:
	string s;
};
int main() {
//	template vector<NoDefault>;
	getchar();
}
//http://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co
//________________________


//16_27
/*
template <typename T> class Stack{};
void f1(Stack<char>); û��ʵ����
class Exercise{
Stack<double> &rsd;û��ʵ����
Stack<int> si;û��ʵ����
};
int main(){
Stack<char> *sc;û��ʵ����
f1(*sc);ʵ������
int iObj = sizeof(Stack<string>);û��ʵ����
}
*///_______________________________________________-