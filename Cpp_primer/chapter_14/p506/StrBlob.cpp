#include"StrBlob.h"
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> a) : data(make_shared<vector<string>>(a)) {}
string& StrBlob::front() const {
	return data->front();
}
string& StrBlob::back() const {
	return data->back();
}