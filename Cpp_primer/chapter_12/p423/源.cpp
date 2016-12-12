#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<initializer_list>
#include<fstream>
using namespace std;
//12_19
struct StrBlobptr;
struct StrBlob
{
public:
	friend struct StrBlobptr;
	friend struct ConstStrBlobPtr;
	StrBlob();
	StrBlob(initializer_list<string>);
	vector<string>::size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &a) { return data->push_back(a); }
	void pop_back(const string &a);
	string& front() const;
	string& back() const;
	StrBlobptr begin();
	StrBlobptr end();
private:
	shared_ptr<vector<string>> data;
	void check(vector<string>::size_type, const string &str) const;
};
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> a) : data(make_shared<vector<string>>(a)) {}
string& StrBlob::front() const {
	return data->front();
}
string& StrBlob::back() const {
	return data->back();
}

struct StrBlobptr
{
public:
	StrBlobptr() :curr(0) {}
	StrBlobptr(StrBlob &a, size_t b = 0) :wptr(a.data), curr(b) {}

	bool operator!=(const StrBlobptr& p) { return p.curr != curr; }//githubÉÏµÄ·½·¨£¬ÖØÔØÁËÔËËã·û

	string& deref() const;
	StrBlobptr& incr();//Ç°×ºµÝÔö
private:
	shared_ptr<vector<string>> check(const size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> StrBlobptr::check(const size_t sz) const {
	auto temp = wptr.lock();
	if (!temp)
	{
		throw runtime_error("Unbound StrBlobstr");
	}
	if (temp->size() < sz)
	{
		throw out_of_range("out of range");
	}
	return temp;
}
string& StrBlobptr::deref() const {
	auto temp = check(curr);
	return (*temp)[curr];
}
StrBlobptr& StrBlobptr::incr() {
	auto temp =  check(curr);
	++curr;
	return *this;
}
StrBlobptr StrBlob::begin() {
	return StrBlobptr(*this, 0);
}
StrBlobptr StrBlob::end() {
	return StrBlobptr(*this, data->size());
}
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//12_20
void readout(const string& filename) {
	ifstream infstream(filename);
	string temp;
	StrBlob TempStrBlob;
	while (getline(infstream,temp))
	{
		TempStrBlob.push_back(temp);
	}
	StrBlobptr TempStrBlobptr(TempStrBlob, 0);

	for (StrBlobptr pbeg(TempStrBlob.begin()), pend(TempStrBlob.end()); pbeg != pend;//Õâ¸öµØ·½ÊÇgithubÉÏµÄ·½·¨
		pbeg.incr())
		std::cout << pbeg.deref() << std::endl;
}
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//12_21
//Ô­°æ±¾¸üÈÝÒ×Àí½â
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª


//12_22
struct ConstStrBlobPtr
{
public:
	ConstStrBlobPtr(const StrBlob &a) :wptr(a.data), curr(0) {}
	ConstStrBlobPtr() :curr(0) {}
	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }//githubÉÏµÄ·½·¨£¬ÖØÔØÁËÔËËã·û
	const string& deref() const;
	ConstStrBlobPtr& incr();//Ç°×ºµÝÔö
private:
	shared_ptr<vector<string>> check(size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t sz) const {
	auto temp = wptr.lock();
	if (!temp) {
		throw runtime_error("Unbound StrBlobstr");
	}
	if (curr>temp->size)
	{
		throw out_of_range("curr is out of range");
	}
	return temp;
}
const string& ConstStrBlobPtr::deref () const{
	auto temp = check(curr);
	return (*temp)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr() {
	++curr;
	return *this;
}
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
int main() {
	string filename("1.txt");
	readout(filename);
	getchar();
	return 0;
}