#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;
bool Equal_9_15(vector<int> a, vector<int> b) {
	if (a==b)
	{
		return true;
	}
	return false;
}
bool Equal_9_15(list<int>::iterator a, vector<int>::iterator b) {
	if (*a==*b)
	{
		return true;
	}
	return false;
}


int main() {
	list<int> a{ 1,2 };
	vector<int> b{ 2,4 };
	if (!Equal_9_15(a.begin(),b.begin()))
	{
		cout << "xxxxxxxxxxx";
	}
	getchar();
	return 0;
}