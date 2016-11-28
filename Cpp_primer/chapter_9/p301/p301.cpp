#include<vector>
#include<string>
#include<list>
#include<iostream>
using namespace std;
void create9_11() {

}


void create_9_13() {
	list<int> a(10, 8);
	vector<double> b(a.begin(), a.end());
	for (auto x : b) {
		cout << x;
	}
}

int main() {
	create_9_13();
	getchar();
	return 0;
}