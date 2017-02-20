#include"Sales_data.h"
#include<strstream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef tuple<size_t, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> res;

bool compareIsbn(const Sales_data &a, const Sales_data &b) {
	return a.bookNo < b.bookNo;
}
//17_4
vector<res> findBook(const vector<vector<Sales_data>> &files, const string &book) 
{
	vector<res> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto tem = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (tem.first != tem.second) {
			ret.push_back(make_tuple(it - files.cbegin(), tem.first, tem.second));
		}
	}
	return ret;
}
//_____________________________________
//17_5
typedef pair < size_t, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> rusX;
vector<rusX> findBookX(const vector<vector<Sales_data>> &files, const string &book) 
{
	vector<rusX> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto tem = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (tem.first != tem.second) {
			ret.push_back(make_pair(it - files.cbegin(), make_pair(tem.first, tem.second)));
		}
	}
	return ret;
}
//_________________________________________________________
//17_6
struct rusEX {
public:
	rusEX(size_t a,vector<Sales_data>::const_iterator b,vector<Sales_data>::const_iterator c):
		index(a),itbeg(b),itend(c){}

	size_t index;
	vector<Sales_data>::const_iterator itbeg;
	vector<Sales_data>::const_iterator itend;
};
vector<rusEX> findBookEX(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<rusEX> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto tem = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (tem.first != tem.second) {
			ret.push_back(rusEX(it-files.cbegin(	),tem.first,tem.second);
		}
	}
	return ret;
}
//____________________________________________________________

//17_7
//���һ���汾������һ����������ݽṹ��������ά��

//17_8
//ûʲôӰ�죬����Ӧ����ʾbookNo�ĵط��ǿյģ�http://blog.csdn.net/chxw098/article/details/39852845��
int main() {
	Sales_data a("a", 2, 3.0);
	Sales_data b("b", 1, 3.0);
	Sales_data c("c", 4, 2.0);
	Sales_data d("a", 3, 3.0);
	vector<Sales_data> X{ a,b,c };
	vector<Sales_data> Y{ d };
	vector<vector<Sales_data>> ZZ{ X,Y };
	auto tem = findBook(ZZ, "a");
	for (auto ZZZ : tem)
		cout << get<0>(ZZZ) << endl;//���Ϊ0 1,��������ֻ��һ�����������û������ָ����Ӧ��Ϊ��

	getchar();
}