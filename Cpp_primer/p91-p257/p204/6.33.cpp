#include"iostream"
#include"string"
#include"vector"
using namespace std;
void copy(vector<string> x,int a) {
	if (a!=0)
	{
		cout << x[x.size() - a]<<endl;
		--a;
		copy(x, a);
	}
}

int main2() {
	vector<string> a = { "sddd","xxx","vbgr" };
	auto b = a.size();
	copy(a,b);
	getchar();
	return 0;
}