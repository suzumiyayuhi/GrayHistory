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
//weak_ptr<vector<string>>�������Լ�����������������������������������Ʒ���
//size_t����������
//=>>���ö�����