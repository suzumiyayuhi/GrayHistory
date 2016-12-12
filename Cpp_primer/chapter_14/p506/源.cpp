#include"StrBlob.h"
#include"StrBlobptr.h"
int main() {
	StrBlob a({ "ddd","ccc" });
	StrBlobptr b(a);
	auto p = make_shared<StrBlobptr> (b);
	cout << b.operator->();
	getchar();
}
//14_31
//weak_ptr<vector<string>>定义了自己的析构函数，拷贝复制运算符，拷贝复制符号
//size_t是内置类型
//=>>不用定义啦