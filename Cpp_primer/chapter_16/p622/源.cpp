#include<iostream>
using namespace std;
int i = 0;
template<typename T>
ostream& print(ostream& os, const T &data) {
	return os << data << endl;
}

template<typename ...T>
ostream& print(ostream &os, const T& ...datas) {
	return os << datas;
}

template<typename T,typename ...T1>
ostream& print(ostream& os,const T &data,const T1&... datas){
	os << data << " ";
	return print(os, datas...);
}
//16_56
template<typename T>
int counter(ostream &os,const T& datas) {
	return ++i;
}

template<typename ...T>
ostream& erroMsg(ostream& os, const T&... datas) {
	return print(os, counter(os,datas)...);
}
//________________________________________________

//16_57
//�ɱ�����汾��errorMsg���Ƚ�����д�����У����һ���ӡ�����
//����һ���汾�������δ�ӡ
int main() {
	erroMsg(cout, "dd", 12, "ddd");
	getchar();
}