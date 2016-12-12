//12_1
//b1��������Ԫ�أ�b2�Ѿ�������

#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;
//������12_2
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
//����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//12_3
//https://isocpp.org/wiki/faq/const-correctness#const-member-fn
//����ӣ�push_back,pop_back�������޸Ĳ�����������ݳ�Ա��ֵ�����ϳ���
//https://www.douban.com/group/topic/61573279/

//12_4
//�Կ�vector����Push_back,pop_back�������ᱨ��
//����size_t������Ϊ������0

//12_5
//ȱ�㣺��Ա������Ƶ�ʹ�ö������͸�����ȷ
//�ŵ㣺������ó�Ա����