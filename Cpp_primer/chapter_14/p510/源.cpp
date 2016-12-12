#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	vector<int> vec = {1055,1023,555 };
	//14_42
	//(a)
	greater<int> greaterint;
	cout << count_if(vec.begin(), vec.end(), bind2nd(greaterint,1024));
	cout << endl << endl;
	//(b)
	vector<string> vecstr = { "poo","pooh","cv" };
	auto X = find_if(vecstr.begin(), vecstr.end(), bind2nd(equal_to<string>(), "pooh"));
	cout << *X;
	//(c)
	cout << endl << endl;
	transform(vec.begin(), vec.end(), vec.begin(), bind2nd(multiplies<int>(), 2));
	for (auto p : vec)
		cout << p << " " << endl << endl;
	//___________________________________________________________
	//14_43
	vector<int> tar = { 2,4,6 };
	int tem = 24;
	if (count_if(tar.begin(), tar.end(), bind2nd(modulus<int>(), tem)) == tar.size()) {
		cout << "tem can be divided";
	}
	//____________________________________________________________
	getchar();
}