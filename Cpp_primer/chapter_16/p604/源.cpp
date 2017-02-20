#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;

//16_39
template <typename T1,typename T2>
T1 compare(const T2 &v1, const T2 &v2) {
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}
//__________________________________________

int main() {
	int a = 3;
	double b = 3.4;
	//16_37
	//auto x = max<int,double>(a, b);
	//很明显，并不行，他只提供了一个模板实参

	//16_38
	//返回一个与给定模板实参相对应的shared_ptr

	auto x = compare<int>("jj", "hh");
	cout << x;
	getchar();
	return 0;
}