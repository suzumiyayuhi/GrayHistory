#include<vector>
#include<string>
#include<iterator>
#include<iostream>
using namespace std;
bool part1(vector<int>::iterator ibegin,vector<int>::iterator iend,int target) {
	while (ibegin!=iend)
	{
		if (*ibegin==target)
		{
			return true;
		}
		else
		{
			++ibegin;
		}
	}
	return false;
}
vector<int>::iterator part2(vector<int>::iterator ibegin, vector<int>::iterator iend, int target) {
	while (ibegin!=iend)
	{
		if (*ibegin==target)
		{
			return ibegin;
		}
		else
		{
			++ibegin;
		}
	}
	return iend;
}

int main() {
	vector<int> aa{ 1,2,3,4,5,6,7,8,9 };
/*	if (part1(aa.begin(), aa.end(), 10))
	{
		cout << "xxxxxxxxxxxx";
	}*/
	cout << part2(aa.begin(), aa.end(), 1)-aa.begin();
	getchar();
	return 0;
}