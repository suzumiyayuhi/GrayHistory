#pragma once
#include<iostream>
#include<string>
#include<strstream>
struct LikePrintString {
public:
	LikePrintString(std::string s,std::istream &i = std::cin) :content(s), is(i) {}
	std::string operator()();
private:
	std::string content;
	std::istream& is;
};
//14_35
std::string LikePrintString::operator()() {
	if (std::getline(is, content))
		return content;
	else {
		return "";
	}
}