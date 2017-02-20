#include<iostream>
#include<type_traits>
#include<vector>
using namespace std;

template <typename It>
auto fcn3(It beg, It end)->decltype(*beg + 0) {
	return *beg;
}
//16_41
template<typename T>
auto sum(T a, T b)->decltype(a + b) {
	return a + b;
}
//__________________________________________

int main() {
	//16_40
	vector<int> a = { 1,2,3,4 };
	cout<< fcn3(a.begin(), a.end());
	//合法，类型为It所指向数据元素的类型
	//______________________________________
	getchar();
	return 0;
}