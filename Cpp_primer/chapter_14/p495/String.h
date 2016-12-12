#pragma once
#include<memory>
#include<iostream>
using namespace std;
//14_7
struct String
{
public:
	friend istream& operator << (ostream&, String&);
	String() :elements(nullptr), end(nullptr) {}
	String(char *cc);
private:
	allocator<char> alloc;
	pair<char*, char*> alloc_n_copy(const char* b, const char* e);
	char* elements;
	char* end;
};
pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto str = alloc.allocate(e - b);
	return{ str, uninitialized_copy(b, e, str) };
}
String::String(char *s) {
	char* sl = const_cast<char*>(s);
	while (*sl) ++sl;
	auto newstr = alloc_n_copy(s, ++sl);
	elements = newstr.first;
	end = newstr.second;
}
istream& operator >> (ostream& is, String& Str) {

}