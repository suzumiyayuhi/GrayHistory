#include<string>
#include<iostream>
using namespace std;

/*               用下标版本。
void X9_43(string &s, string oldVal, string newVal) { 
	int i = 0;
	int j = s.size();
	int k;
	string a;
	int newSize = newVal.size();
	int oldSize = oldVal.size();
	while (i<=j)
	{
		k = 0; 
		while (s[i] != ' ')
		{
			a.push_back(s[i]);
			++k;
			++i; 		
			if (i == j)
			{
				break;
			}
		}
		if (a==oldVal)
		{
			s.insert(i, newVal);
			s.erase(i - oldSize, oldSize);
			j = j + newSize;
			j = j - oldSize;
			++i; 
		}
		else
		{
			++i; 
		}
		a.clear();
	}
}*/
void X9_43(string &s,const string oldVal,const string newVal){   //这段代码写得很差劲= = 同学们不要向我学习。。。 完全体现出了一个弱智青年的水准。
	int oldSize = oldVal.size();
	int newSize = newVal.size();
	auto iter = s.begin();
	while (iter!=s.end())
	{
		int alphaNumber = 0;
		auto iter1 = oldVal.begin();
		auto iter2 = iter;
		while (*iter==*iter1)
		{
			++alphaNumber;
			if (alphaNumber == oldSize)
			{
				auto iter3 = newVal.begin();
				while (iter3 != newVal.end())
				{
					++iter;
					iter = s.insert(iter, *iter3);
					auto iter2 = iter;
					++iter3;
				}
				auto iter4 = iter - newSize;
				++iter4;
				iter = s.erase(iter4-oldSize, iter4);
				break;
			}
			++iter;
			++iter1; 
		}
		++iter;
	}
}
void X9_44(string &s, string oldVal, string newVal) {
	int i = 0;
	int j = s.size();
	int k;
	string a;
	int newSize = newVal.size();
	int oldSize = oldVal.size();
	while (i <= j)
	{
		k = 0;
		while (s[i] != ' ')
		{
			a.push_back(s[i]);
			++k;
			++i;
			if (i == j)
			{
				break;
			}
		}
		if (a == oldVal)
		{
//			s.insert(i, newVal);
//			s.erase(i - oldSize, oldSize);
			s.replace(i,i+oldSize, newVal);
			j = j + newSize;
			j = j - oldSize;
			++i;
		}
		else
		{
			++i;
		}
		a.clear();
	}
}
void X9_45(string &s, const string prefix, const string postfix) {
	auto begin = s.begin();
	auto iter = prefix.begin();
	while (iter!=prefix.end())
	{
		begin = s.insert(begin, *iter);
		++iter;
		++begin;
	}
	s.append(postfix);
}
void X9_46(string &s,const string prefix,const string postfix) {
	int size = s.size();
	s.insert(0, prefix);
	s.insert(size, postfix);
}
int main() {
	string a = "is world mine x";
	string oldone = "world";
	string newone = "baka";
	string prefix = "new";
	string postfix = "baka";
	X9_46(a, prefix, postfix);
	cout << a;
	getchar();
	return 0;
}