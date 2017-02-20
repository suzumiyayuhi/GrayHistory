#include"Sales_data.h"
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<strstream>
using namespace std;
//16_62
template<> struct hash<Sales_data> {
	size_t operator()(const Sales_data &s) const {
		return hash<string>()(s.book_no) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenu);
	}
};
//_________________________________________________

//16_63
template<typename T> int counter(const vector<T> &vec, T val) {
	int z = 0;
	for (auto X : vec)
		if (X == val)
			++z;
	return z;
}
//_______________________________________________________
//16_64
template<> int counter(const vector<const char*> &vec,const char *val){
	int z = 0;
	for (auto X : vec)
		if (strcmp(X, val) == 0)
			++z;
	cout << "counter(const vector<const char*> &vec,const char* &val)" << endl;
	return z;
}
//______________________________________________________
//16_65
template<typename T>string debug_rep(T t) {
	ostrstream ret;
	ret << t;
	return ret.str();
}

template<>string debug_rep(char *t) {
	return debug_rep(string(t));
}

template<>string debug_rep(const char *t) {
	return debug_rep(string(t));
}
//________________________________________________________

//16_66
//模板特例化不影响函数匹配

//16_67
//不会，从本质上来说，特例化模板只是接替了编译器的工作，为模板的一个特殊实例作了定义
int main() {
	Sales_data a("ss", 2, 3.4);
	Sales_data b("xx", 1, 4.4);
	unordered_multiset<Sales_data> x;
	x.emplace(a);
	x.emplace(b);
	for (auto z : x)
		z.print();

	vector<int>aa = { 1,2,3,4 };
	vector<string>bb = { "ff","v" }; string tem = "v";
	vector<const char*>cc = { "dd","xxx","aa" };
	cout << endl << counter(aa, 1) << " " << counter(bb,tem) <<" "<<counter(cc,"w")<< endl;

	getchar();
}