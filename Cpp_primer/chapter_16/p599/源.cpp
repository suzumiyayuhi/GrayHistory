//16_25
//extern template class vector<string>;
//将vector<string>实例化声明为extern,表名该类在其他文件中实例化
//template class vector<Sales_data>;
//表示在该文件中实例化vector<Sales_data>

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
void f1(Stack<char>); 没有实例化
class Exercise{
Stack<double> &rsd;没有实例化
Stack<int> si;没有实例化
};
int main(){
Stack<char> *sc;没有实例化
f1(*sc);实例化了
int iObj = sizeof(Stack<string>);没有实例化
}
*///_______________________________________________-