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
//可变参数版本的errorMsg是先将数据写入流中，最后一起打印出结果
//而另一个版本则是依次打印
int main() {
	erroMsg(cout, "dd", 12, "ddd");
	getchar();
}