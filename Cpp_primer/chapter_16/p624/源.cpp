//16_59
//��sת��Ϊstring���͵���ֵ����
//��ͨ��StrVec���ƶ����캯��������Ԫ��


#include<iostream>
#include<memory>
#include<utility>
using namespace std;
//16_60
//��������ֵתΪ��ֵ���ã���ͨ��shared_ptr���ƶ����캯��������Ԫ��

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