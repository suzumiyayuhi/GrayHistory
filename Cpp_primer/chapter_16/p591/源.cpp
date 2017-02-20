//16_9
//一个创建类或函数的蓝图或者说公式

//16_10
//会重写模板，将模板参数类型改为给定的参数类型

//16_11
#include<list>
#include"Blob_and_BlobPtr.h"
#include"Screen.h"
#include"Vec.h"
#include<string>
template<typename elemType> class ListItem {

};
template<typename elemType> class List {
public:
	List<elemType>(){}
	List<elemType>(const List<elemType> &){}
	List<elemType>& operator=(const List &);
	~List(){}
	void insert(ListItem<elemType> *ptr, elemType value);//ListItem后加<elemType>
private:
	ListItem<elemType> *front, *end;//ListItem后加<elemType>
};
//_______________________________________________________________
//16_13
//一对一关系

int main() {
	List<int> a;
	Blob<int> b({ 1,2 });
	Screen<3,4> c;
	cout << c;
	Vec<int> d({1,3 });
	getchar();
}
