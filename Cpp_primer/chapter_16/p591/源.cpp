//16_9
//һ���������������ͼ����˵��ʽ

//16_10
//����дģ�壬��ģ��������͸�Ϊ�����Ĳ�������

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
	void insert(ListItem<elemType> *ptr, elemType value);//ListItem���<elemType>
private:
	ListItem<elemType> *front, *end;//ListItem���<elemType>
};
//_______________________________________________________________
//16_13
//һ��һ��ϵ

int main() {
	List<int> a;
	Blob<int> b({ 1,2 });
	Screen<3,4> c;
	cout << c;
	Vec<int> d({1,3 });
	getchar();
}
