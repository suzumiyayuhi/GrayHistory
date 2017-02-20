//16_59
//将s转换为string类型的右值引用
//再通过StrVec的移动构造函数创造新元素


#include<iostream>
#include<memory>
#include<utility>
using namespace std;
//16_60
//将给定数值转为右值引用，再通过shared_ptr的移动构造函数构建新元素

//16_61
template<typename T1,typename ...T2>
shared_ptr<T1> make_sharedX(T2 ...t) {
	return shared_ptr<T1> (new T1 (forward<T2>(t)...));
}
//_______________________________________
int main() {
	auto a = make_sharedX<int>(1);
	cout << *a;
	getchar();
}