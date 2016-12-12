//12_1
//b1包含三个元素，b2已经被销毁

#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;
//下面是12_2
struct StrBlob
{
public:
	StrBlob();
	StrBlob(initializer_list<string>);
	vector<string>::size_type size() const { return e->size(); }
	bool empty() const { return e->empty(); }
	void push_back(const string &a) { return e->push_back(a); }
	void pop_back(const string &a);
	string& front() const;
	string& back() const;
private:
	shared_ptr<vector<string>> e;
	void check(vector<string>::size_type, const string &str) const;
};
StrBlob::StrBlob():e(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> a):e(make_shared<vector<string>>(a)) {}
string& StrBlob::front() const {
	return e->front();
}
string& StrBlob::back() const {
	return e->back();
}
//———————————————————————————————————————————————————————————————————————————————————————————————
//12_3
//https://isocpp.org/wiki/faq/const-correctness#const-member-fn
//不添加，push_back,pop_back方法会修改操作对象的数据成员的值，不合常理。
//https://www.douban.com/group/topic/61573279/

//12_4
//对空vector进行Push_back,pop_back操作不会报错
//并且size_t类型总为正数或0

//12_5
//缺点：成员方法设计的使用对象类型更加明确
//优点：方便调用成员方法